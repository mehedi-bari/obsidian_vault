## Diffuse and specular reflection:

![[Screenshot 2023-09-18 at 20.59.46.png]]



Diffuse reflection is absorption and uniform radiation.
- some wavelengths are absorbed, some are reflected
- a green object looks green because it reflects only green.
![[Screenshot 2023-09-18 at 21.00.32.png]]
Specular reflection is reflection at the air/surface inferface:
- to a first approximation, the colour of the specular reflection is the same as the light source

This is an example of perfect specular reflection, which is where the angle of incident is the same as the angle of reflection.
![[Screenshot 2023-09-18 at 21.01.49.png]]

However what is more common is imperfect specular reflection, which is where there is a range of angle of reflection:
![[Screenshot 2023-09-18 at 21.03.14.png]]



We have an illumination model:
$$I_R = k_{aR}I_{aR} + \frac{I_{pR}}{d'}[k_{dR}(\hat{N} \cdot \hat{L}) + k_s(\hat{R} \cdot \hat{V})^n]$$
How do we apply this to a triangle mesh? We will look at three shading methods:
- Flat (constant)
- Gouraud (intensity)
- Phone (normal-vector)

![](Pasted%20image%2020230302141745.png)
## Flat (aka constant) shading
Take one of the vertices of the polygon, compute the surface normal, and apply the illumination model to that. Apply the resulting colour to the whole surface.
![](Pasted%20image%2020230302141928.png)
This method of shading gives results like this:
![](Pasted%20image%2020230302142318.png)
Because each polygon is uniformly coloured, we can see the mesh clearly. This is made worse by the Mach Band effect, which says that the human vision system perceives the intensity of edges as higher than they actually are, increasing contrast.
## Gouraud (aka intensity) Shading
Gouraud shading uses interpolation to smooth out the discontinuities between polygons.
First, to find the normal at some vertex it interpolates between the surface normals of each surface it is part of, approximating the shape that the polygons are representing:
![](Pasted%20image%2020230302142544.png)
To find the average surface normal for a point, this formula is used:
![](Pasted%20image%2020230302142636.png)
The local illumination model is applied to each vertex using this average normal. Now that vertex colours are calculated, the colours can be interpolated between the vertices:
![](Pasted%20image%2020230302143001.png)
First, you find the colours of $C_\text{Left}$ and $C_\text{Right}$ by interpolating between the colours of the two vertices that the point falls on. In this example, $C_\text{Left}$ is an average of $C_A$ and $C_C$ and $C_\text{Right}$ is an average of $C_B$ and $C_C$. Now that you have starting and ending colours for this scanline, you can calculate the colour of each pixel along the line by interpolating between $C_\text{Left}$ and $C_\text{Right}$.
This gives results like this:
![](Pasted%20image%2020230302143537.png)
The result is definitely smoother, but polygons on the edge are still sharp. This is apparent in places like the eyelids or the nostrils. This method also doesn't handle small specular highlights well:
![](Pasted%20image%2020230302143741.png)
#### Implementation
This implementation needs to be as optimised as possible. For each scanline we compute the colour increment between pixels instead of doing a full interpolation for every pixel:
![](Pasted%20image%2020230302143845.png)
We can do this same optimisation for the interpolation between the vertices to find $C_\text{Left}$ and $C_\text{Right}$.
## Phong (aka normal vector) interpolation
Similar to Gouraud, but instead of interpolating the colours for each pixel we interpolate the surface normals themselves. This method requires calculating a surface normal and then computing the illumination model for every pixel.

First, calculate the vertex normals in the same was as Gouraud. Now, instead of using them to calculate the vertex colours, perform this procedure:
![](Pasted%20image%2020230302144722.png)
For each scanline, find the average normals along the two edges of the polygon, instead of the average colour like in Gouraud. Then, interpolate between these two in the same way as with Gouraud, but again with the normals themselves. When this is done, compute the final colour using the illumination model.
This gives results like these (compared to Gouraud):
![](Pasted%20image%2020230302144925.png)
Here is a final comparison between all three:
![](Pasted%20image%2020230302145004.png)
## Rendering performance
Our local illumination model takes about 60 floating point operations (FLOPS) to compute the colour of one pixel. For a Gouraud-shaded triangle, it takes **180 FLOPS** to calculate the colours then about **2 FLOPS per pixel**. Phong, however, takes **60 FLOPS** for every pixel.
