From the start of the course, we have mainly been interested in the **outer surface**  of the object. This is mainly because we can render things in very nicely, where it is generated using parametrically or using a mesh of connected polygons. 

Volume Rendering requires a 3D dataset, which can be generated synthetically using a **simulation** or scanning/measuring some real world phenomenon using e.g. CT, MRI, MicroCT, sonar, ground penetrating radar. 

It doesn't matter what units are measured, or what the properties the dataset contains, but it must be a 3D dataset.
# Direct Volume Rendering
Direct Volume Rendering creates images by casting rays into a volume set. 

Take this image:
![[Screenshot 2023-11-25 at 21.04.43.png]]
This is **voxel** structure, which is larger outermost cube.  Each one of the smaller cubes is a voxel. Inside each square there are data points. The `purple` part represent the bouncy part of the gold ball, and `white` part is the shell. Therefore the first problem of volume rendering is figuring out what is what. We have all of this information, but we require a **classifier** to put it into different groups.

### Step 1: Transfer Function
This step involves generating **colours** and **opacity** values for each voxels to classify the different materials.

Take the CAT scanner: It uses Hounsfield scale, and it uses calibration points water and air, and finds the units for lungs, muscles, and skull/bones. So, the data we get back from the CAT scanner is radiodensity values, which are just numbers, and doesn't contain any information about opacity or colour. In order to visualise this, we need to add colour; this requires a classifier which is known as the **transfer function**.
![[Screenshot 2023-11-25 at 21.13.29.png]]

Suppose you take this object, and we don't know how many different material there are. All we have is a voxel structure with the data information.
![[Screenshot 2023-11-25 at 21.20.46.png]]
The glass has one hounsfield, the hand has different hounsfield, and some combination of both depending on what is present. On the right, we have generated a graph. Now, we can say our data is made of two material, or a resolution is a bit poor so we are getting a mixture of both, or both.  

We can can associate an **alpha** value, which is the opacity, and also a colour to each category. Then we can classify each voxel our classifier. Now we are starting reconstruct the crude form of the hand. 
>For example, suppose we want to view only bone, without any of the clutter of muscle or fat. In this case we’d set the $\alpha$-value of all voxels that have been classed as being bone to 1, and we’d want to make all other materials totally transparent (i.e. set their α-value to 0). If we want instead to see muscle displayed partially transparently and overlaid on top of the bone, we’d just set the corresponding $\alpha$-values

The image looks poor, but if we make the **voxels smaller**, and sampled at a **higher frequency**, then we can acquire a really good image. 

### Second Step: Ray Casting/Tracing:
We fire a ray from the viewpoint, through a pixel in our view plane and into the volume. Then when it enters the volume, it takes small tiny little marches whilst looking at the **colour,** and **opacity** corresponding to voxel it is currently in. The **opacity** tell us how much colour to add to the running total, and we also keep track of the opacity we have encountered so far; so when we reach a certain limit or the end of the volume we can stop. 

The general idea here is that you keep track of an accumulated colour, and an accumulated opacity value. Every time you step along the ray you take into account how opaque a voxel is, and its colour, and add this effect to the accumulated values until you reach a certain ‘terminal opacity’

Like path tracing, we cast multiple rays per pixel, and do it for all the pixels in the view-plane. Unlike Ray Tracing where we typically spawn new secondary rays as the primary rays intersect with object surfaces, in Volume Rendering we allow the original primary ray to penetrate through the scene ‘into’ the data, and we **accumulate the effects of colour and transparency** along the ray to work out what coloured pixel to plot on our viewplane.
![[Screenshot 2023-11-25 at 21.28.23.png]]


>When calculating the value at a sample point along the ray, we could just use the value of the voxel we are passing through. Though this is quick, even with sub-voxel sampling distances along the ray it can still lead to aliasing effects, so it’s usually better to **interpolate** values from neighbouring voxels in 3D to get a more representative sample value. This process is called **Trilinear interpolation**.


### Adding surface effect
So, if we stopped at that the images would look something like this:

