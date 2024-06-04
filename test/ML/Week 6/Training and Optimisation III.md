###### Gradient Descent
- Whenever solving the least-squares problem it always forms linear solutions, which makes it very easy to solve.
- An alternative approach when it isn't feasible is using gradient descent(GD.)
	- We start froma random (intial state) of $\Theta,$ and apply a change to the guess.
	- The changed $\Theta$ aims at leading to a reduced value of the objective function.
	- So every iteration we want to have a smaller loss value.
	-  $\Theta^{t+1} = \Theta{t} + change(\Theta^{t})$
![[Screenshot 2023-03-28 at 12.16.30.png]]
- Using the idea of gradients of a function it indicates the direction in which the function ascends the fastest.
- An effective way to set change is $change(\Theta) = -\eta\Delta O(\Theta)$ where $\eta > 0:$ learning rate
	- Align the change with function descending direction, which is the opposite of the gradient
	- Set an appropriate learning rate.
- So the equation then becomes: $\Theta^{t+1} = \Theta{t} + -\eta\Delta O(\Theta^{(t)})$
![[Screenshot 2023-03-28 at 12.24.57.png]]

![[Screenshot 2023-03-28 at 12.26.58.png]]

![[Screenshot 2023-03-28 at 12.28.16.png]]

![[Screenshot 2023-03-28 at 12.29.22.png]]

![[Screenshot 2023-03-28 at 12.29.54.png]]
- The learning rate is too high and it keeps bounching around, and doesn't even find the solution even after `15 iterations`.


### How to apply GD for Least Squares:
- Gradient descent traiing for a least squares model: 
	 $minO(\mathbf{w}) = \frac{1}{2}\sum_{i=1}^N(\widetilde{y}_{i} - y_i)^2$
- We know that the gradient is $\Delta O(\mathbf{w}) = \widetilde{X}^T\widetilde{X}\mathbf{w} - \widetilde{X}^T\mathbf{Y}$
- Then the GD update is $\mathbf{w}^{(t+1)} = \mathbf{w}^{(t)} -\eta(\widetilde{X}^T\widetilde{X}\mathbf{w}^{(t)} -\widetilde{X}^T\mathbf{Y})$  
- $cost = \frac{1}{2n} \sum_{i=1}^{n}(y_i - \mathbf{w}^T\mathbf{x_i})^2$
![[Screenshot 2023-03-28 at 12.37.15.png]]


#### Sequential (On-line Training):
- A learning process that involes the processing of the entire training set can be computationally costly for large datasets.
- Sequential(on-line) trainign updates modle parameters after the presence fo one training (or a small set of training samples)
- A sequntail training process can be derived based on **stochastic gradient descent**
![[Screenshot 2023-03-28 at 12.43.14.png]]

![[Screenshot 2023-03-28 at 12.47.09.png]]
- SGD takes less time, but takes more iterations whereas GD takes more time, but less iterations.
- SGD is computationally much cheaper. $O(M) = M \times T_{m}$

##### Example Time:
![[Screenshot 2023-03-28 at 13.11.16.png]]

![[Screenshot 2023-03-28 at 13.13.45.png]]


![[Screenshot 2023-03-28 at 13.14.10.png]]


![[Screenshot 2023-03-28 at 13.15.05.png]]


![[Screenshot 2023-03-28 at 13.16.24.png]]

![[Screenshot 2023-03-28 at 13.19.28.png]]


![[Screenshot 2023-03-28 at 13.20.07.png]]