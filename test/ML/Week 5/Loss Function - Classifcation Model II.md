This part only consider probablistic approches.
## Cross Entropy for single class:
- Cross Entropy measure distance between probability distributions.
- Its discrete version can us used to examine the distance betweeen the predicted class proabilites(_posterior_) and the _true probabilities._
	- $H(p,q)=-[p(1)log(q(1)) + p(0)log(q(0))]$ (two classes)
	- $H(p,q) = -[p(1)log(q(1)) + p(2)log(q(2)) + .... + p(c)log(q(c))]$ (multiple classes)
-  0/1 label coding for a smaple ($\mathbf{x},y$)
	- If $y = 1, x$ is from _class 1_ which means that $p(0)= 100$% and $p(0) = 0$%
	- If $y = 0, x$ is from _class 1_ which means that $p(0)= 0$% and $p(0) = 100$%
	- Therefore, $p(1)=y$ and $p(0) = 1-y$
- Cross entropy loss comptuer over $N$ training samples is:
  $O = -\sum_{i=1}^{N}[y_i\log_b(c_1|\mathbf{x_i})) + (1-y_i)\log_b(c_2|\mathbf{x_i}))]$  where $b = ln/ base 2$ 

## Cross Entropy for Multi-class:
- Multi-class cassification $y_{ik}$ means that the $i^{th}$ sample belongs to the class k, $y_{ik} = 0$ otherwise.
![[Screenshot 2023-03-20 at 14.49.48.png]]
- Cross entropy loss is computed over N training samples over **c** different classes  is: $O=-\sum_{i=1}^N\sum_{k=1}^cy_{ik}\log_b(p(c_k|(\mathbf{x}_i))$

**Notes**:
- Different models give you different ways to formulate $p(c_k|\mathbf{x})$
- Logistic regression:  A linear classification model trained using cross-entropy loss.


### Likelihood Maximization for Classification:
One way to train the model is to maximise the likelihood (or log likelihood) function.

- Binary classification: Assume the class label follows a Bernoulli Distribution
![[Screenshot 2023-03-20 at 15.01.04.png]]


- Multi-class classification: Assume that the follows categorical multinormial distribution.
![[Screenshot 2023-03-20 at 15.01.21.png]]


### Likelihood of a i-th / N training sample:
Consider the i-th training sample ($\mathbf{x}_i ,y_i$)
For binary classifcation you get: $p(\mathbf{x}_i,y_i | \theta) = \theta(\mathbf{x}_i)^{y_i}(1-\theta(\mathbf{x}_i))^{y_i}$ 
Multi-class classification: Assume that the class label follow a categorical multinomial distribution: $p(\mathbf{x}_i,y_i | \theta) = \prod_{k=1}^c\theta_k(\mathbf{x}_i)^{y_{ik}}$   

Consider for $N$ training samples:
Binary Classification is $L = \sum_{i=1}^N p(\mathbf{x}_i,y_i | \theta) = \sum_{i=1}^N \theta(\mathbf{x}_i)^{y_i}(1-\theta(\mathbf{x}_i))^{y_i}$ 
Likewise Multi: $L = \prod_{i=1}^N  p(\mathbf{x}_i,y_i | \theta) = \prod_{i=1}^N\prod_{k=1}^c\theta_k(\mathbf{x}_i)^{y_{ik}}$
![[Screenshot 2023-03-20 at 15.19.55.png]]

This gives you a value for $\theta(x)$ between 0 and 1.

### Negative Log-liklihood Loss
If we want to minimise loss, wer can use the negative log-likelihood. The negative log-likelihood being minimised is the same as the minimisation of cross-entropy. 

![[Screenshot 2023-03-20 at 15.27.10.png]]

![[Screenshot 2023-03-20 at 15.32.32.png]]

