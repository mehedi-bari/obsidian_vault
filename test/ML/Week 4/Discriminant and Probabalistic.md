 Assume that we have already found theta, and we have the function for all of these.
![[Screenshot 2023-02-20 at 21.32.58.png]]


## Discriminant Function By Thresholding:
- We focus on binary classification.
- Step 1: construct a real valued f(x)
- Step 2: convert the output to a class prediction by thresholding.
![[Screenshot 2023-02-20 at 21.35.21.png]]

- The real number t can be treated as a hyper-pararameter.
- A common setting t=0/0.5
![[Screenshot 2023-02-20 at 21.35.53.png]]
The contour line can partition the data, which will corresponding postive and negative parts.

##  Classification by Probabilistc Inference
- Model the posterior class probability p(class k| x)
- Find the most likely class: y^ = argmax$_p$(class k| x)
 ![[Screenshot 2023-02-20 at 21.38.53.png]]
#### How do you model the posterior class probability p(class k | x)?

![[Screenshot 2023-02-20 at 21.55.32.png]]

#### What about regression?
![[Screenshot 2023-02-20 at 21.58.30.png]]
- You can model the posterior distribution by using Approach II or III, and then you can find the conditional mean (which is its predicted output.)


### Examples:

![[Screenshot 2023-02-20 at 22.02.52.png]]
- For an input they give you a probability output 

![[Screenshot 2023-02-20 at 22.07.01.png]]
- This returns a probability function, with some level of uncertainty/entropy, which can be used to calculate a probablility.


