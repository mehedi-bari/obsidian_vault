We can use the sum-of-squares loss for classification too.
#### Least Squares for Single Binary Classification:
- We have binary classification: +1/-1 lablel coding.
	- where $y = 1$ _class A_ and $y = -1$ _class B_
- You need a discriminant function: $\widehat{y} = 1, f(x) \geq 0$  || $-1,f(x)\leq0$
- We have to minimise the sum-of-squares loss in training (_N_ training samples):
	- $O(\theta) = \frac{1}{2}\sum_{i=1}^{N}(f(x_i)-y_i)^2$
	- We wish our prediction to return close to +1 for _class A_ and -1 for _class B_

#### Least squares for Multi-Class Binary Classification:
- Mutli-class classification: +1/-1 label coding
	- $y_{ij} = 1$ the $i^{th}$ sample is from the $j^{th}$ class.
	- $y_{ij} = -1$ the $i^{th}$ sample is NOT from the $j^{th}$ class.
- We have to minimise the sum-of-squares loss in training (_N_ training samples):
	- $O(\theta) = \frac{1}{2}\sum_{i=1}^{N}\sum_{j=1}^{c}(y_{ij} -f_j(\mathbf{x}_i))^2$ 	
	- We wish our prediction to return close to +1 for _class A_ and -1 for _class B_ for every $j$
![[Screenshot 2023-03-18 at 16.19.49.png]]


#### General Configurations:
![[Screenshot 2023-03-18 at 16.23.16.png]]

- Theoretically, you can choose any number for $a$ and $b$ as long as $a \neq b$ 
- In reality, for some data, the performance can be sensistive to the choice of $a, b$ 
- Usually we choose $a = + 1$ and $b = -1$  ||   $a = 1$  and $b = 0$
- Usually we use fixed threshold as $T = \frac{a+b}{2}$ . For example, $a = 1$, $b = -1$ then $T = 0$ or $a = 1$, $b = 0$ then $T = 0.5$
- Sometimes, the threshold $T$ is treated as a hyperparamter to tune.


### Hiinge Loss for Classification:
- Hinge loss assesses clasification error.
- Given +1/-1 $\mathbf{label coding}$, hinge loss over $N$ training samples
- We have our class labels which $y_i\in$ {${-1,+1}$}, with the prediction model: $f(\theta,x_i)$
- Then we can use the hinge loss function $O(\theta) = \sum_{i=1}^{N}max(0,1-y_if(\theta,x_i))$ to minimise the error loss
- If you set $a = y_if(\theta,x_i)$ then you get a graph:
![[Screenshot 2023-03-18 at 16.39.14.png]]

- If $a\geq 1,$ then it is equal to $0$
- If $a\leq1,$ then it is a positive number.
- The main aim of the hinge loss fuction is to get everything close to 0, which means there is no error
- Therefore to get 0, we need it to greater than 1. There are two possible ways:
	- If $y_i=1$ , then we want  $f(\theta,x_i)\geq{1}$ which mens the hince loss function will be 0.
	- If $y_i=-1$ , then we want  $f(\theta,x_i)\leq{-1}$ which mens the hince loss function will be 0.
- If $0\leq a < 1$ it is not too large, we have a small error, and it lowers our confidence.
- If $a\leq 0$  means that there is a very large error, not we are not very confident with our model.
You can also add a **regularisation** term to the loss. This results in  support vector machine.
![[Screenshot 2023-03-18 at 16.52.30.png]]
$min C\sum_{i=1}^{N} max(0,1-y_i(w^Tx_u +w0)) +  \frac{1}{2}w^Tw$   
  
### Example of Hinge Loss for Binary Classification:
A linear bassis function function model is trained to return the following prediction for the 3 samples:
![[Screenshot 2023-03-18 at 16.54.16.png]]
$O = max(0,1-1\times10) + max(0,1-1\times0.9) +max(0,1-(-1)\times0.1)$
$O= 0 + 0.1 + 1.1 = 1.2$


The hinge loss function is given by:
![[Screenshot 2023-04-26 at 10.43.39.png]]
where $\theta$ is the vector of parameters, $y_i$ is the true label of the $i$-th sample, $x_i$ is the feature vector of the $i$-th sample, and $f(\theta, x_i) = \theta^T x_i$ is the linear prediction.

The goal is to find the gradient of the hinge loss function with respect to the $i$-th component of $\theta$. To do this, we can use the chain rule. First, we need to rewrite the hinge loss in terms of $\theta$ as $f(g(\theta))$, where $g(\theta) = x_i^T \theta$ and $f(z) = \max(0, 1 - y_i z)$.
x
Next, we can apply the chain rule to get:
![[Screenshot 2023-04-26 at 10.44.09.png]]
Now, we need to evaluate each of these terms separately.

First, let's evaluate $\frac{\partial f(g(\theta))}{\partial g(\theta)}$. Using the definition of the $\max$ function, we can write:
![[Screenshot 2023-04-26 at 10.44.29.png]]

Thus, we can write:
![[Screenshot 2023-04-26 at 10.44.45.png]]

Substituting $g(\theta) = x_i^T \theta$ and $z = g(\theta)$, we get:

![[Screenshot 2023-04-26 at 10.45.55.png]]
Next, let's evaluate $\frac{\partial g(\theta)}{\partial \theta_i}$. Since $g(\theta) = x_i^T \theta$, we have:
![[Screenshot 2023-04-26 at 10.46.04.png]]
where $x_{i, j}$ is the $j$-th component of the $i$-th feature vector.

Substituting these two expressions back into the chain rule, we get:
![[Screenshot 2023-04-26 at 10.46.24.png]]

Since this expression is defined for each $i$ and $j$, we can write it in vector form as:
![[Screenshot 2023-04-26 at 10.46.37.png]]