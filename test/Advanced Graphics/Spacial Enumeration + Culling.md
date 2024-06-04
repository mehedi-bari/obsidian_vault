# Regular Spacial Enumeration
Spacial Enumeration/ Spacial partitioning are techniques that are used to **organise** spaces similar to data structures and algorithms. They address the idea of forming an efficient data structure for a particular problem.
Note: This is not the low-level data structure like matrix, which are usually handled by hardware: GPU.

For example, consider we have a list of animals. We can add animals in order, and when we need to present them, we can print out the array. Suppose, we want to print in a particular order, this becomes a difficult task: we would need to extract them, and then sort them out; if this is done regularly its a huge computational cost.
Solution: We can have a separate data structure with the index, and we won't have to change the order of the animals array. In addition, we can have a different order using length of word. So, this idea supports multiple sorts. The problem we concur is that if we delete an animal, we need to delete the word from both data structures or else it will point to null ptr. 

> There is always a trade-off which requires a trade-off between memory and speed.

![[Screenshot 2023-12-03 at 20.12.32.png]]

Typical Queries of a Graphical Scene:
$\square$  Does a given point intersect with an object in the scene?
$\square$  Ray casting: It can be used trace a part of a path, or a part of tree.
$\square$  Marching through volume


## Gridcell Structure
This is something that we have encountered before during 'Volume Rendering,' which is where we have a 3D array, and we would propagate through the cube. Similarly, we have a Gridcell which contains lots of small cubes. Each cube points to a pointer to an object. 
![[Screenshot 2023-12-03 at 20.30.41.png]]
This means that a find is $O(1)$, but our memory becomes $O(n^3)$. We get really fast finds for the cost of large large memory; also a lot of memory is **wasted**. There are other problems in terms of populating the Gridcell. For an object in 3D space,  you have to work out which of the gridcell’s cells the object touches, and make sure that each of them gets a pointer back to that object. The decision as to whether you only do this for cells that intersect with the surface of the object, or for all cells including those ‘inside’ the object will depend on the application.

Other considerations: What happens when we remove an object? If the object changed position/orientation? There are few ways to deal with this, but then it becomes computationally heavy.

$O(n^3)$ - space complexity, you could also make the grid sizes smaller, but increases the risk of false positives
$O(1)$ - time complexity 

## Octree Structure
To minimise the amount of wasted space, you can use and Octree structure. You have encountered this in 2D using Quadtrees. Let's consider an example in 2D.

For this, it is usually required to have a **threshold** for the maximum number of objects in a square. We take the whole image as a square, and then split it into further 4 quadtrees of the same size. If we break the maximum threshold we further recursively form more equal sized quadtrees until the requirement is met. In this structure, each child is either a **leaf node** or **it has 4 child nodes**. Every non-leaf nodes then points to its own children. 

![[Screenshot 2023-12-03 at 20.50.42.png]]

The nature of this algorithm is that it divides more spaces where there are more objects together, and less so near sparse areas. 

> The saving in memory comes at a cost of time complexity.  Since you need to find out which nodes in the tree structure it is, and how far along the hierarchy tree you need to go till you get your list of objects. The only guarantee  you get is the max number of object in each leaf quad-tree, and the size of a quad-tree at a specific level is the same.

Remember: if you shift up to 3D you get octree. Instead of squares you get cubes. Instead of 4 child nodes, you get 8.

$O(logn)$ - time complexity
$O(logn)$ - space complexity
#  Irregular Spatial Enumeration
There are lots of unused spaces, and sometimes these spaces isn't really convenient to use something likes cubes. There are usually things that very close, which forms a collection; also between the collections there are huge empty space. This idea is known as **spacial cohesion.**

The Octree is good at dividing spaces. It takes advantages of this being clumped together, and then dividing things even more. But also because of spacial cohesion it means things aren't usually clumped as cubes.
## Hierarchical Bounding Volumes(HPV)
HVPs start with objects and wrap those around increasingly bigger spaces until you've covered the whole scene. The idea is that it builds a hierarchical structure from the bottom up. 

It usually wraps an object in a **bounding volume.** The idea is to encapsulate a simple shape in a more complex one. Suppose you do an intersection test. and  you get a negative result. It means that you've not got a collision with the object. So, test with the polygon or complex shape is not required. Computing checks for bounding volume are **simpler**, and **quicker** than the complex polygon shapes. 

If the test results is positive, there is still a chance of it being **false positive**. So, there needs to be checks with the polygon to see if there is contact. The idea is that we expect to fire lots of rays, and there are more rays missing that hitting the sphere (which is a cheap test!)
![[Screenshot 2023-12-03 at 21.40.48.png]]
Mathematically, a sphere is the simplest shape, not it terms of drawing using polygons but it terms of representing in a mathematical equation.  

> Look at notes on intersection of a ray and a sphere as well as a ray and a polygon. You will see how the sphere is better in terms of performance. 