![[Screenshot 2023-11-25 at 22.37.05.png]]
They're all flat, and it looks like an x-ray; this is not surprising as we are doing a 'digital' x-ray. This effect is known as **additive reproduction**.

The problem is that we don't have a surface, and we haven't talked out a light source. We can create fake surface normals, so have a look at the image.
![[Screenshot 2023-11-25 at 22.40.34.png]]
We do this by **interpreting changes** in voxel values over the three different dimensions as giving the $x$, $y$ and $z$ components of a value that can be used as a kind of **surface normal vector**. Even though the vector’s direction doesn’t mean much in any physical or absolute sense, if the underlying data vary smoothly according to ‘surfaces’ that exist in the real world, then this vector will vary smoothly too, in some sense representing that surface.

TADA!
![[Screenshot 2023-11-25 at 22.44.01.png]]

It is **viewpoint** dependent! This makes it really expensive!

# Indirect Volume Rendering
In Direct Volume Rendering, any ‘surfaces’ that appear in the rendered image are **implicit**- which meant that they're visual artefacts of the process and only exists in the mind of the viewer. As human, we can see them, but the computer has no idea what surface it has drawn. 

An alternative approach is to create images from volume data - called **Indirect Volume Rendering**. This **explicitly** identifies surfaces in the volume set, and convert these into polynomial meshes, and then uses traditional polygonal rendering.

We usually use **isolines lines** to denote the idea of things being the same. For example, we use **contour lines** on maps to show different level compared to surface level. So moving up one isoline results in you moving up 100m. Isolines are present in 2D space, but when working with 3D we require to find **isosurface.** 
We want to perform a process like this in 3D, but with surfaces separating different classifiable things instead of lines. We then use these ISO surfaces to convert the point grid into a mesh. This is not an easy process in 3D. 

First you need a function to sample points at regular interval, and you can colour in these points according to the function.
![[Screenshot 2023-11-26 at 20.37.04.png]]

Creating these surfaces is known as **marching cubes**. The goal of marching cubes it to generate polygon meshes using the algorithm. To solve this problem, we can consider a single cube, and there are corner points which can be **inside** or outside, and since there are `8` points, there are $2^8=256$ possibilities. However, there are only `14` unique shapes - which are not rotation/symmetrical.
![[Screenshot 2023-11-26 at 20.41.22.png]]
![[Screenshot 2023-11-26 at 20.42.13.png]]
The output of marching cubes is a regular mesh, which can be rendered extremely quickly by the graphics card.

### Proxy geometry
An increasingly popular alternative to finding and rendering isosurfaces is to use ‘**proxy geometry**’ to recreate a volumetric image. This is a kind of half way house between rendering the image onto a viewplane (as with direct Volume Rendering), and creating a fully blown polygonal mesh of a surface.

![[Screenshot 2023-11-26 at 20.51.42.png]]
In terms of polygons, it takes very few to draw this proxy. Each scan only takes a few polygons, and there are only as many layers as there are scans. Rendering a **texture** on these layers is, of course, extremely fast on a GPU. But how do we create these textures? Recall how UV mapping takes place for 2D textures: 


**Texture Mapping**: We interpolate between the points on the surface and then find the colour at the calculated UV coordinate by interpolating over the texture. Now imagine doing this with a 3D texture, where that 3D texture is the voxel grid of scans:
![[Screenshot 2023-11-26 at 20.58.12.png]]
Modern GPUs usually support hardware 3D textures (known as volumetric textures) which makes this just as trivial as regular UV mapping. So the solution is to convert our voxel grid into a 3D texture and then simply apply this texture to our proxy surfaces.

We can tell that simply having a static stack of surfaces will not be good enough: If viewed from the side, we would see the gaps.
![[Screenshot 2023-11-26 at 20.59.25.png]]
To fix this, we need the surfaces to be parallel to the viewplane at all times. 
![[Screenshot 2023-11-26 at 21.00.01.png]]
This is an easy and fast calculation, so while this does technically make this method viewpoint dependent it is an insignificant amount of work. 

The amount of slices is very important. Not enough slices and the image simply doesn't come together.And when we reach a suitable amount the image becomes clear.

