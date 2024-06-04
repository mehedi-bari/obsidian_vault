Why curves?
- Curves are needed to approximate shapes, and make things visually accurate. and appealing. 
- It can be used to model **realistic objects** e.g. describing the movements and trajectory of an object, character motions.

Why are there more than one type of curve?
- Different curves have **different applications**.
- Some offer more **accuracy** over the thing you want to model
- Some are more **scalable** and doesn't require a high degree polynomials.

What are the pros and cons of Bezier vs B-Spline curves?
- Bezier: It is simple to implement. They are not robust ot changes,, changing one control point affects the entire curve. For a large number of control points, the polynomial will be of a high order.
- B-Spline: It can be changed **locally** as changing one point changes only a part of the segment. It is essentially a chain of curves with the same function but different coefficients glued together. Because it is segmented, only neighbouring knots will be affected. 

True or false: In Bezier, the degree of the polynomial defining the curve segment is one less than the number of defining polygon points.
- Very True

True or false: B-Spline allows the order of the basis function, so the degree of the resulting curve is independent of the number of vertices.
- Very True. The degree of the B-spline is an input describing the basis function independent of the number of vertices. The vertices can be split into groups based on the degree of the function, and the number of segments of the B0spline curve is the number of groups. 