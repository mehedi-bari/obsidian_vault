###### Single vector input:
- $\bar{x}$  represents the sample input , also known as a feature vector, and there is a one added at the front to adjust for the bias, this is known as the expanded feature matrix. 
- The$~w~$vector contains the optimal setting of the coefficients (or the weights), with a bias w<sub>0</sub>
![[Screenshot 2023-02-21 at 11.36.15.png]]

###### Multioutput linear Model:
- W contains multiple weights for different linear combinations, which represents the coefficient matrix.
![[Screenshot 2023-02-21 at 11.43.07.png]]
![[Screenshot 2023-02-21 at 11.44.29.png]]
- `X` represents multiple data inputs where each row is a single input.
- `Y` represnts the predicted matrix for all N samples, where each row represnts a sample.
- Using the equation above, you can generate `Y`. 

## Classification by Discriminant Function:
![[Screenshot 2023-02-21 at 11.49.12.png]]

### How do you separate a hyperplane?
![[Screenshot 2023-02-21 at 11.51.50.png]]

![[Screenshot 2023-02-21 at 11.52.13.png]]


#### How about doing it using probability?
- There are two methods logistic regression or softmax function.
![[Screenshot 2023-02-21 at 11.55.08.png]]
- The sum of these need to add up to 1, and when c=2 it is the same as the logistic sigmoid function.
- The logistic sigmoid function is a special case of the softmax function.
- First they're converted to arbitary small positive numbers, and you divide that number by the sum of positive exponential numbers to provide sum sort of scaling.
- The outputs will be between 0 and 1.

 ![[Screenshot 2023-02-21 at 12.02.42.png]]



![[Screenshot 2023-02-21 at 12.23.50.png]]

- We can use a Gausian function.
- The **wTx** repesents the mean, and then you can find the SD and construct a Normal distribution.
- You can set $\sigma$  by setting it as a hyperparameter, or optimise it.
 
