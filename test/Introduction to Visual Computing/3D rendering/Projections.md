#### Recap: the camera analogy
If you want to take an image of something with a real life camera, you take these steps:
1. Arrange the subjects of the photo to create the desired composition
2. Position the camera to point at the scene
3. Choose a camera lens based on the angle, zoom, etc...
4. Decide on the final size of the photo
These steps are roughly analogous to 3D viewing:
1. Set the Modelling Transformation
2. Set the Viewing Transformation
3. Set the Projection Transformation
4. Set the Viewport Transformation
This page defines the Projection Transformation.

## Planar geometric projections
How do we map 3D world coordinates to 2D coordinates on a screen? 
There are many ways to do this, each with different properties.

![[Screenshot 2023-09-18 at 11.00.31.png]]
## Parallel Projections - Orthographic
In a parallel projection, the lines between 3D points and their 2D projection are parallel. ![[Screenshot 2023-09-18 at 11.01.08.png]]

This is an **orthographic** projection. It gives an undistorted view of some side of an object, which makes it useful for seeing the real proportions of an object. However, anything behind the frontmost faces will be completely obscured. 

The parallel projection are usually parallel to 2 of the world axis. This makes it very useful to get front, side, and top views - good for engineers! However, you lose alot fo information.
![[Screenshot 2023-09-18 at 11.08.30.png]]
#### Making an orthogonal projection
Making an orthogonal projection matrix is extremely simple. Consider the case where the projector is parallel to the z-axis (i.e. the 'camera' is 'looking down' the z-axis). All you have to do is remove the z depth from each point, giving this matrix:
![[Screenshot 2023-09-18 at 11.13.16.png]]
You may notice that this matrix (and in fact all projection matrices) are **singular**; that is, they have no inverse. 

#### Making an axonometric projection
There are multiple types of axonometric projection to choose from:
- **Isometric**: The plane that is being projected onto is symmetrical to all three axes (i.e. the projector is at a $45\degree$ angle to all of the axes.)
- **Dimetric**: The plane that is being projected onto is symmetrical to two of the axes (i.e. the project is at a $45\degree$ angle with 2 of the axes.)
- **Trimetric**: The plane that is being projected onto is placed in any location.
![[Screenshot 2023-09-18 at 11.15.14.png]]

#### Making an oblique projection
![[Screenshot 2023-09-18 at 11.16.28.png]]
(making matrices for axonometric or oblique projections isnt examined.)

## Perspective projection
In a perspective projection, the lines between 3D points and their 2D projections are **not** parallel. Instead of a projector line, there is a centre of projection (or an "eye point"); the lines between 3D points and their 2D projections must meet at this eye point, which is behind the projection plane. In this kind of projection, distant objects appear to converge toward a vanishing point, and lines of an object that are truly parallel may not appear to be.

There are three kinds of perspective projection:
- **1-point perspective**: The projection plane is parallel to two of the axes (i.e. the 'camera' is looking 'straight at' the scene). This projection will have 1 vanishing point.
- **2-point perspective**: The projection plane is parallel to one of the axes. This projection will have 2 vanishing points.
- **3-point perspective**: The projection plane is parallel to none of the axes. This projection will have 3 vanishing points.
![[Screenshot 2023-09-18 at 13.20.40.png]]

#### Making a 1-point perspective projection
You have a set of axes, an eye point (centre of projection), and a projection plane. To project a point onto the projection plane, you need to trace a line from the eye point to the point and find the point $(x_p, y_p, z_p)$ where this line intersects with the projection plane. But how do you accomplish this?
![[Screenshot 2023-09-18 at 13.21.48.png]]
Consider this scene when facing down each of the axis. If looking down the Y axis at the XZ plane, you see this:
![[Screenshot 2023-09-18 at 13.22.58.png]]
You can observe that the distance from the origin of $x$ and $x_p$ will have the same ratio as the distance from the origin of $z$ and $z_p/d$. Therefore, this is true:
$$\frac{x_p}{x} = \frac{d}{z}$$
$$x_p = \frac{dx}{z}$$
$$x_p = \frac{x}{z / d}$$
Do this again with the YZ axis to get this result:
![[Screenshot 2023-09-18 at 13.25.01.png]]
$$y_p = \frac{y}{z/d}$$
So now we know that the transformation should do this:
$$
\begin{bmatrix}
x \\ y \\ z \\ 1
\end{bmatrix}
\Rightarrow
\begin{bmatrix}
\frac{x}{z/d} \\
\frac{y}{z/d} \\
d \\
1
\end{bmatrix}
$$

