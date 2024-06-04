## Hyperplanes:
![[Screenshot 2023-05-06 at 15.41.06.png]]
 The $\mathbf{w}^T \mathbf{x} +b$ represents the **perpendicular** line, and then || $\mathbf{w}$ ||$_2$  represents the $l_2$ norm. Therefore $r$ represents the distance!
To find the distance from the origin to the **hyperplane** we use $\frac{b}{\| \mathbf{w} \|_2}$  
We call $b$ the bias when we set $\mathbf{w}$ as $0$

### Parallel Hyperplane:
![[Screenshot 2023-05-06 at 15.47.24.png]]
The distance of $r$ is indiscriminant of $b$ 

### Serpartion Margin:
Given two parallel hyperplanes below, we separate the two clases of data points by preventing the data points from falling into the margin:
$\mathbf{w}^T\mathbf{x}+b \geq 1, y = 1$  or $\mathbf{w}^T\mathbf{x}+b \leq -1, y = -1$  $\longrightarrow$ $y(\mathbf{w}^T\mathbf{x} +b) \geq 1$
- The region bounded by these two hyperplanes is called the separation margin given by $\rho =\frac{b}{\| \mathbf{w} \|_2} = \frac{2}{\sqrt{w^Tw}}$   

## Hard-margin SVM:
Hard-margin SVM finds an optimal hyperplane to fully separate the two classes of data points with the widest margin, by solving this:
$$min_{w,b}  = \frac{1}{2}\mathbf{w}^T \mathbf{w}  ,y_i (\mathbf{w}^T \mathbf{w} + b) \geq 1 \forall i \in \{1,...,N\} $$   We want to min $\frac{1}{2}\mathbf{w}^T \mathbf{w}$ because we want a big margin and since the margin is $\frac{2}{\sqrt{\mathbf{w}^T \mathbf{w}}}$ , they're equivelent. 
We have two conditions:
- We want to maximise the margin
- The training samples shouldn't exist inside of the margin.
We consider data poins that satisty $y_i (\mathbf{w}^T \mathbf{w} + b)  = 1$. These data points are called **support vectors** because they're the most difficult to classify, and are play an important role on how the hyperplane looks like.

![[Screenshot 2023-05-06 at 16.15.41.png]]

Then becomes a problem of soving each $\lambda _i$  which depends on the number of samples. This problem is called the quardratic progrmaming (QP) problem. The new variables $\lambda _i$ are called the **Lagrangian multipliers**. They woould be positive numbers. 




