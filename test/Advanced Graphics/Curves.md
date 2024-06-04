**Explicit Modelling** - Where geometry is represented by a set of concrete points, which are assembled in some way. Examples include point clouds, polygon meshes (this is the kind covered last year), and NURBS surfaces.
![[Screenshot 2023-09-23 at 22.16.22.png]]

**Implicit Modelling** - Where geometry is not represented by a set of concrete points. Examples include level sets and algebraic surfaces.

![[Screenshot 2023-09-23 at 22.16.47.png]]

# Smooth Geometry
In many cases, we want properties of our geometry or animation to be smooth. For example, we want our 2D vector art to have smooth edges, we want our 3D geometry to have smooth surfaces, we want our 3D models to smoothly animate, etc.
## Polylines
![[Screenshot 2023-09-23 at 22.19.11.png]]

Simply a set of points connected by lines. While simple, they completely lack smoothness.
They are still of great importance, as they are essentially what a GPU takes as input for rendering; while other kinds of lines may be used, when it comes to rendering polylines must be used.

## Splines
![[Screenshot 2023-09-23 at 22.21.44.png]]
Spline is a general term for any kind of curve that smoothly connects a set of lines. The points that are used to construct a spline are called **control points**.
There are two distinct categories of splines:
**Interpolation** - Given a set of points, produce a smooth curve that *exactly* passes through every point. (Good when we want to preserve all the data points.)
![[Screenshot 2023-09-23 at 22.22.21.png]]
**Approximation** - Given a set of points, produce a smooth curve that follows a similar trajectory to the points, but is not required to pass through every point. It is more flexible, and it used to simplify complex graphs, by going through important control points.
![[Screenshot 2023-09-23 at 22.22.45.png]]

### Cubic Bezier
![[Screenshot 2023-09-23 at 22.31.15.png]]
Cubic Bezier is an approximating curve. The first and last control points will be touched exactly by the curve, while the other two control points define the way the curve bends on its way between the points. 
This curve has some interesting properties:
- The control points form a *convex hull* which the curve will never fall outside of.
- The curve is tangential to the convex hull going out of $P_1$ and going into $P_4$.
These are both useful properties for many reasons.

The Cubic Bezier can be defined by this function:
![[Screenshot 2023-09-23 at 22.35.01.png]]
where $P_1$, $P_2$, $P_3$ and $P_4$ are coefficients representing the control points and $t$ is the progress along the curve (in the interval 0 to 1).
The terms in this function are basis functions called **Bernstein Polynomials**:
![[Screenshot 2023-09-23 at 22.34.32.png]]

Alternatively, you can define it using matrices:
![[Screenshot 2023-09-23 at 22.36.34.png]]
![[Screenshot 2023-09-23 at 22.37.31.png]]

In this function, G/Geometry is a matrix representing the position of the control points, and B/Spline Basis and T/Power Basis together represent the Bernstein Polynomials seen in the previous representation.

But why use these Bernstein Polynomials? Because of these properties:
- **Non-negativity** - These polynomials output only positive values, all the values are between 0 and 1.
- **Partition of unity** - The sum of all of the Bernstein Polynomials at any given value of $t$ will add up to 1.
These two properties are why the Bezier curve remains inside the convex hull.

### Bernstein Polynomials can easily be calculated using polynomials:
We can use the matrix $B$ to transform them the t basis to the $B_?(t)$, and also switch back.  This is known as change of basis.
![[Screenshot 2023-09-23 at 22.45.33.png]]
![[Screenshot 2023-09-23 at 22.47.25.png]]




What about the other Bezier curves?
A degree 1 Bezier curve is a straight line, and only takes two control points:
![[Screenshot 2023-09-23 at 22.51.46.png]]
A degree 2 Bezier curve ("Quadratic Bezier curve") takes three control points:
![[Screenshot 2023-09-23 at 22.52.05.png]]
A degree 3 Bezier curve takes four control points:

![[Screenshot 2023-09-23 at 22.53.41.png]]

A degree 4 Bezier curve takes 5 control points:
![[Screenshot 2023-09-23 at 22.54.22.png]]
And so on. To find the Bernstein polynomials for these other degrees, use this formula:
![[Screenshot 2023-09-23 at 22.54.34.png]]

Where $n$ is the number of control points (or $n - 1$ is the degree of the curve) and $i$ is which of the polynomials you want. 

