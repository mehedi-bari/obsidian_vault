Backpropagation is the method of **calculating the gradient of the loss function** with respect to layers of the neural network weights.
It uses the **chain rule** to iteratively compute the gradient for each layer.

## Loss and Regularisation:
- After choosing a loss function $Loss(W_{NN})$ a regularisation term, e.g. the sum of all the squared weights, is addded to the final optimisation objective function for training:
$$O(\mathbf{W}_{NN}) = loss(\mathbf{W}_{NN}) + \lambda\frac{1}{2}||\mathbf{W}_{NN}||^2_2$$
- This is called $l_2$ regularisation (**hyperparameter**). The regularisation term plays the asme role as in the rgularised least squares model.

## Backpropagation Illustration:
We have our original function $z=\varphi(\mathbf{x},\mathbf{W}^{(h_1)},\mathbf{W}^{(h_2)},\mathbf{W}^{(h_3)})$ 
Our loss function is then $O(z,\mathbf{W}_p)$, which is equivalent of writing it as: $O(x,\mathbf{x},\mathbf{W}^{(h_1)},\mathbf{W}^{(h_2)},\mathbf{W}^{(h_3)})$.

![[Screenshot 2023-03-31 at 17.30.19.png]]
To explain this, there are orginaly $\mathbf{x}$ features, and during the first layer function $\mathbf{z}^{(h_1)}$ it takes $\mathbf{x}$  and $\mathbf{W}^{(h_1)}$ the weights, as input. Then in the second layer function $\mathbf{z}^{(h_2)}$ it takes the inputs from $\mathbf{z}^{(h_1)}$, its features and its $\mathbf{W}^{(h_2)}$ the weights etc.

![[Screenshot 2023-03-31 at 17.39.44.png]]


### Examples:
![[Screenshot 2023-03-31 at 17.41.37.png]]


![[Screenshot 2023-03-31 at 17.44.49.png]]![[Screenshot 2023-03-31 at 17.44.57.png]]