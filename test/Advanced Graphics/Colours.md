Light is a kind of electromagnetic wave residing between 380nm and 760nm in wavelength. Light is characterised by it's spectrum, which is the amount of energy that light of each wavelength has.
![[Screenshot 2023-10-07 at 20.58.02.png]]

To see the wavelengths of light we can use a **prism** or a **diffraction grating**
![[Screenshot 2023-10-07 at 21.11.28.png]]
#### Diffraction Grating:
This is where a large number of closely spaces slits are etched onto a surface. These slits are narrow which allows light to pass. It is used to **disperse** light.
You can think of it like this: a diffraction grating shifts light as a **function of wavelength**. When light comes from various wavelengths, it disperses the different wavelengths at different angles.
There are 3 main characteristics:
- Order: Diffraction grating produce multiple orders of spectra.
- Wavelength Dispersion: diffraction gratings disperses dependent on the wavelength - with shorter wavelengths being diffracted at larger angles.
- Resolution: The ability of a diffraction depends on the number of ruling per unit length.
## The Process
The perceived light is a composite of the illumination of the light itself multiplied by the reflectance of the surface(s) it bounced off of to reach your eye.
![[Screenshot 2023-10-07 at 21.12.23.png]]

## Making Colours 
Our eyes percieve colour using three types of cone, which can each measure one wavelength in these ranges:
![[Screenshot 2023-10-07 at 21.13.20.png]]
Our eyes have 3 cones $S,M,L.$ The primary (additive) colours are red, green and blue, vaguely matching the cones. The response can be calculated an integral over all the stimulus multiplied by the cone response. 

However, the good thing is that we have **3 primary, additive colours** which can be used to represent those colours, so we don't need to mess with those wavelengths. We call this **additive colour synthesis**.

**Subtractive colour synthesis** can also be used to make pigments. It works by using red, yellow, blue to absorb different wavelengths, hence making a new colour. Additionally, the more pigments you addd, the closer you are to absorbed all colours, which results in darker hues.
![[Screenshot 2023-10-07 at 21.24.19.png]]

![[Screenshot 2023-10-07 at 21.25.56.png]]
The left picture shows additive, as the wavelengths are being added. The right ones shows subtractive, as the wavelengths are being removed.

### Issue! OverLap!
If you want to **scale** the cone spectra for $S$, but you get some undesired response from $M$ & $L$.  The fundamental problem is that there is an infinite wavelength function, and this is projected into 3 types of cones, which are not **orthogonal**, as a result there is some **overlap** in the responses. 
![[Screenshot 2023-10-07 at 21.31.26.png]]

#### Gargon
Light intensity/value is measured in $cd/m^2$ (candela per meter squared) and represents how bright the colour is.
- A high-intensity colour is closest to white, and dark means low-intensity.
- It is the area under the light wave on the diagram:
![[Screenshot 2023-10-07 at 21.36.34.png]]

The hue of the colour is determined by the wavelength of the **mean** of the light wave, that is where it is centrally positioned on the graph. 
- It refers to the pure dominant colour of the object, like blue, green, magenta.
![[Screenshot 2023-10-07 at 21.37.10.png]]



The Saturation/Chroma is the amount of light in the wave that isn't the "main" colour; a large amount of non-central energy will wash out the colour and lead to a less saturated perception. On the graph, this corresponds to the deviation of the curve from the mean.
- It refers to the purity of the colour, indicating how intense it is.
- Highly chromatic colours are rich, and vibrant.
![[Screenshot 2023-10-07 at 21.37.29.png]]
All of these three factors are related to each other, and they cannot just be changed independently.
![[Screenshot 2023-10-07 at 21.37.44.png]]

# Colour Spaces
How do reproduce a colour given 3 bases? Human vision is linear and three-dimensional, so you can suitably convert any colour space to one that humans can perceive. For this reason there are many colour spaces, but the most popular now is **CIE XYZ**.

The colour values for CIE XYZ were found with this practical method:
![[Screenshot 2023-10-07 at 21.48.09.png]]
A subject monitors a split screen, one side being illuminated by the colour they want to measure and the other size being illuminated by three primary lights of R, G and B. The values of the RGB lights are adjusted until the subject decides the difference in colour between the test light and the combined primary lights is negligible. The 3 primary colours are chosen for **robust reproduction**. Because light is linear, you can interpolate between the values found using this method to get a continuous colour space. The results 3 number for each wavelength are called **tristimulus colours**. Some colours cannot be reproduced because  of **negative response**, they have to shoot light at the back screen.

## Interpreting Monochromatic Wavelength Graphs
At a specific wavelength colour can be reproduced using the $r,g,b$  functions using $\lambda$ as the wavelength parameter. The diagram below shows how are eyes perceive light, not how $RGB$ works. Note: One of the responses can be **negative** which is **NOT** possible in $RGB$.   

![[Screenshot 2023-10-07 at 21.58.51.png]]

To solve the negativity, we add light by adding more light to the other two cones $G$ & $B$. 
![[Screenshot 2023-10-07 at 22.03.29.png]]


## Chromaticity Diagram:
These diagrams are used to make a graphical representation of **hue** and **saturation.** These usually separate all the colours with different hue and saturation, while eliminating any information about any brightness or intensity. 
It is important to colours on a vector will have the same **chromaticity**, but different **light intensity**. 
![[Screenshot 2023-10-07 at 22.04.07.png]]


## Transformation:
Since all of the functions are linear, we can convert from one colour space to another.
![[Screenshot 2023-10-07 at 22.20.21.png]]


## Different Colour Spaces:
Here it shows different **colour spaces**. Give 3 primaries, they always form a triangle in a chromaticity diagram because you can only add colours, and there is no **negative light**.
![[Screenshot 2023-10-07 at 22.20.47.png]]


## Scaling of Brightness
The human eye is more sensitive to certain brightness of colours ratios than others, so doing it linearly isn't always a solution. 
- One solution is to use **logarithmic**, however this would create an infinite spectra around 0. 
- The ultimate solution is using **Gamma2.2**, or gamma correction, which is a on-linear solution which can be used to present various brightness. Remember you can always decode back to the linear values.

![[Screenshot 2023-10-07 at 22.26.24.png]]

**metamerism** : under certain conditions you could perceive the colour as the same, but they're different colours.
colour gamut: how much of the full colour space can the device show, which is a subset of it.
gamma encoding: there are some wavelengths of colours, which are easier to see for our eye, or which is present in the computer system, this makes it easier to see. This is non-linear!



