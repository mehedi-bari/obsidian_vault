This part only conterns with non-probabilistic approaches
## Data + Model in Supervised Learning
- After the learning/training is finished the final product is a trained model which if $f(\theta (D_{tr}),x$ ) 
- The process of using the trained model on unseen data (or called query data, test data) is called inference $=>$  $answer = f(\theta(D_{tr}),x_{query})$ 
 
### Loss Function:
- Loss function is essential in training, computed using the training data.
- It decided how good the model paramters are, how well the model fits your training data.
- Other namees: error fucntion, cost fuction etc.
- To train a machine learning model, you pick a loss function $O(\theta)$. Then:
	- Minimise it, if $O$ evaluates how bad the model is.
	- Maximise it, if $O$ evaluates how good the model is.
- Supervised learning: $f(\theta (D_{tr})$  to emphsise it is done using the training data.

#### Non-Probabilitic Regression Loss:
- Some regression losses are simplified verison of RMSE computed using training data.
- The prediction for each training sample is computer by $\bar{y}=f(\theta,x_i)$ 
	- Sum-of-squares error loss: $$O(\theta)=\frac{1}{2}\sum_{n=1}^{N}\sum_{j=1}^{c} (\bar{y}_{ij}-y_{ij})^2$$
		- What this does is calculates the difference between the predicted, with the target output, and squared it.
		- Sum it over different outputs over different samples.
		- The $\frac{1}{2}$ is there for the deriviative
	- Mean-squared error loss: $$MSE = \frac{1}{N}\sum_{i=1}^{N}(\bar{y}_i - y_i)^2$$
		- This is the same as sum-of-squared except $c = 1$

#### A Regression Examples:
![[Screenshot 2023-03-18 at 13.20.23.png]]
- Then work out the sum-of-squares error loss for trianing the linear model (finding the best $w_0$ and  $w_1$)
	$O=\frac{1}{2}[ (\bar{y_1} - y_1)^2  + (\bar{y_2} - y_2)^2 + (\bar{y_3} - y_3)^2 + (\bar{y_4} - y_4)^2 +(\bar{y_5} - y_5)^2 + (\bar{y_6} - y_6)^2]$
        $= \frac{1}{2}\sum_{i=1}^{6}(\bar{y_i}- y_i)^2$
        $= \frac{1}{2}\sum_{i=1}^{6}(w_1x_i + w_0 -y_i)^2$
        $O(w_1,w_2) = \frac{1}{2}[ (5w_1 +w_0 -64)^2 + (6w_1 +w_0 -56)^2 + (12w_1 +w_0 -50)^2 + (9w_1 +w_0 -71)^2 + (15w_1 +w_0 -44)^2 ]$
    We want to then minimise this training loss: $minO(w_1,w_2)$
    ![[Screenshot 2023-03-18 at 13.36.30.png]]
- By doing this we are trying to find a line which minimises squares; this represents its geometic meaning. 

### Linear Least Squares(LLS):
- LLS: It is to train a linear model by minimising the sum-of-squares error.
- In the single output case we 
	 $$minO(w) = \frac{1}{2}\sum_{i=1}^{N}(y_i - w^T\bar{x_i})^2$$
- In the multi-output case we
	  $$minO(w) = \frac{1}{2}\sum_{i=1}^{N}\sum_{j=1}^{c}(y_{ij} - w_j^T\bar{x_i})^2$$
![[Screenshot 2023-03-18 at 13.48.21.png]]
- $\lambda$ is a hyperparameter 
- Regularisation prevents the model from over-fitting to training data.
- When $\lambda$ is too large, it will lead to under fitting.

#### Probabilistic Regression:
- Likelihood: Given the observed data, it is the conditional probability assumed for the observed data given some parameter values:
	- Likelihood($\theta$, data) = $p$(data | $\theta$)
- Log likelihood: Take the natural log of it.
- A model can be trained by maximising the log-likelihood funtion of the training samples.
-  Maximum likelihood estimator(MLE):
	-  for MLE $max_\theta = \Pi_{i=1}^{N}p(x_i, y_i|\theta)$
	- Log-likelihood MLE $max_\theta = \sum_{i=1}^{N}log p(x_i, y_i|\theta)$
![[Screenshot 2023-03-18 at 14.04.54.png]]

- We make some assumptions about the model. We write the probability as a conditional probability. We distribute the data as Gausian, and we set $\mu$ as the predicted output, and also a $\sigma^2$ which is a **hyperparamter**.
- If we try, and find the MLE using the log-likelihood, it results as the same as minimising the sum-of-squares error.

