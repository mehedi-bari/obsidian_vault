## Linear Basic Function Model:
- You can make a non-linear function that are called basis function. Each can be viewed as a feature extractor.
- It extracts a f feasture for each sample
![[Screenshot 2023-03-18 at 08.49.35.png]]
- Then we apply a linear modle to the mapped featured to get:
![[Screenshot 2023-03-18 at 08.50.35.png]]

###### Gausian Basis Function:
- $\mu$  is predermined
![[Screenshot 2023-03-18 at 08.52.29.png]]

###### Polynomial Basis Function:
![[Screenshot 2023-03-18 at 08.55.38.png]]

##### Examples:
![[Screenshot 2023-03-18 at 09.08.32.png]]

![[Screenshot 2023-03-18 at 09.09.51.png]]


###  Kernal Methods:
- You don't compute the feature function directly using the Kernal Method.
- The Kernal methods uses variations of the inner product.
- The Kernel trick avoids to directly define the map function $\phi$($x$), but defines the innner product function in the new space using a kernel function: ![[Screenshot 2023-03-18 at 09.14.48.png]]
![[Screenshot 2023-03-18 at 09.15.17.png]]

### Express a function by an induced kernel:
- It is a function that takes the data to a new feature space induced by a kernal, and compute the dot product.
- 
![[Screenshot 2023-03-18 at 09.22.56.png]]

![[Screenshot 2023-03-18 at 09.28.15.png]]

- You need to train $a$ and $w$  and it becomes a linear combination, similiar to the linear case.


