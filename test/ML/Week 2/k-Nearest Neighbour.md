K-NN classification:
-  Given a set of training sample, and each point corresponds to a point in the feature space.
- Given a testing data, we can calculate all the possible distances, and order them in ascending order.
- We find  the nearest-k elements, and we assign it based on the most commmon class.

K-NN regression:
- Given a set of training sample, and each point corresponds to a point in the feature space.
- Given a testing data, we can caclulatre all the possible distance, and order them in ascending order.
- We find the average of the nearest-k elements, and we assign it based on the average.

Instance based learning:
- These are algorithms that predict the output based on the simalarity, distance, of the query to the nearest neighbours in the training set.
- This represents the k-NN method.

![[Screenshot 2023-02-09 at 13.40.59.png]]

![[Screenshot 2023-02-09 at 13.43.43.png]]




Effects of small/large training samples:
- The classifcation region produced by a larger training sample is usually more accurate, and provides more information.
- However, this increases the amount of commupational cost needed, which can make it expensive depending on the sample size.
- ![[Screenshot 2023-02-11 at 08.56.07.png]]
- ![[Screenshot 2023-02-11 at 08.57.16.png]]
- There are some regions that are classed inaccurately.


Effects of Noisy Training Sample:
- The two red points cause the red part to be overfit, and causes inaccuracies.
- ![[Screenshot 2023-02-11 at 08.59.05.png]]


Neighbour Number K in k-NN:
- Hyper-parameter: neighbour number k.
- Small k: we may model noise!
- Large k: Neighbours will include too many samples from other classes, which can negatively affect the prediction.
- It will include other samples, which are not involved in the classification of this test. Therefore it makes it unreliable. 

Note there is no explicit training
- This is a non-parametric method; as there is not paramtere to be optimised
- k-NN is non-parametric and instead it has a <b>hyperparamterer<b>, which is the value k from 1 to Z.