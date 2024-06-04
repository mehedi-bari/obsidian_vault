Deep learning refers to techniques for learning using neural networks. It is considered as a kind of represenation *feature* learning techniques.

> The main idea is that you would pass in data with features, and you let the neural network generate high-quality features which is created by the representation generator. In classical ML, you would need to process the features, characterise it and create a representation (which is not needed.) This leads to **end to end system** 

There are two types of advanced neural network achitecture:
- Convolutional neural network(CNN) which is used to automatically learn a good feature vector for an image from its pixels.
- Recurrent neural network(RNN) which is useful for learning sequential data Each neuron an use its internal memory to maintain informatioon about the previous input. This makes it suitable for processing natural languages, speech, music etc

**Attention mechansim:** A type of effective mathematical diagrams based on weighted sums, which uses wieght funcitons to locate salient information. You can embed an attention mechanism to a neural network which would help identify **the contributing parts to final decision making.**


#### Training tips of Deep Neural Network:
- Pre-trian: Consider to use a.pre-trained neural network if you data shares some similar structure to existing training data that has been used to train some well-known neural network.
- Batch Normalisation: remove the mean and scale by SD for outputs of hidden layers.
- Regularisation! To avoid overfitting!
- Skip Connection: A type of network connection proposed in ResNet.


## Convolutional Neural Network:
The main receipe of a convoltuional neural network(CNN) includes:
- 2D/3D neurons: The CNN supports layers that have neurons arranged in 2D/3D
- Convolutional Layers
- Pooling Layers
- Fully connected Layers.
Its training is based on backpropagation(chain rule) and stochastic gradient descent.

#### Convolutional Layer:
Local Connectiviity: Each neuron inside a layer is connected to only a small region of the previous layer, called the receptive field.
![[Screenshot 2023-05-09 at 11.21.09.png]]
The output of a neuron is a number ocmputer from the output of those neurones from the corresponding local region, and the weights of hte convoution filter.
Weight sharing: One same filter of the size of the local region slides over all the spatial location.

#### Stride and Output Calculation:
The stride tells you the number to move up, and down by.
The equation below is used to calculate the size of ouptut after passing through the filter. Note: it should be integers.
![[Screenshot 2023-05-09 at 11.31.36.png]]


Same can be done for 3D layers
![[Screenshot 2023-05-09 at 11.37.15.png]]

![[Screenshot 2023-05-09 at 11.39.31.png]]


## Pooling Layer:
The pooling layer takes the activation maps returned by a convolutinoal layer as a the input, and reduces the size of each activation map separately.
It is can viewed as an operation of **down-sampling**.
A pooling filter slides over all the spatical locations in an activation map in the same way as 2D convolutional filter.
![[Screenshot 2023-05-09 at 11.44.19.png]]


## Fully Connected Layer:
![[Screenshot 2023-05-09 at 11.47.43.png]]


## Example
![[Screenshot 2023-05-09 at 11.55.58.png]]