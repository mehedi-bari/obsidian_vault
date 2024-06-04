**Hypotheiss**: predicition made by a trained machine learning model.
**Sample error** of a hypothesis(error s): Error computed by a performance metric using a set of data samples.
**True Error** of a hypothesis (error d): For classification iti sthe probability that a single sample if misclassifed where the sample is randomly drawn from a distribution.
> For regression case, it is the expecation of the error

![[Screenshot 2023-02-13 at 22.12.46.png]]

Given the limited data, you wil probably encounter hte following issues, caused by the gap between the true and sample erros.

Bias Issue
- Accuaracy of the training samples can be a poor estimators of the accuracy of the unseen samples.
- It can provide optimisically biased estimate of the hypothesis over future unseen examples.
- It is naturallly going to biased towards the sample data.
- To deal with the bias issue, it is better to choose a new set of test examples independent of the training examples.

Variance issue:
- Accuracy of a new set of test samples can still vary form the true accuracy depending on the makeup of a particualr set of test samples.
- Smaller set of test samples can result in higher variance.


![[Screenshot 2023-02-13 at 22.28.07.png]]
Disadvanatages:
- sample error doesn't equal to the true error.
- if the dataset is small, we may not be able to set aside a portion of the dataset for testing.

Random Sampling:
- Perform K data splits of the entire dataset.
- Each split randomly selects a fixed number of samples for testing, and then uses the remaining samples for training.
- For each data split, the classifier is trained from scratch using the training samples, and its error rate is estimated with the testing samples (donted by Ei for the i-th split.)
- Then the average error is calculated with the K samples.![[Screenshot 2023-02-13 at 22.31.05.png]]
- Dis: There's a chance you can select the same sample, and testing data.


K-fold Cross Validation:
- Divide the entire dataset into K partitions.
- For each of the K experiments, use (K-1) experiements for training and the remaining one for estimating the error rate Ei.
- Ad: all the examples in the dataset are eventually used for both for training and testing
![[Screenshot 2023-02-14 at 10.20.14.png]]

![[Screenshot 2023-02-13 at 22.44.50.png]]

Leave One Out:
- Leave one out(LOO) is a special case of K-fold CV.
- We have a single sample for testing, and the rest are training samples.
- You use a different sample for testing every single time.
- LOO is an N-fold cross validation.![[Screenshot 2023-02-14 at 10.12.39.png]]

Bootstrap:
- Boostrap is sampling based on replacement.
- Repeat the follwoing process K times:
	- Randomly select(with replacement)  M samples and use these for training.
	- The remaining samples that were not selected are for testing.
	- The number of testing samples can change over repeats.
	- ![[Screenshot 2023-02-14 at 10.23.23.png]]



Maching Learning Experiments:
- A complete machine learning experiment includes:
	- Model training
	- Model evaluation
	- Model selection: select a best model among differerent options (also known as hyper-paraeter selectino, model selection.)
- Do not train, assess and selet the hyper-parameters using the same data.
- You split the data for training, and testing data.
- The data for training is then split depending on what sort of experiment you're doing. 
- Test the different models, and calculate the different error rate, and the model is selected with the min error rate.
- The Final Model can be re-trained using all the training data, and then finally tested with testing data to calculate its performance.

![[Screenshot 2023-02-14 at 10.48.05.png]]


![[Screenshot 2023-02-14 at 10.51.23.png]]



![[Screenshot 2023-02-14 at 10.59.21.png]]

![[Screenshot 2023-02-14 at 11.01.16.png]]

