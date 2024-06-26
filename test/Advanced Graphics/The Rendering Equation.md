
This is the Rendering Equation, which is a mathematical abstraction of how light interacts with materials in a 3D space. 
![[Screenshot 2023-11-05 at 20.42.48.png]]

The equation is actually based on similar mathematical representations of heat transfer. This is the basic idea:
You have a 3D environment with some objects in it.
![[Screenshot 2023-11-05 at 20.43.57.png]]
Each object radiates some amount of heat, some of which will hit the other objects and impart some energy. These other objects will be doing the same. This will continue until the objects all reach some heat equilibrium, wherein their temperature will stop changing.
This concept intuitively transfers well to simulating visible light. Add a viewpoint to the scene:
![[Screenshot 2023-11-05 at 20.45.27.png]]

What we want to sample is the steady equilibrium light values from these surfaces. This is what the rendering equation models.

Notice that this is **THE** graphical equation, not **A** graphical equation. This equation can describe essentially all graphical scenes, and trying to calculate what a scene looks like has come to be known as "solving the graphical equation".

# From Scratch: 
Consider this scene:
![[Screenshot 2023-11-05 at 20.49.15.png]]
We have a viewpoint (represented by a camera), a few objects, and a light source.
As for the objects, we have:
- A shiny ball
- A reflective monkey
- A diffuse fractal broccoli
- A transparent cube

So what colour should each of these things be to the camera? Well, clearly the light should be pure white because the light that the camera sees is coming directly from the bulb. The light is an **emitter**, and we want to take this into account in our formula.
What about the matte diffuse floor? The apparent colour of the floor is a function of the light bouncing off of it and the reflectivity of the floor's material. We can't see the floor because it is emitting light, but because it is reflecting it. The colour of this surface will not just be affected by direct reflections from light sources, either; it will be affected by light that is bouncing off of other objects in the room.
In this case the final colour is clearly dominated by the bright direct light of the lightbulb, but in other cases the colour can be affected more strongly by the surrounding surfaces.
So, let's apply these intuitions to the rendering equation. First let's explain what the equation takes:
$$L_o(\mathbf{x},w_o,\lambda,t) $$
This part represents **spectral radiance**. $\mathbf{x}$ is the point that the spectral radiance originates from, and $\omega_o$ is the direction it is moving. The $o$ in $\omega_o$ is for "out", as in it is the light moving "out" of the scene.
![[Screenshot 2023-11-05 at 20.53.41.png]]
Spectral radiance also takes into account the wavelength of light $\lambda$ and the time $t$, but these terms make the equation more complicated and can be reasonably ignored in a simple explanation, so let's remove them:
![[Screenshot 2023-11-05 at 20.54.42.png]]
So $L_o$ is an expression that represents the total light the observer receives from a point $\mathbf{x}$ along direction $\omega_o$. In other words, it's what we want to know: the colour of some point in the image from the observer's point of view.
$L_e(\mathbf{x}, \omega_o)$ represents light **emitted directly** from point $\mathbf{x}$ in direction $\omega_o$. This part will be the overwhelming decider of colour if point $\textbf{x}$ is on a light emitting surface such as a light bulb.

$$\int_\Omega$$
This integral says that, for the hemisphere $\Omega$, we will add up the contributions of every incoming vector$\omega_i$.
![[Screenshot 2023-11-05 at 21.08.18.png]]
The $i$ in $\omega_i$ stands for "incident".
$L_i(\mathbf{x},\omega_i)$ represents the incident light on $\mathbf{x}$ from direction $\omega_i$. In fact we will be adding up infinite $\omega_i$'s, this being inside an integral.
$f_r(\mathbf{x}, \omega_i, \omega_o)$ is the **Bidirectional Reflectance Distribution Function**, or **BRDF**. This part gets a whole video to itself, but in summary it modifies the incident light on $\mathbf{x}$ coming from $\omega_i$ in a way that corresponds to the material of $\mathbf{x}$. Essentially, it represents the way that the surface's material influences light reflections.
$(-\omega_i \cdot \mathbf{n})$ is the dot product of the inverse of the incident direction and the normal of the surface at $\mathbf{x}$.
![[Screenshot 2023-11-05 at 21.09.22.png]]
This represents how the effect of some incoming light source will be reduced by a sharp angle with the surface. If the light is coming in directly against the normal then it will be at it's brightest:
![[Screenshot 2023-11-05 at 21.09.50.png]]
But if it is just grazing the surface at a sharp near-$90\degree$ angle, the intensity will be lowered:
![[Screenshot 2023-11-05 at 21.10.10.png]]
In more concrete mathematical terms this term is just Lambert's Cosine Law. When the angle with the normal is $0\degree$ then $\cos\theta = 1$, and we have maximum effect. When the angle with the normal is near $90\degree$ then $\cos\theta$ is near $0$, and we have near minimum effect.
Remember that $\omega_i$ is just one incoming vector of the infinite number that we are summing up in this integral.

