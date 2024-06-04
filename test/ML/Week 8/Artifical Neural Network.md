Artifical neural networks refer to computing systems that are inspired by biological neural network. It is based on a collection fo connected units called a **aritical neurones**. They will try to simulate these 3 important factors:
- Input signals sent from other neurones.
- Connection strengths determines how the singal are accumulated.
- If enough signal accumulate, the neuron fires a signal.

#### Single Neuron Model:
Suppose we get multiple inputs $[x_1,x_2,...,x_d]$ and one output $y$.
For a given neuron, we have modeled it with $d+1$ parameters. 
$$ y = \varphi(\sum^d_{i=1}w_ix_i +b)$$
- This one neuron model is very **similar** to a multi-input and sinlge-output of a linear model; the only difference is there an **activation function**.
- A set of synapses or connection. Each of these is characterised by a **weight**.
- An **adder** is there to sum up the strength.
- An **activation function**, which squashes the permissible amplitude range of the output signal.

#### Activation Functions:
![[Screenshot 2023-03-30 at 15.45.53.png]]
The model you should can also be tested

###### Single Layer Perception(SLP):
A **Single Layer Perception(SLP)** ihas one input layer and output layer.
A  SLP is simlar to a multi-input multi-output linear model.
![[Screenshot 2023-03-30 at 15.50.25.png]]

###### Adding Hidden Layer!
- The presence of hidden layers allows to formulate more ocmplex that are nonlinear 
- Each hidden node finds a partial solution to the problem to be ocmbined in the next layer.
![[Screenshot 2023-03-31 at 10.44.56.png]]


###### XOR Example:
Consider the XOR problem as an example:
![[Screenshot 2023-03-31 at 10.47.55.png]]

Each of the hidden nodes above, finds a partial solution to the problem. 
Then, the output node combines the **two partial solution** and makes the probelm separable.
![[Screenshot 2023-03-31 at 10.48.18.png]]

You can also add more and more layers to increase the complexity around the decision boundary.
![[Screenshot 2023-03-31 at 10.50.10.png]]

### Multilayer Perceptron:
A multilayer perceptron(MLP), aslo called **feedforward aritifical neural network**, consists of at least three layers of nodes: input, hidden layer(at least one), and output layer.
![[Screenshot 2023-03-31 at 10.54.07.png]]

An Example:
![[Screenshot 2023-03-31 at 11.04.36.png]]
It has 9-4-2 archiecture!

#### MLP Mapping Function I
- MLP with 1 input and 1 output, usinga sigmoid activation is used in the output layer.
- Sigmoid activation in all hidden layers.
-  Random weights.
![[Screenshot 2023-03-31 at 11.08.25.png]]
- By changing the number of hidden layers, and the number of hiddern neurons it changes the mapping structure drastically. 
#### MLP Mapping Function II:
- MLP with 1 input and 1 output, usinga sigmoid activation is used in the output layer.
- ReLu in all hidden layers.
-  Random weights.
![[Screenshot 2023-03-31 at 11.10.18.png]]


### Powerful Mapping Function & Methodology:
- From the input to  the last hidden layer: a powerful non-linear mappingg function generating a new and better features. 
- So it can be considered as a feature extractor similar to the kernal method, non-linear basis functions etc.
- In supervised learning, the output layers as a linear predictor that takes the new features an the input, thus it is also called the prediction layer.
![[Screenshot 2023-03-31 at 11.17.02.png]]


#### Example:
Suppose we have a MLP for Handwritten Digit Recognition:
It is $28\times 28$  which is $784$ pixels in total. 
![[Screenshot 2023-03-31 at 11.20.56.png]]
$16 \times 784 + 17 \times 16 17 \times 10 = 129986$ 

