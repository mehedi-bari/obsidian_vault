# Task1
It would be very distracting! 
It would be common in entrance of hotels

# Task2
not always true

# Task3
Texture baking from radiosity solution gives different results to texture baking form path racing. Why might one give safer results? This is because it doesn't depend on the point of view. So, things like colour bleeding can be baked without causing any issues. 
Things like mirrors changes depending on the viewpoint which cannot be computed.

# Task4
Ray Tracing: A high resolution is more expensive, so more pixels, and more light being shot per pixel.
Radiosity: More simulation equations if there are more objects, but if you increase the size of the rendered image. 


Caustic: It is caused by reflection/refraction by a curved surface, which can be done with the rendering equation, this can also be done by ray-tracing, and path tracing.
Motion Blur: It is not in the rendering equation. It is a time, $t$ component, and it is a component of our brain, and it cannot be modelled with both of them
flourence: issue with $t$ again [![File](https://learn.content.blackboardcdn.com/3900.82.0-rel.45+82d6e90/images/ci/ng/cal_year_event.gif) midterm-2019-solutions.pdf](https://online.manchester.ac.uk/bbcswebdav/pid-15112840-dt-content-rid-162851926_1/xid-162851926_1)
doppler effect: it is change in position over time, so it cannot be calculated using the rendering equation.
DOF: There is no position, or lens in the rendering equation! It is in ray-tracing, but 
Participating media: mediums such as fog, smoke, adn mist which interact with and scatters light as it passes though. It can done with ray-tracing, and  path tracing, but cannot be done radiosity!
$$\int^{\infty}_{0} (logx)g(x) = \frac{d}{da} \int^{\infty}_0 x^ag(x)dx$$ 