In this section, you do we train these weights. We have figured out the number of weights that require training. So, how do we train them?

## Hebbian Learning Rule:
- The weight change is formulated as $\Delta w_{ij} = F(x_i,z_j)$
- The simplest form of the function F is $\Delta w_{ij} = \eta x_iz_j$
$$ neuron_i(x_i) \Longrightarrow (w_{ij})  neuron_j(z_j)$$
- For this neuron:
	- pre-synaptic signal is $x_i$
	- post synaptic signal is $z_j$
	- $w_{ij}$ is the weight
- This can be very **unstable**
To find $w_{ij}$ we take a random guess, like in the gradient descent approach, and after each iteration we add a new change to the top of it from the old $w_{ij}$
$$ w_{ij}^{(t)} =  w_{ij}^{(t-1)} + \Delta  w_{ij}^{(t-1)} =  w_{ij}^{(t-1)} + \eta x_iz_j$$
If $x_i$ and $z_j$ are both postive and both negative, it increases the weight, and if they're both different it redues the weight.

#### Examples:
Apply the Hebbian learning rule to train a two-input one-output single layer perception to simulate $AND$ gate. Update hte weights usign one sample in every iteration with $\eta = 1$.
We only need a single layer perception, because the solution is a straight line.

This is the Hebbian Learning rule(agian):
$$ w_{ij}^{t} =  w_{ij}^{t-1} + \Delta  w_{ij}^{t-1} =  w_{ij}^{t-1} + \eta x_iz_j$$
| Input 1 | Input 2 | Output |
| ------- | ------- | ------ |
| 1       | 1       | 1      |
| 1       | -1      | -1     |
| -1      | 1       | -1     |
| -1      | -1      | -1     |
- Two network weights to decide: $w_{11}, w_{12}$
![[Screenshot 2023-03-31 at 11.46.56.png]]

![[Screenshot 2023-03-31 at 11.52.49.png]]

![[Screenshot 2023-03-31 at 11.59.25.png]]

![[Screenshot 2023-03-31 at 12.01.06.png]]

![[Screenshot 2023-03-31 at 12.03.56.png]]

Note: If you change the order of the table, you will get different results, but at the end you will find the same answer.


## Gradient Based: 
- We treat $z=\varphi(\mathbf{x},W_{NN})$  as the new features, to be used as the input of a linear predictor.
- A loss fucntion is minimised to find the optimal neural network weights $W_{NN}$ together with the weights of the linear predictor $W_P$
- We do the training/optimisation using stocastic gradient descent, or using mini-batch gradient descent.
- This is usually more accurate & stable than Hebbian learning rules in practice.

The training pipeline for this model is:
![[Screenshot 2023-03-31 at 12.10.24.png]]

#### CASE study: Perceptron Algorithm
Trainining a single neuron modle by minimising the perceptron criterion using stochastic gradient descent.
$$ y = \varphi(\sum^d_{i=1}w_ix_i +b)$$
When the activation function is set as the threshld function, the model is still linear, and it is known as the perceptron of Rosenbaltt.
![[Screenshot 2023-03-31 at 16.18.57.png]]


#### The Perceptron Algorithm:
- Update the weight using one sample at a time:
	- you start with random $w$ (weights.) 
	- $y_i$ represents the labels of the misclassified sample.
	- We want to update using a misclassified sample in each iteration.
$$w^{(t+1)} = w^{(t)} +\eta y_i\widetilde{x}_i(*), \eta > 0$$
- An Example Implementation of this is:
```python
Intitalise weights w from frange -1 to 1
for t=1 to NUM_ITERATIONS:
	for each training_sample(x_i,y_i):
		Calculate activation using currect weights in w(t)
		if the ample is misclassified:
			update weights(stored in w(t+1)) by *
```

#### Why?
The **perception criterion** asssesses classification error.
$$O(w) = -\sum_{i\in Misclassified-Set} y_i(\mathbf{w}^T\widetilde{x}_i)$$
>If a sample is correctly classified, applies an error of zero penalty; if incorrectly classified, applies an error penalty of the following quantity: 
>$|y_i(\mathbf{w}^T\widetilde{x}_i)| = -y_i(\mathbf{w}^T\widetilde{x}_i)$

The idea is when training we have to minimise $O(w)$, which is our error function.

The perceptron algorithm can be derived by minimising the perceptron criterion 
computer using the training samples.

#### How do we minimise the error function?
We use a Stochastic gradient descent (SGD) is used to minimise the pereptron criterion.
You've to calculate the error using **one misclassified sample**.
$$O_i(\mathbf{w}) = -y_i\mathbf{w}^T\widetilde{x}_i$$
Then calculate its graident:
$$\frac{\partial O_i}{\partial\mathbf{w}} = -y_i\widetilde{x}_i$$
Then perform the SGD update:
$$\mathbf{w}^{(t+1)} = \mathbf{w}^{(t)} + \eta y_i\widetilde{x}_i$$

![[Screenshot 2023-03-31 at 17.07.29.png]]