>So, in summary:
	To calculate the light that the viewer receives from some point $\textbf{x}$, we add up the direct emitted light from that point (if any) and the total light that was reflected off of it.
	Calculating $L_o(\textbf{x}, \omega_o)$ for all of a scene is often called "solving the rendering equation".

But can we simply just solve this equation to render a scene? Unfortunately, it isn't that simple. Even having simplified it by removing $\lambda$ and $t$, we still have an integral in there that we don't actually have a way to solve. We cannot just perform infinite calculations. We need some special technique to calculate a result to this integral, in the same way that we need a special technique (calculus) to solve integrals over simple polynomials.

The rendering equation is one of many equations in the "Fredholm Equations of the Second Kind". Mathematicians have found analytical solutions to several of these equations, but unfortunately the rendering equation is not one of those. Part of the reason why is that it's infinitely recursive; The $L_i(\textbf{x}, \omega_i)$ inside the integral is a nested rendering equation that must also be solved. It's worse than just being a potentially deep recursion:
![[Screenshot 2023-11-05 at 21.18.43.png]]
For example, finding the reflected light on $\textbf{x}$ requires finding the reflected light on the plinth, which requires finding the reflected light on the ball, which in fact **requires finding the reflected light on $\mathbf{x}$**, creating a loop that never ends. Clearly we need to cut corners somewhere here.

# Light and Materials
There are three ways that light can interact with a material:
![[Screenshot 2023-11-05 at 21.20.36.png]]
1. It can reflect off, which can give a shiny, mirror-like appearance with high specularity or a smooth, diffuse appearance with low specularity.
2. It can transmit through, which can make the object appear transparent or refract light like a prism, depending on the specifics of the material.
3. It can be absorbed.

All three of these interactions can be mixed together. That is, you could for example have a material that absorbs half of the light that hits it, and reflects the remaining half with high specularity.
# Reflections
If light hits a surface and reflects back off in a single direction (or a very tight range of close directions, at least) then we perceive it as a shiny mirrored surface.
![[Screenshot 2023-11-05 at 21.22.09.png]]
This is called a **mirror** reflection.
Because the angle of incidence and angle of reflection are (roughly) the same, the light coming off of the surface are identical (or very similar) in shape and colour to the light that hit it, resulting in a recreation of the incoming image.

Surfaces with this mirror appearance tend to be metallic, as the same mobile electrons that allow a material to conduct electricity also tend to repel electromagnetic radiation such as light. As long as the material is **smooth** and flat, **light** will reflect in a well defined direction. This will preserve the shape and the colour of the object.

On the other hand, a reflection is **diffuse** if the light scatters off in lots of different directions when it's reflected.
![[Screenshot 2023-11-05 at 21.24.32.png]]
In materials like this, the light is penetrating the surface a small amount before being reflected back out, resulting in a more varied exit angle. Because the reflected light is scattered so much, diffuse surfaces do not appear smooth or mirror-like and instead appear flatly coloured, for example white paper.

There are also **specular** reflections, which are similar to mirror reflections but with a variance in the reflection angle:
![[Screenshot 2023-11-05 at 21.25.00.png]]
Specular surfaces appear smooth, hard and shiny, but not mirror-like. If the spread is low enough then there may be a slight mirror image, but it will be very faint compared to a fully mirrored surface.

Generally, surfaces will not be purely mirrored, diffuse or specular - they will be a combination of the three. For example, here is a surface that has both diffuse and specular reflections:
![[Screenshot 2023-11-05 at 21.26.20.png]]
And of course in the real world, there is no such thing as a perfectly flat surface. Even a polished mirror that produces a great reflection is in reality not perfectly smooth. The previous mixed reflection surface probably appears more like this in reality:
![[Screenshot 2023-11-05 at 21.26.46.png]]
This applies to all kinds of reflections; you are not going to get a perfect mirror, and you are also not going to get a perfectly diffuse material, where the rays are equally distributed in all directions. If we want to model realistic surfaces, then we need a model that takes into account these imperfections, and this is what BRDF is trying to do.

# Colour
We perceive colour using the three kinds of light receptors in our eyes. Each of these three **cones** perceives a range of wavelengths, and the combination of these three cones allows us to perceive colour.
![[Screenshot 2023-11-05 at 21.35.39.png]]
(Note that we have way more red receptors than any others; this will be mentioned later.)
The range of electromagnetic radiation that these cones allow us to perceive is called the visible light spectrum. There is nothing special about this range of wavelengths; other animals have different cones that allow them to see a different range of colours. The visible light spectrum is only important to us because we're concerned with how humans see.
![](Pasted%20image%2020231102141231.png)
This graph plots the wavelength of each colour against the response of each cone when exposed to it. For example, when exposed to a saturated blue with a wavelength of about 460nm, the S cone has a strong response which the M and L cones have similarly weak responses.
Note that these cones are not named B, G and R, but instead are called S, M and L for Short, Medium and Long. This refers to the wavelength of the light they are most responsive to - Short for short wavelengths and Long for long wavelengths.
Notice that these curves are not evenly distributed across the visible light spectrum - M and L are quite close together while S is quite far away. In practice, this makes humans better at distinguishing differences between greens and reds.
This has important ramifications for computer graphics, in that when you experience a pure white, the distribution of colours will not actually be an even distribution of frequencies due to our sensitivity to certain frequencies over others.

