#### Optimality Condition:
Our goal is to optmise the loss function e.g. $minO(\theta_1,\theta_2,...,\theta_m)$
Optimisation theory tells us that the optimal $\theta =(\theta_1,\theta_2,...,\theta_m)$. This is called the gradient vector.
Therefore each one of the partial derivative of the objective function with respect to the input variable sould be set as zero.

#### Linear Least Squares: Single Output:
-  Apply the linear mdoel to training samples: $\widehat{y_i} = \mathbf{w}^T\widetilde{x_i}, i=1,2, ...N$
- Calculate the sum-of-squares error loss:
$$O(w)=\frac{1}{2}\sum_{i=1}^N(\widehat{y_i}-y_i)^2 = \frac{1}{2}\sum_{i=1}^N(\mathbf{w}^T\widetilde{x_i} - y_i)^2 = \frac{1}{2}\| \widetilde{X}\mathbf{x-y} \|$$
-  This need to equal to 0 in the most ideal case.
 ![[Screenshot 2023-03-28 at 10.01.52.png]]

#### Linear Least Squares: Multi -Output:
-  Apply the linear mdoel to training samples: $\widehat{y_i} = \mathbf{W}^T\widetilde{x_i}, i=1,2, ...N$
- Calculate the sum-of-squares error loss:
$$O(w)=\frac{1}{2}\sum_{i=1}^N \sum_{j=1}^c(\widehat{y_{ij}}-y_{ij})^2  = \frac{1}{2}\| \widetilde{X}W - \mathbf{Y} \|$$
	 - This needs to equal 0 in the most ideal case
![[Screenshot 2023-03-28 at 10.07.03.png]]

## How does this follow on?
- If the minimal error of zero can be achieved, it is equivalent to solving the following linear systems:
	- Single-output case: $\widetilde{X} \mathbf{w=y}$
	- Multi-output case: $\widetilde{X}\mathbf{W = Y}$
- When there are more training samplesa than input features (N>d), then the system is overdetermined.
- If $\widetilde{X}^T \widetilde{X}$ is invertible, then there is a unique solution.
- We usually use **normal equations** to find the solution.

### Normal Equations (overdetermined N>d):
- The gradient function being equal to zero is the same as:
$$\Delta O(\mathbf{w}) = \widetilde{X}^T \widetilde{X}w - \widetilde{X}^T \mathbf{Y}$$
- You can re-express the gradient in an equivalent form:
	$\Delta O(\mathbf{w}) = \sum_{i=1}^N(\widetilde{x_i}\mathbf{w} - y_{i})\widetilde{x_i}$   
- It is easy to see that the term carries the error information for each training sample

- Then we apply the optimality condition: set the gradient equalt to zero:  $\Delta (w) = 0$
	$\Delta O(\mathbf{w}) = \widetilde{X}^T\widetilde{X}\mathbf{w} - \widetilde{X}^T\mathbf{Y} = 0 \Rightarrow \mathbf{w} = (\widetilde{X}^{T}\widetilde{X})^{-1}\widetilde{X}^T\mathbf{Y}$ 
- For multi-output: 	$\Delta O(\mathbf{W}) = \widetilde{X}^T\widetilde{X}\mathbf{W} - \widetilde{X}^T\mathbf{W} = 0 \Rightarrow \mathbf{W} = (\widetilde{X}^{T}\widetilde{X})^{-1}\widetilde{X}^T\mathbf{Y}$ 

This equation is known as the **normal equation** for the least squares problem, and only works when **N>d**

### Normal Equations (underdetermined N<d):
- When there are less training samplesthan input features (N<d), the system is underdetermined.
- Whe $\widetilde{X} \widetilde{X}^T$ is invertible, there are infinitely many solutions, and we want to use the one with the minimum norm, where the **$l_2$ norm/frontier's norm** is the smallest ,which is:
	- single output case: $\mathbf{w} = \widetilde{X}^T(\widetilde{X} \widetilde{X}^T)^{-1}\mathbf{y}$ 
	- multi-output case: $\mathbf{W} = \widetilde{X}^T(\widetilde{X} \widetilde{X}^T)^{-1}\mathbf{Y}$

###### Some notations:
- The quantity of $(\widetilde{X} \widetilde{X}^T)^{-1}\widetilde{X}^T$ and $\widetilde{X}^T(\widetilde{X} \widetilde{X}^T)^{-1}$ are called **Moore-Penrose inverse** are called pseuudoinverse of $\widetilde{X}$
- Regardless of the sample size and feature size, we can unfify the solution.
	- Single output case: $\mathbf{w} = \widetilde{X}^{\dagger}\mathbf{y}$ 
	- Multi-output case: $\mathbf{W} = \widetilde{X}^{\dagger}\mathbf{Y}$   
- You can calculate the pseudo inverse of a matrix using readily implemented library **numpy.linalg.pinv**

![[Screenshot 2023-03-28 at 11.14.45.png]]

#### l2-Regularised Least Squares:
![[Screenshot 2023-03-28 at 11.17.09.png]]

### Hyperameter $\lambda$
- It controls the balance beween the data dependent error function adn the regularisation term.
- To distringuish it form those  model parameters to be optimised during the lerning process(e.g. $W$), $\lambda$ is referred to as a hyperparamterer.

### Training, validation and testing:
- Training set: A set of samples used for learning, that is to optimise the model paramters.
- Validation set: A set of samples used to select(tune) the hyperparameters.
- Test set: A set of samples used only to assess the perofrmance of a fully-specified classifier (trained with selected hyperparameters.)