#### Subdivision
Subdivision is the process of splitting a curve into multiple smaller curves, where the combination of the smaller curves is identical to the original curve.
![[Screenshot 2023-09-23 at 22.56.09.png]]
A method for subdividing a Bezier curve is **De Casteljau Construction**.
First, take the points halfway between the control points. Connect these dots with new lines, then take the points halfway along these new lines. Repeat this until we only get one point (the number of repetitions depends on the degree of the curve). This point lies exactly halfway along the curve.
![[Screenshot 2023-09-23 at 22.58.45.png]]
The two smaller Bezier Curves are here:
![[Screenshot 2023-09-23 at 22.59.48.png]]

You take the first of each group of points for the first curve, and the last of each group of points for the second curve.

#### Differential Properties
![[Screenshot 2023-09-23 at 23.01.19.png]]
There are many properties of curves that you may want to know, for various reasons. These include:
- normal
- velocity
- acceleration:
##### Velocity
We can find the velocity of the curve at a given point by finding the tangent of the curve.
Recall this function for a Bezier curve:
![[Screenshot 2023-09-23 at 23.01.56.png]]
We can find the tangent of the curve at a given point by differentiating:
![[Screenshot 2023-09-23 at 23.02.08.png]]
(We also normalise the vector.)
This is the velocity of the curve.
##### Curvature/acceleration
We can find the direction that the curve is turning (aka the curvature, or acceleration) by finding the normal of the curve.
As you might expect, you can get the acceleration by taking the second derivative of P, or the first derivative of T:
![[Screenshot 2023-09-23 at 23.06.06.png]]
(Normalising again.)

#### Orders of Continuity
There are many ways in which two Bezier curves can be connected.
**C0** - They are connected in any way. Sharp corners may be present, at the seem.
![[Screenshot 2023-09-23 at 23.06.51.png]]
**G1** - They are connected, and the tangents at the meeting point are in the same direction. The connection is quite smooth.
![[Screenshot 2023-09-23 at 23.07.19.png]]
**C1** - They are connected, and the tangents at the meeting point are the exact same. The connection is completely smooth, and appears continuous.
![[Screenshot 2023-09-23 at 23.07.52.png]]

### Cubic B-Spline Curves
![[Screenshot 2023-09-23 at 23.16.17.png]]
Cubic B-Spline Curves are another approximating curve. They are locally cubic (like a Bezier curve), but instead of having a fixed number of points, they have a *minimum* of 4 points; Adding more points creates more turns in the curve, while keeping a smooth appearance with no visible discontinuity. For example:
![[Screenshot 2023-09-23 at 23.16.53.png]]
As you can see, B-Spline curves do not need to pass through *any* of the control points.

B-Spline curves, like Bezier curves, are contained entirely within the convex hull formed by the control points.
Also like a Cubic Bezier curve, they are composed of 4 Bernstein basis functions:

The same properties apply as with a Cubic Bezier curve, but observe that while the sum of the basis functions does add up to 1 when $t = 0$ and $t= 1$, no single basis function equals 1. This is why the curve never touches the control points.

![[Screenshot 2023-09-23 at 23.21.15.png]]
![[Screenshot 2023-09-23 at 23.22.09.png]]
### Converting between curves
![[Screenshot 2023-09-23 at 23.28.13.png]]
These two matrices are the spline basis matrices for Bezier and B-spline, respectively. Because both of these produce a cubic curve, we can make an identical curve using either of these; the control points will just be different.
For example, say we have a Bezier curve. Let $B_1$ be the spline basis matrix for Bezier, and $B_2$ be the spline basis matrix for B-spline.
Our Bezier curve can be represented in matrix form:
![[Screenshot 2023-09-23 at 23.28.52.png]]
A B-spline curve would be represented in the same form, but with the B-spline spline basis matrix. So, we introduce that matrix
:![[Screenshot 2023-09-23 at 23.29.28.png]]
Multiply the first three elements:
![[Screenshot 2023-09-23 at 23.29.55.png]]
Because we multiplied by a matrix and its inverse, we didn't change the result of the function. Therefore, we have the same curve but expressed as a B-Spline curve.
Here is a concrete example of this:
![[Screenshot 2023-09-23 at 23.30.30.png]]

### NURBS (Non-Uniform Rational Basis Spline)
![[Screenshot 2023-09-23 at 23.31.46.png]]
NURBS is different in that the control points (called knots in a NURBS curve) each have a weight. This weight determines how closely the curve must adhere to each point.
NURBS curves are known for being very flexible and very smooth. You are able to get a very specific shape without sacrificing smoothness.