>The problem is that the cow doesn't have a tight fit around the bounding volume. This means if you have a tighter bound, you will have less false positive; this usually increases the computational costs for finding hits of the bounding volume. 

![[Screenshot 2023-12-03 at 21.45.07.png]]
You could try a cube, but it doesn't result in a better fit. In terms of compromise, the best result is to use a cuboid! 

The obvious next step is to allow bounding volumes to contain other bounding volumes; again exploiting the spatial coherence of most scenes:
1 ) enclose complex polygonal objects in bounding shapes (let’s say cuboids)
2) enclose any bounding shapes that end up being near one another in a bigger bounding shape
3) repeat the process until you have a suitable hierarchy of objects.

> Align everything to world axis, don't use an object aligned bounding volumes, as this increases the complexity of calculating rays intersecting with it.

![[Screenshot 2023-12-03 at 21.55.11.png]]
$O(logn)$ - time complexity
$O(logn)$ - space complexity



![[Screenshot 2023-12-04 at 13.39.44.png]]
Axis aligned bounding boxes are very to compute for a CPU/GPU which requires simple subtractions. You would require the use of trigonometry for non-axis aligned bounding boxes.
Non-axis aligned forms a tighter fit which results in fewer false positives.

## Binary Space Partition(BSP)
There are two main variants, one of which is easy to understand but not hugely efficient, and another which is a bit more tricky to make sense of on first contact, but which has better performance in most cases. We’ll look at the former first, as a way of leading up to the latter.

**Axis Aligned Binary Space Partitioning** attempts to split the world recursively into two sections, where the boundary is drawn such that it aligns with one of the world axes. 

![[Screenshot 2023-12-03 at 22.35.31.png]]

![[Screenshot 2023-12-03 at 22.35.38.png]]

A relatively minor tweak that makes BSP more efficient is to allow the partitioning to take place along arbitrary axes, rather than being constrained to world axes, and in **Polygon Aligned Binary Space Partitioning**, the planes are frequently (but not always) chosen to coincide with the planes defined by polygons in the scene.
$O(logn)$ - time complexity
$O(logn)$ - space complexity


# Culling 
For most graphical scenes it is likely that there’s much more detail or content in the under- lying model than is visible in any one rendered view; this is particularly true for interactive applications with dynamic content where objects and the viewpoint vary. There’s an obvious **performance advantage** to be had if you can work out which bits of the scene aren’t going to contribute to the rendered view

### Detail Culling:
The idea here is to not bother drawing things that are simply too small to have a perceivable effect on the final scene. This approach is particularly effective for moving scenes, since the viewer is unlikely to notice tiny bits of lost detail.

### Backface Culling: 
Most objects cannot be seen simultaneously due to their orientation. Some parts are visible and others are hidden. This is especially true for opaque convex objects, while open or concave objects can be seen. To save time, it's possible to render polygons facing away from the viewer. 

There are two important consideration to be made: it has to be a cheap calculation, and it has to be something we can do early on in the rendering pipeline. 

>A simple test on polygons in object-space involves calculating the dot product of the view vector and the polygon's surface normal. If negative, the polygon faces away from the viewer, while positive indicates it faces towards us. This requires trigonometry, but modern hardware often provides this calculation as a GPU instruction.

### Frustum Culling:
The viewing frustum represents the volume visible to the virtual camera, and objects outside this volume are discarded. Objects on the viewing frustum are cut into pieces called **clipping**, while t hose outside the frustum are discarded. Spatial enumeration techniques help quickly determine which objects are candidates for culling.
https://learnopengl.com/Guest-Articles/2021/Scene/Frustum-Culling
### Occlusion Culling: 
Z-Buffer techniques address the issue of objects near the viewplane being drawn over those further away, but they rely on all objects being drawn late in the rendering pipeline, which doesn't improve performance. Ideally, objects behind opaque objects should be excluded from the list of things to be drawn early on, but this is not trivial.
![[Screenshot 2023-12-03 at 23.00.42.png]]
Another approach to solving this problem is to exploit specific features of the scene being rendered. For example, indoor scenes often consist of enclosed spaces with portals, such as doors and windows, through which other enclosed spaces are potentially visible. The 'portal culling' approach works by identifying any portals that are partly or wholly visible in the current view frustum, casting rays against the perimeter of the portal into other rooms, identifying portals that are visible in the view frustum for each room that a ray enters, and repeating the ray casting process.

1. From the current viewpoint, identify any portals that are partly or wholly visible in the current view frustum.
2. For each portal, cast a rays against the perimeter of the portal into other rooms.
3. For each room that a ray enters, identify portals that are visible in the view frustum, and repeat the ray casting process
4.  Each room that a ray passes through has contents that are potentially visible from the original viewpoint; create a new viewing ‘frustum’ (the portal need not be square, so it’s not always technically a frustum) from the eyepoint that takes into account the frame of the portal, and repeat the process from Step 1 until all visible portals have been included.