For most topics in this course these subtleties do not matter, but it is important to keep in mind at all times. We often talk about primary colour as if it's some fundamental property of light; that mixing an "equal amount" of red, green and blue will produce white, and that any other colour is just some mix of these primary colours. In reality this is just a convenient shorthand. Colours across the visible light spectrum all exist independently of the primary colours. For example, consider this aqua-marine colour:
![[Screenshot 2023-11-05 at 21.44.36.png]]
In terms of colour we might think of this as a mix of blue and green, but it is important to remember that this is no fundamental property of the colour. It is entirely possible for this colour to exist without any use of the primary colours blue and green. You can achieve the same responses from the cones with a mix of different wavelengths, but that is not the only way.
Also note that this spectrum doesn't contain every colour; where is purple? Purple actually cannot exist as a monochromatic colour; it is always a mixture of many different wavelengths.

# Bidirectional Reflectance Distribution Function
$$f_r(w_i,w_o) = \frac{radience}{irradiance}$$
A BRDF (in a simplified form) describes the ratio between radiance and irradiance for a surface. Radiance and irradiance are terms from radiometry with specific meanings:
**Radiance** is the **radiant flux** emitted, reflected, transmitted or received by a given surface, **per unit solid angle per unit projected area**.
**Radiant flux** is a measure of energy over time. Essentially, it's how much energy is imparted in some amount of time.
**Per unit solid angle, per unit projected area** is what really complicates the calculation (and the definition). What this means is that instead of measuring our quantity (radiant flux) over some flat surface (in which case it would be **per unit distance squared** or similar), we are measuring over the projected surface of a (hemi)sphere:
![[Screenshot 2023-11-05 at 21.57.19.png]]
This can seem quite complicated, so let's start from the basics. We have a hemisphere $\Omega$ around our point $\mathbf{x}$, in a regular 3D coordinate system.

![[Screenshot 2023-11-05 at 21.58.17.png]]
We have our incident ray and reflected ray, both of which are parameterised in terms of their **altitude** $\theta$ and the **azimuth** $\phi$.
![[Screenshot 2023-11-05 at 21.59.09.png]]
The BRDF then does some integration over some delta quantities (i dont understand what they are). When you take this to the limit, you get *something* in the direction of the reflected ray which represents *something*. I think.
![[Screenshot 2023-11-05 at 22.05.54.png]]
This is where $\lambda$ can be re-introduced; the result of this calculation will be different depending on the wavelength of colour:
![[Screenshot 2023-11-05 at 22.07.15.png]]
How this function behaves for different wavelengths of light defines how the surface colours the light it reflects. For example, the BDF would tell us for this material how much red light energy is heading out, specifically along the vector $w_o$  We would get different values for different wavelengths.

In summary, the BRDF of a surface represents its general behaviour when reflecting light. It gives how diffuse or specular it is, how much light it absorbs of each wavelength, etc.
![[Screenshot 2023-11-05 at 22.15.34.png]]
You could have a BRDF that just returns 0 for all possible inputs. That would effectively be saying regardless of what kind of light comes in any direction, and regardless of what angle you're looking at this material, the answer is that no energy comes out. That would give you a black surface. You might write a BRDF that says whatever comes in goes out. Or you might perturb that a little bit to make the effect more complex and more interesting.

BRDF captures light hitting a certain point on a material which might reflect off in a specular spike. 

However, that does not cover every way that light can interact with a surface. You may have a transmissive surface that transmits light through it. Often the light will be refracted, coming out parallel on the other side but shifted over. And often the light will come out of the object in a similar manner to the light that reflected off of it. None of this behaviour is captured in the BRDF, but there is another component called a **BTDF** (Bidirectional Transmittance Distribution Function) which is very similar and which can describe this.
![[Screenshot 2023-11-05 at 22.34.53.png]]
In addition to these, there is another behaviour called **Subsurface Scattering** that neither of these describe. When light hits a **translucent surface**, it might not reflect or transmit, but rather bounce around a little around the material and then escaping out the back. Most **non-metalic** surfaces exhibit this to some extent.
![[Screenshot 2023-11-05 at 22.36.37.png]]
Some light, instead of reflecting immediately or refracting through to the other side of the object, may meander around in the object for a while before being ejected back out of the object. This is visible in many non-metallic objects in real life, for example human skin.
![[Screenshot 2023-11-05 at 22.39.48.png]]
The subsurface scattering is the red glow.
Here is a rendered example. First, without subsurface scattering:
![[Screenshot 2023-11-05 at 22.40.07.png]]
And with subsurface scattering:
![[Screenshot 2023-11-05 at 22.40.24.png]]
The function that models Subsurface Scattering is called a **BSSSDF** (Bidirectional SubSurface Scattering Distribution Function), following the naming pattern of the other functions.

A combination of any of these things (BRDF + BTDF + BSSSDF) is often called a **BSDF**, for Bidirectional Scattering Distribution Function.