There are three main kinds of animation:
1) Artist-driven: Where the animation is created manually. Involves steps such as Rigging, Skinning and Posing.    
	- Skinning - It is process of adding weight to each rig. It determines how a mesh deforms as the bones move. It essentially controls how the character's surface stretches, squashes under motion + making it natural.
	- Posing: It is manipulating the rig controls to create a specific positions or poses; this makes the character expressive, and convey emotions.
2) Data-driven: Where the animation is created using recorded data. Motion capture is the main example.
3) Procedural: Where the animation is generated automatically by the computer. It uses **physics simulation** to make it realistic, and model complex behaviours like crowd simulation, fluid dynamics. An example is fabric simulation.
4) Physics Based Animation
![[Screenshot 2023-10-07 at 22.43.06.png]]

## Artist Driven:
There are some crucial concepts in animation:
- Squash and stretch - Squash is how an object deforms based on the pressure exerted on it, or it's own exertion. Stretch means to increase the sense of speed, and emphasise the squash by contrast. 
![[Screenshot 2023-10-07 at 22.45.59.png]]
- Timing - The apparent weight of objects is portrayed by the speed and acceleration of their movements. Heavily related to interpolation.
![[Screenshot 2023-10-07 at 22.46.25.png]]

#### Rigging:
Building **3D models** and their **animation control** is called **rigging**. It is a crucial step to enable **realistic and expressive** movement. Animation is usually specified by using **low-dimensional** controls opposed to re-modelling the whole thing.   
These **skeletons** or **control structures** typically consist of bones or joints that can be manipulated to pose the model, and they act as **low-dimensional controls** to specify the animation. We usually use the low level semantic controls determine the high level semantic ones.
	$\square$  It is more **efficient** and **practical** to use these low-level controls like angles or bone transformations to determine the high-level semantic animation.
	$\square$  For example, it's much easier to manipulate a bone in the rig, and the connected muscles or other parts of the character's body move accordingly, creating a more lifelike and expressive animation.
![[Screenshot 2023-10-14 at 23.33.07.png]]

#### Skinning:
How do we animate a skeleton? We know how to animate a bone hierarchy by changing the joint angles using bone transformation, and that goes over time which is known as **key framing**. So we can animate the skeleton, but how to move the mesh based on the movement of the skeleton/rig?

Skinning is the process of **linking a mesh** to the bones in a skeleton such that the mesh animates along with the skeleton.
![[Screenshot 2023-10-15 at 20.09.07.png]]
The most popular technique is Skeleton Subspace Deformation (SSD), but other methods of skinning exist.

We define which vertices on the model should move with which bone by assigning each vertex a weight for each bone. If a vertex has max weight for a single bone then it will exactly follow the transformations of that bone. If a vertex has zero weight for a bone then it will not be effected at all by the transformations of that bone. Typically, a vertex will be affected by multiple bones, which provides a more fluid animation.
![[Screenshot 2023-10-15 at 20.20.13.png]]

In this example coloured patches represent sections of the mesh that belong to a single bone, and black patches represent sections that belong to multiple bones:![[Screenshot 2023-10-15 at 20.21.30.png]]You can see that the parts belonging to multiple bones are around the joints, which is where you would naturally expect smooth bends to happen.
Formally speaking, we define these weights as a function $W$:
![[Screenshot 2023-10-15 at 20.23.33.png]]
where $i$ is the vertex and $j$ is the bone. So, $W_{ij}$ is the weight of vertex $i$ for bone $j$.
When $W_{ij} = 1$, vertex $i$ is **rigidly attached** to bone $j$ and will follow it's transformations exactly.
When $W_{ij} = 0$, vertex $i$ is unattached to bone $j$ and is not influenced by it's transformations.
Two important properties:
	$\square$   Generally speaking, the weight is **non-negative (Between 0 and 1)**
	$\square$   For any given vertex the s**um of the weights across all bones must equal 1**.
