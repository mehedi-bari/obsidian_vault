Unlike curves, there are 4 kinds of surface:
![[Screenshot 2023-09-29 at 20.43.00.png]]
# Explicit Surfaces
Surfaces defined in terms of a collection of concrete units, such as points in a point cloud or vertices in a mesh. Meshes are the more common type.
## Mesh/Point Representation:
There are two different types of mesh, using triangles or polygons. Each triangle/polygon has a number of vertices. Each triangle/polygon is called a **face**, and each point is called a **vertex**. A collection of faces is called a **surface**. This is the most common representation. 
![[Screenshot 2023-09-29 at 20.57.13.png]]

# Tensor Product Splines
Analogous to splines when talking about curves. A tensor product spline is a surface defined in terms of a curve function, which produces a smooth surface.
We know how to define Bezier curves - how might we extend this from a line to a solid surface?
Consider how a Bezier curve is constructed, by interpolating smoothly between the control points according to $t$. Now imagine the control points themselves moving along Bezier curves, according to another variable called $v$.

The formula for the Normal Bezier curves, and now the adjusted version which also uses the Bernstein numbers, but using a $v$ to adjust where it is:
![[Screenshot 2023-09-29 at 21.18.46.png]]

For each value of $v$ you would have a single Bezier curve, similarly to how you have a single point for each value of $t$ in a regular Bezier curve. If you do this continuously for every single value of $v$, the individual Bezier curves will assemble into a smooth surface.
![[Screenshot 2023-09-29 at 21.16.35.png]]
This surface, made of cubic Bezier curves, requires 16 control points.

Formerly $P1$, $P2$, etc. represented the location of each control point and were constant values. Now, the control points move according to the value of $v$, so they have become functions on $v$.
This surface (specifically with a degree of 3) is called a **Bicubic Bezier surface(type 2)**
The **red** points are approximated, and the **black** control points are the end control points . 
![[Screenshot 2023-09-29 at 21.23.10.png]]
The control points are being reused constantly, so it saves memory. 

## Parametric Surfaces
A more general type of surface, which includes Tensor Product Splines. Any kind of curve that is defined in terms of parameters fits into this category.
![[Screenshot 2023-09-29 at 21.28.55.png]]
From now on, parametric surfaces will be used as an interchangeable way to refer to tensor product splines such as the Bicubic Bezier Surface.
A point on a parametric surface is defined by the function $P(u,v)$. This was seen previously in the bicubic Bezier surface example.
Like a curve, you can extract some useful differential properties from this function.
### Differential Properties
![[Screenshot 2023-09-29 at 21.35.27.png]]
Because there are now two parameters, we find partial differentials instead.
We can find the velocity/tangent at point P along $u$ (called T on the diagram) by finding the derivative with respect to $u$.
We can find the velocity/tangent at point P along $v$ (called B, or "bi-normal" on the diagram) by finding the derivative with respect to $v$.
We can find the normal at point P by finding the second derivative.

### Matrix Representation
A parametric curve can also be represented as a matrix. Here is a general form of a parametric curve:
![[Screenshot 2023-09-29 at 21.41.04.png]]

This can be given in matrix form like this, much like a curve:
![[Screenshot 2023-09-29 at 21.42.36.png]]
For comparison:
![[Screenshot 2023-09-29 at 21.43.29.png]]
Pros: The surface is very **smooth**, and they're defined by a small number of control points. The meshes produced previously requires a lot of memory:
Cons: They need to converted into triangles to form a **triangular mesh**, so this becomes a bottleneck when rendering images. They're also tricky to ensure continuity around boundaries especially between two patches, and figuring out if it is C0,C1,C2 etc. 
## Displacement Maps
Sometimes you don't want a perfectly smooth surface - after all, most natural surfaces are rough. We can do this using a displacement map:
![[Screenshot 2023-10-01 at 20.14.41.png]]
A displacement map is a texture/function/something that you apply to a surface. The brightness of the map at a given point shows how far the surface should displace in the direction of the normal. Pure black will remain at the actual surface location, while pure white will stick out massively in the normal direction from the surface. Grey will stick out less.
Note that this is done to an explicit mesh; therefore it will usually be necessary to tessellate the surface before applying the displacement to get fine detail.

## Subdivision Surfaces
Unlike subdividing a curve, subdividing a surface begins with an explicit polygon mesh. Subdividing a surface involves splitting the polygons of the surface apart; there are many methods of doing this, but generally they make the mesh smoother.
One method is "corner-cutting". Start with this mesh:
![[Screenshot 2023-10-01 at 20.21.48.png]]

We cut the sharp edges, giving us more edges:
![[Screenshot 2023-10-01 at 20.22.09.png]]
Eventually we approach the "limit", that is the blue lines, which is perfectly smooth:
![[Screenshot 2023-10-01 at 20.23.00.png]]
Note: we only store the control points.

With this method, also called **Chaikin's Algorithm**, the resulting mesh (or the limit that it approaches) is actually a **quadratic B-Spline curve**. The original mesh's vertices become the control points to the curve.
In 3D:
![[Screenshot 2023-10-01 at 21.12.50.png]]
Here is what happens when you do it on a cube:
![[Screenshot 2023-10-01 at 21.28.02.png]]
(That is a perfect sphere, not just a vaguely sphere-like shape.)
In fact, you can get any shape out of a cube.
# Implicit Surfaces(Type3)
An implicit surface is a mesh defined by an equation. For example:
![[Screenshot 2023-10-01 at 21.29.29.png]]
Implicit surfaces are very efficient, as you can make a perfectly smooth shape with no need for a large amount of polygons. They are also very efficient for boolean operations such as intersection, as there is only a single equation to handle. It can also handle weird topology, like having holes inside a shape.

However, the obvious limitation is that you can only create shapes which you can express as an equation. If you want to create the shape shown above but with a bump on the surface, you cannot.

Notably, you can do very easy bounds checks:
![[Screenshot 2023-10-01 at 21.38.50.png]]

# Procedural Surfaces(Type 4):
A **surface of revolution** defines a 3d surface by first defining a 2d shape, and then rotating it around some axis to create a 3d surface. For example:
![[Screenshot 2023-10-01 at 21.40.50.png]]
A surface of revolution can be represented as this formula:
$$s(u,v)=\mathbf{R}(v)\mathbf{q}(u)$$
Where $s(u,v)$ is the function defining the surface, $R(v)$ is the rotation matrix where it only travels in $v$ directions and $q(u)$ is the vector being rotated .

Another kind of procedural surface is the **Generalised cylinder** (aka **General Swept Surface**), which takes a 2D profile and a 3D curve and produces the shape of the 2D profile sweeping across  the 3d curve. For example:
![[Screenshot 2023-10-01 at 21.46.12.png]]
We essentially trace out a surface by moving a profile curve in a trajectory.  $q(u)$ is the profile curve and it moves along the trajectory $c(v)$ and the $M$ is the movement/rotation.

Note: A surface of revolution is actually a special case of a generalised cylinder, where the trajectory is a circle. 


# Differential Parameters of Surfaces
## Frenet Frame
The Frenet Frame of a surface is a right-hand system formed by the first, second and third derivatives of a surface.
![[Screenshot 2023-10-01 at 22.03.22.png]]

T (tangent/velocity) is the first derivative.
N (normal) is the second derivative.
B (binormal) is the third derivative, and is equal to the cross product of the other two.

The tangent is usable, but there is a problem with the normal: At points of inflection (when the curvature changes sign) the normal becomes zero and then flips sides.
![[Screenshot 2023-10-01 at 22.03.49.png]]

The last type is the point set, which is type 1!