We can apply a trick here to simplify the transformation matrix:
$$
\begin{bmatrix}
\frac{x}{z/d} \\
\frac{y}{z/d} \\
d \\
1
\end{bmatrix}
=
\begin{bmatrix}
\frac{x}{z/d} \\
\frac{y}{z/d} \\
\frac{z}{z/d} \\
1
\end{bmatrix}
=
\begin{bmatrix}
x \\
y \\
z \\
z/d
\end{bmatrix}
$$
The last step is possible because of normalisation; the resulting coordinate will be divided by $z/d$ in order to make $w$ equal $1$. Using this observation, we can achieve this simple transformation matrix:
$$
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 1 & 0 \\
0 & 0 & 1/d & 0 \\
\end{bmatrix}
$$
### Summary
To perform a 1-point perspective projection we can use this matrix:
$$
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 1 & 0 \\
0 & 0 & 1/d_z & 0 \\
\end{bmatrix}
$$
(note that $d$ has been renamed $d_z$ to make it clear that it's a z coordinate)
You can perform a 3-point perspective projection using this matrix (which you don't need to derive):
$$
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 1 & 0 \\
1/d_x & 1/d_y & 1/d_z & 0 \\
\end{bmatrix}
$$
Where $(d_x, d_y, d_z)$ is the point where the projection plane intersects with the XYZ axis.

## Viewing volumes
In order to describe the field of view of the 'camera', the viewing angle of the rendered image must be limited. We can do this by defining a **3D view volume**.
Only parts of 3D objects which lie inside the view volume are displayed - objects outside are **clipped**.
The shape of the view volume depends on the kind of projection.
Parallel projection view volume:
![[Screenshot 2023-09-18 at 13.35.01.png]]
This rectangular view volume is defined by a near plane and a far plane, which are parallel to the projection plane.
Perspective projection view volume:
![[Screenshot 2023-09-18 at 13.38.22.png]]
This view volume is in the shape of a frustum - imagine an infinite pyramid with its peak at the eye point, then cut off the top and bottom leaving a frustum behind. The near and far planes are parallel to the projection plane.

#### Orthographic projection in three.js
![[Screenshot 2023-09-18 at 13.47.20.png]]
#### Perspective projection in three.js
![[Screenshot 2023-09-18 at 13.48.13.png]]
## Projection normalisation
When we perform projection, we completely destroy the depth information from the scene. For example, consider the result a 1-point perspective projection:
$$
\begin{bmatrix}
\frac{x}{z/d} \\
\frac{y}{z/d} \\
d \\
1
\end{bmatrix}
$$
The depth of any point is a shared constant. This is a problem; we want to keep the depth information so that we can perform hidden surface removal. We can solve this problem using **projection normalisation**.
Suppose we have some perspective transformation expressed in terms of a frustrum $F$ and a matrix $M$.
It can be shown that we can derive a new transformation matrix $PN$, based on $M$, that distorts $F$ into a cube.
We transform our model by $PN$ and then take an orthographic projection.
This produces exactly the same result as performing the original transformation $M$, but with depth values preserved.
![[Screenshot 2023-09-18 at 13.57.52.png]]

## Clipping
Clipping is the process of removing geometry that falls outside of the viewing area.
![[Screenshot 2023-09-18 at 13.59.34.png]]


