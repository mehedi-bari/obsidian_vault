When performing simulations of any kind, we need to know if two objects have intersected, and if so how they should respond. These problems are **collision detection** and **collision response**, respectively.
![[Screenshot 2023-10-22 at 21.49.26.png]]

## Collision Detection
There are many different algorithms for detecting a collision between two objects, and the main factor that informs your choice is the geometry of the colliding object. For example, here is a collision between two rigid bodies, where the orange rectangle is an implicit surface (i.e. mathematically defined):
![[Screenshot 2023-10-22 at 21.50.43.png]]
We know that when the function representing this surface equals zero that a coordinate is on the surface, and when the function is less than zero a coordinate is inside the surface. Therefore, it is trivial to know if a collision has occurred.

This is not so simple with all definitions of a surface, specifically with meshes. There is no guarantee that a mesh is even closed, so how could you know if you are "inside" it?
## Collision Response
Collision response deals with models for simulating the changes in the motion of the bodies after collision; that is, how the objects involve move as a result of colliding.
Usually when we detect a collision we are already "too late" - in the last simulation step the colliding object was outside the collider, and in this step it is inside it.
![[Screenshot 2023-10-22 at 21.53.24.png]]
One solution is to retroactively adjust our colliding object's position such that it is in the place where it should be. This is called **backtracking**:
![[Screenshot 2023-10-22 at 21.53.54.png]]
We can do this by computing the intersection point between the colliding object's movement path and the collider, which gives us the exact point of collision.
With this point of collision, we can calculate the new direction, speed, etc. of the colliding object and advance it in that direction for the fractional time steps that we undid.
Alternatively, we can do a quick and **dirty hack** called "Fixing", where we simply take the final position of the colliding object and roughly adjust it to be on the surface of the collider:
![[Screenshot 2023-10-22 at 21.54.41.png]]
We then apply the response from this point. This is inaccurate, but it may be simpler to compute in some situations.

## Complexity
The complexity of (naïve) collision detection is high; for $n$ dynamic objects, we must compare each object to every other and check for collisions, meaning collision detection runs in $O(n^2)$ time.
There are ways to improve the running time of collision detection, such as:
- Use **simple, conservative proxies** to reduce the impact of non-colliding checks.
- And use **recursive/hierarchical tests** to make these proxies more "precise", weeding out even more non-colliding checks
- Only compare objects that are both in the same close part of the scene, **neighbouring lookup**.

### Bounding Volumes
A common approach to improving the efficiency of collision detection is to collide with the bounding volumes of an object before the actual object's geometry.
![[Screenshot 2023-10-22 at 22.18.51.png]]
Bounding volumes are generally very simple and easy to calculate intersections for. If the bounding volumes of two objects intersect, then they may or may not have actually intersected and a second check with the actual meshes is required. These robots can intersect only if their bounding boxes are colliding so it’s faster to check if the simpler objects are colliding instead.
There are various types of bounding boxes:
![[Screenshot 2023-10-22 at 22.19.38.png]]
(AABB = Axis Aligned Bounding Box, OBB = Oriented Bounding Box, k-DOP = k-Discrete Oriented Polytopes)

We will cover sphere bounding boxes.
![[Screenshot 2023-10-22 at 22.21.04.png]]
A bounding sphere is a sphere that is placed around an object such that the entire object fits exactly in the sphere. If the bounding spheres of two objects do not intersect, then the objects definitely don't intersect and we can skip the check. Vitally, checking if spheres are intersecting is very easy.
We can extend this to a hierarchical model, by performing a series of increasingly precise bounding sphere checks:
![[Screenshot 2023-10-22 at 22.21.51.png]]
So first we check the bounding sphere, then we increase the number and decrease the size of the bounding spheres repeatedly in a series of more precise (but more time consuming) collision checks.
###### What's the strategy?
We do a **recursive test** with **early pruning**. For example, if a bounding sphere for a cluster intersects with the bounding sphere of another cluster, you recursively check the bounding spheres within those clusters. 
**Early Pruning:** During the recursive tests, you use early pruning techniques to quickly reject pairs of bounding volumes that can't possibly collide
**Mesh-to-Mesh Collision Tests:** After all the recursive tests and early pruning checks, you eventually reach the leaf nodes of the hierarchy, where you have the smallest, most precise bounding volumes. At this point, you perform the actual mesh-to-mesh collision tests for the objects within these leaf nodes.