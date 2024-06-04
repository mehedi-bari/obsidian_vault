There are different types of simulation: 
$\square$  Rigid Body Simulations
$\square$  Deformable Object Simulations
$\square$  Particle Model Simulation
$\square$  Mass Spring Fracture Model simulation
$\square$  Grid-Based Fluid Simulation
$\square$  Hybrid Fluid Simulation 

## Rigid Body Simulation
![[Screenshot 2023-10-21 at 19.57.42.png]]
Mass Spring Models is all about simulating a single point which we call particles. Rigid Body has an actual **geometry**, consider a rock, and it can have a particular orientation which allows it to **rotate** around an axis.
Particle systems have 3 **degrees of freedom**(DOF), which corresponds to $x,y,z$ values.
While, Rigid Body system have 6 DOF, which include $x,y,z$ as well as the **rotation** around each axis. 
>Note: Rigid Bodies are far more complex than Particle systems.
### How does rigid body systems interact with its environment?
The challenge is usually how the rigid body **responds** to its environment.
>E.g. we drop a rock on the edge it can either bounce back, or rotate depending on the location of contact. How do model this?
![[Screenshot 2023-10-21 at 20.05.50.png]]
#### Force and Torque
There would be a force pushing back at the rock, which is the **normal** force. There would also be a **torque** force which is defined as the rotating force.
#### Impulse-Based Collision
A very common approach for rigid body simulation is **impulse-based collision**. This is where you skip the force which controls the acceleration $\longmapsto$ velocity. We directly modify the **velocity** by defining the impulse.
>Note: The impulse-based collision can also be applied to mass-spring models.
#### Rest-in-Contact
When a rigid body is stable on a surface, we should make sure it says stable. Suppose we calculate all the points of contact, and get a force, the rock would look like its **vibrating/wobbling,** if there are errors in the calculations or they're not calculated at the exact time. So, we define **rest-in-contact**, where we don't simulate the object at all.
We stop the simulation until another force arrives that **releases** the rigid body from that **state.**
#### Stacking
The collision of one rigid body on top of another is called **stacking.** From the picture above, both the rocks are **stacking** and are stable. The challenge is that a change of state of one rigid body affects the rest. 

### Articulated Rigid Body simulation
Another important concept is the **articulated rigid body simulation**, which is similar from the rigging step from **Animation Principles**.
Suppose we have two bones, and we want to bend them. There is a joint, which is called the **joint constraint**, and stops the bones moving in any **arbitrary form.** This **limits** the degree of freedom. 
#### Approach 1:
![[Screenshot 2023-10-21 at 20.30.25.png]]
Each rigid body has $6$ degrees of freedom. However, the **joint constraint** means that it cannot rotate around $2$ axis, as it can rotate around $1$ axis or that **orientation** is not possible, so we need to remove $2$ degrees of freedom. Finally, since they're connected they cannot move on their own, so we reduce their DOF by $3$.
>$6+6-2-3=7$
#### Approach 2:
![[Screenshot 2023-10-21 at 20.36.41.png]]
Since every rigid body has $6$ DOF, and now we have an additional $1$ DOF being the bone orientation.
>$6+1=7$
 
#### And more
![[Screenshot 2023-10-21 at 20.48.40.png]]
These articulated rigid body simulation are used not only for human simulation, but also cars, or any other object that consist of rigid body component that they are somehow connected. Based on the joint constraints connecting these rigid bodies, the possible movements are defined as well as the available DOF. For example, we know wheels only rotate in one directions. So there are different types of joints defining the movements.


## Deformable Object Simulation:
Another important type of simulation is **Deformable Object Simulation**. These models are usually elastic like octopus.
#### Finite Element Method(FEM):
A particular type for Deformable Objects Simulation is called **Finite Element method**(FEM).
![[Screenshot 2023-10-21 at 20.53.55.png]]
To start the FEM simulation, we get a deformable object and model in a mesh, we first convert it into tetrahedrals and this process is called **Tetrahedralisation**. So you see the original mesh in blue and it converted to pink tetrahedrals. 

>The reason we use tetrahedra is because it is the **simplest** 3D object for volume. Same as triangles for surfaces in 2D.

Thus for each tetrahedral, we know it’s rest shape and when it deforms, it returns back to its rest shape. And FEM allows us to compute the forces needed to go from deformed shape to rest shape. 
To summarise,  all we need is to compute the forces that applies to **each vertex of the tetrahedral** to get back to the rest shape.

>FEM resembles the mass-spring model that also tend to go back to the rest length but in 1D. So the mass-spring is much simpler that dealing with volume in deformable objects.


## Mass-Spring Fracture simulation
- A mass-spring model simulation represents objects as a collection of masses connected by springs.
- This model can be used for simulating deformable objects, and when "fracture" is mentioned, it may involve simulating the breaking or fragmentation of objects.
![[Screenshot 2023-10-21 at 21.04.05.png]]
 Here springs are located between every two particle but the stiffness is too high and if the amount of force passes a threshold, the springs break and it propagates the neighbour springs and so on...


## Particle-Based Fluid simulation
Particle simulations model systems using individual particles with specific properties like position, mass, and velocity. In this case, lots of particles are **interacting** with each other.
![[Screenshot 2023-10-21 at 21.06.40.png]]
 As you see on top, we use particles for the simulation phase, but in time of rendering, we wrap them around a **mesh** and render it using surface representations. One of the techniques to solve the motion of fluid simulation is called **Lagrangian fluid simulation**.

## Grid-Bassed Fluid simulation
Another type of simulation for Fluid simulation is **Grid based**. It means given the bounding box of the fluid, we first **discretise** the object and analyse the attributes of the object for every **voxel**. Remember the **voxel** is each of these small components of the 3d volume. Same as pixel that is defined for a 2D image. 
The volume in and out of the box should remain constant.
One of the techniques to solve the motion of fluid simulation using grid-based is called **Eulerian-fluid simulation**,

![[Screenshot 2023-10-21 at 21.43.28.png]]

## Hybrid-simulation
Combining Eulerian and Lagrangian methods provides the best of two worlds and this is called **hybrid fluid simulation**. So we have grid but also particles and use each representations based on the purpose of action. Note these fluid simulation are not limited to liquids, they can be applied for smoke, fire, cloth etc.

![[Screenshot 2023-10-21 at 21.50.16.png]]