$$\sum_{j \in \text{Bones}}W_{ij} = 1 \text{ for all $i$}$$
Consider these bones in a resting position (also known as **bind position**):
![[Screenshot 2023-10-15 at 20.43.35.png]]
We know that the weight of $P_0$ is split half-and-half between these two bones.
We want to find the position of $P_0$ after some transformation ($T^\prime _1$ and $T_2^\prime$) of the bones. 
![[Screenshot 2023-10-15 at 20.44.18.png]]
(In less ugly notation, $P'_0 = 0.5P'_1 + 0.5P'_2$).
We calculate the position of the point $P'_1$ by applying the same transformation that was applied to $T_1$ to $P_0$. The same is done for $T_2$ to get $P'_2$. We now multiply these two positions by the weights of the corresponding bones and sum them up to get the final position $P'_0$.
We know that the weight of $P_0$ is split half-and-half between these two bones.
We want to find the position of $P_0$ after some transformation of the bones. 
(In less ugly notation, $P'_0 = 0.5P'_1 + 0.5P'_2$).
We calculate the position of the point $P'_1$ by applying the same transformation that was applied to $T_1$ to $P_0$. The same is done for $T_2$ to get $P'_2$. We now multiply these two positions by the weights of the corresponding bones and sum them up to get the final position $P'_0$.

Vertices' positions are given in world space, while transformations applied to bones (and thus to the vertices) will be taking place locally. To remedy this we must convert the vertices' positions to local space using like this:
![[Screenshot 2023-10-15 at 20.54.28.png]]
$p_i$ is the global position of the vertex in bind position, $B_j$ is the matrix representing the coordinate system of bone $j$ relative to world space (where applying the inverse converts the world space vertex coords to local bone space coords), and $T_j$ converts back from local bone space to world space.
Basically, $T_jB_j^{-1}$ gives the relative change between the bone transformation from the bind to the current pose, and applying it to the point will transform it accordingly.

How do we get the vertex weights? Usually, by painting them on by hand. There are some automatic methods, but they aren't good enough to supersede doing it manually.

## Data Driven
Motion falls into two different categories, which need to be handled differently:
- Production - Motion in an offline production such as a movie, where there is lots of time to generate animation.
- Interactive - Motion in an immediate interactive form such as a game or a simulator, where there is little time and information to generate animation.

When you animate, you don't go frame by frame and create each pose one after the other. You first create **keyframes**, strong poses with lots of time in-between them, and then create **tweens** which bridge the gaps between these keyframes:
![[Screenshot 2023-10-07 at 22.47.18.png]]

## Procedural Animation
Procedural animation, like procedural surfaces or curves, is animation that is expressed as a function of a number of parameters. For example, if you wanted to animate a clock you could manually set the position of the clock hands for every single second, for the entire time the clock is visible. More reasonably, you could define the position of the clock hands according to a function which takes the current time as a parameter, making the animation completely automatic.
This also includes simulations, such as foliage, objects with physics, cloth physics, etc.

## Skeleton Animation:
For a simpler **rigging**, we need to use an **articulated skeleton**. 
	$\square$  **Topology**: how the different body parts/joints are connected to each other.          Furthermore, which elements are connected.
	$\square$  **Geometric relationship**: defines the relative positions and orientations of            the joints. 
	$\square$  **Hierarchy**: The bones are organised in a tree like structure to help establish         a parent-child relationship. There should be **NO LOOPS**.
The low-level dimensional control is done using angles.
![[Screenshot 2023-10-14 at 23.47.20.png]]

#### Forward Kinematics
 The simplest way to animate this skeleton is by rotating the bones to achieve the desired pose, which is called **forward kinematics**. Forward kinematics describes the position of the body-part as a function of joint angles. Body part are usually called bones. 
![[Screenshot 2023-10-15 at 09.26.54.png]]
In this image, the "end effector" is $p$, which is the result of the forward kinematics. The input is in the form of the two angles $\theta_1$ and $\theta_2$, which are continuous functions that the animator defines (see represented on the right as graphs.)
#### Inverse Kinematics
The inverse of this is (appropriately) called **inverse kinematics**. With this method, the animator gives a desired endpoint (still called the end effector) and the computer instead calculates the required angles for the bones to reach this endpoint.
![[Screenshot 2023-10-15 at 09.30.55.png]]
Advantages:
	$\square$   The benefit of inverse kinematics is that it allows the animator a **great deal of control** over the position of body parts which forward kinematics doesn't. It allows  you to achieve **specific poses, and movements** where **precise control** is needed.
	$\square$   It enables **flexible** animation, which all an animator can give an absolute position for some body part that does not change with the rest of the body, for example if a character is standing up on a bus and their body is shaking around, but their hand is held still on a handle.

Disadvantages:
	$\square$   However, inverse kinematics is a **complex problem** to solve: For any given point there are **many possible ways** to achieve the desired location for the end effector, and there may be a large number of joints to solve for.
	There are also very consuming for designers to make these. 
	$\square$   In addition, there may be **no solution** at all. For example, if the desired end effector is too far away for the bones to reach even when fully outstretched, or if there is a minimum angle constraint and the angle between a bone and the end effector is too great. This could lead to animation being **inconsistent** as doesn't flow the laws of physics.
	$\square$   **Complex Set-Up**: Setting up Inverse kinematic systems can be complex and **time-consuming**, as it often involves defining constraints, limits, and dependencies between components.

## Motion capture
Instead of manually animating a rig, you can take a **data-driven** approach where the we capture pose of a character as function of time which is extracted from real footage of actors. We use  **optical markers** and **high speed cameras** to record the 3D positions of these markers. Generally the actors will be required to wear a large number of markers to allow easy, automated extraction of the position of many points on their body. 
**Important Note:** The character's movement is governed by animation controls that influence bone transformations. As markers cannot be directly placed on the character's bones, a process known as **retargeting** is employed to translate marker positions into character controls, ensuring seamless motion capture integration.
![[Screenshot 2023-10-15 at 19.52.09.png]]



## Physics-Based animation
This is where you assign **physical properties** to objects, like forces, masses, and gravity.  We usually use **particles** or **mass spring** systems. You typically solve physics equation of motion such as rigid body, fluid motion.
	Note: Procedural Animation, like wind, is also a physical animation. 
###### Side Note:
There are different kinds of dynamics:
$\square$  Points Particles
$\square$  Rigid body
$\square$  Deformable body
## Mass Spring Models
Simulate a surface that folds like cloth, which is hold together using internal springs. Ideal for cloth animations.
![[Screenshot 2023-10-15 at 21.31.55.png]]
Here is a simple implementation of internal springs, shown in 2D simulating a strand of hair:
The objective here is to keep the distance between particles constant, so we use **Hooke's Law** for calculating the force exerted by a spring. The variables involved are:
![[Screenshot 2023-10-15 at 22.58.59.png]]
$$F(P_i,P_j)=K(L_0 - ||P_iP_j||)\frac{P_j \overrightarrow{P_i}}{||P_i \overrightarrow{P_j}||}$$
	$\square$  $P_i, P_j$ - The points connected by the spring. The calculated force acts on $P_j$ and pulls it towards $P_i$.
	$\square$  $L_0$ - The length of the spring when at rest.
	$\square$  $||P_j \overrightarrow{P_j}||$: This represents the Euclidean distance (norm) between points $P_i$ and $P_j$, which is essentially the current length of the spring. It is the normalising constant.
	$\square$  $K$ - A scalar value representing the stiffness of the spring. A stiffer spring will pull back to rest length with greater force.

$F(P_i, P_j)$ calculates the force exerted on $P_j$ by the spring between it and $P_i$, but we can easily find the force exerted on $P_i$ by the same spring by simply inverting the result. Remember Newton's third law; for each action (force) there is an equal and opposite reaction (force).

You can essentially implement this same idea for strings as hair simulation.

With this method, we get three types of forces interacting on the model (be it string, hair or cloth):
- **Structural forces**, which enforce strict invariant properties on the system. For example, you may require certain particles to have constant distance from each other or to not move (e.g. anchoring one side of a flag to a pole), or you may enforce a constant distance between all particles if the cloth material you are simulating is non-elastic. These should ideally be **hard constraints**, and not forces.
- **Internal deformation forces**, which are the internal forces described prior that cause a string to bend, a piece of cloth to flatten, etc.
- **External forces**, such as gravity, friction, wind, etc.


## Particle Systems
Simulate a large set of small particles. Ideal for fluid simulations (e.g. water, smoke, flames, sparks). We will cover Point Dynamics.
![[Screenshot 2023-10-15 at 21.27.37.png]]
For each particle we need to store some properties representing their current state. This can include:
- Position
- Velocity
- Age
- Colour
Particles are the borderline between physics based animation, and procedural animation.
	$\square$  **Emitters** are objects that create particles, for example a sprinkler or an exhaust pipe.
	$\square$  **Forcefields** affect the particles, for example a wind or gravity forcefield will change the acceleration/velocity.
	$\square$  Finally, using the **properties** of the particles and taking into account external forces, we make the particles move by implementing the laws of mechanics. We do this using Ordinary Differential Equations (ODEs). 
	$\square$  In the simplest case, particles are **completely independent** of each other. They often have lifetimes, beyond which they are removed.
	$\square$  Particles typically  **do not interact with each other**.
By using enough particles (and enough randomness), we can achieve some nice effects; while we are treating them as points while calculating the dynamics, we can render them however we like.
Here is something you might recreate using a particle system:
![[Screenshot 2023-10-15 at 21.30.30.png]]


## Ordinary Differential Equations (ODEs)
We have many tools to solve differential equations and thus implement the laws of mechanics in our simulations. Take, for example, this equation representing the Newtonian mechanics for point mass:
$$\overrightarrow{F} = m \overrightarrow{a}$$
We can rewrite this as a differential equation, as both force and acceleration are vectors. Express acceleration in terms of the position vector:
$$\overrightarrow{\mathbf{F}} = m \frac{d^2\overrightarrow{\mathbf{x}}}{dt^2}$$
Split this into two ODEs:
$$\frac{d}{dt}\overrightarrow{\mathbf{x}} = \overrightarrow{\mathbf{v}}$$
$$\frac{d}{dt}\overrightarrow{\mathbf{v}} = \frac{\overrightarrow{\mathbf{F}}}{m}$$
Then combine into a single state vector $X$ to get a 1st order ODE, and take the derivative of both sides:
![[Screenshot 2023-10-15 at 22.02.31.png]]
![](Pasted%20image%2020231013105151.png)
We can calculate $X$ (that is, $x$ and $v$) using this result.

![[Screenshot 2023-10-15 at 22.16.36.png]]
We can use this iterative approach, and use a guess $x_i$ to find $x_{i+1}$. This can be used to find the next state.

### Euler's Methods 
$$t_1 = t_0 + h$$
$$\mathbf{X_1} = \mathbf{X_0} + hf(\mathbf{X_0,t_0)}$$
The Euler method is a straightforward but relatively simple way to approximate solutions for ODEs. However, it may not always provide **highly accurate results**, especially for ODEs with **complex** or** rapidly changing behaviour.**
	$\square$  It provides a piecewise linear approximation to the path.
	$\square$  $\mathbf{X_0}$ is the position at time $0$, $h$ is the step size, and the step forward is $hf(\mathbf{X_0,t_0)}$.

![[Screenshot 2023-10-15 at 22.46.32.png]]
	$\square$  $X_t$ is a trajectory in multidimensional state space
	$\square$  $f(\mathbf{X},t)$ typically describes the **derivatives** that determine how the state $\mathbf{X}$ evolves with time.
	$\square$  We scale the vector by $h$, which is the step size.  Smaller the $h$ is more **smooth** the curves are, and **more accurate**. 


