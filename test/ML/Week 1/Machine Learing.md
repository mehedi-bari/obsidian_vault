Data + Model Strategy:
- We try to create a function that provides answers to solutions to task. 
- The objective function is the best function to performance P of task T.
- Then we have the optimisation min O(theta) which is where it tries to maximise the function which is also known as learning/ training. 


What is Optimisation?
- Mathematical Optimisation find the input that can given the minimum(or maximum) output value of a real-valued function.

Example: How to find which wine is a sample between 2 wines?
- Find you may want to go to the chemist and find out the amount of chemicals in each wine
-  Lets say we measure 13 chemicals from 30 bottles, and 15 mottles of each grape.

![[Screenshot 2023-01-31 at 11.12.25.png]]


![[Screenshot 2023-01-31 at 11.14.50.png]]
- The problem then becomes an eror minimisation problem, where we are trying to adjust wi to get the corret values. 


Machine Learning Keys:
- Needs lots of data.
- Create a model with some parameters that need optimisation
- Loss function: The function you use tojudge how well the parametes of the model are set. (called error fucniton/obj function)
- Training Algo: The algorithm that optiises the model paramters, using the error functions.




Supervised Learning:
- The machine learning task of learning a function that maps an input to an output based on input-output pairs.
- So a pair of input data pattern and its target output is called a training example.
- Typicial supervised learning tasks include classification, regression, differeing from their output type.

Unsupervised learning:
- Unsupervised learning is a type of algorithm that learns patterns from untagged data.
- Therefore the system forms a natural understanding of the hidden structure from the unlabelled data.
- Clustering: group similar data patterns together.
- Generative modelling: estimate distributin of the observed data patterns.
- Unsupervised representation learning: remove noise, capture data stats, capture inehrenet data structures.

Reinforcement Learning:
- Reinforcement learning is an area of machine learning concerned with how intelligent agents ought to take actions in an environment in order to maximise the notion of cumulative reward.
- There is a teacher who provides feedback on the actino of an agent, in terms of reward and punishment.

![[Screenshot 2023-01-31 at 11.39.08.png]]


Classification(class output):[]
- The goal is to idendify which categories a data pattern belongs to,
- Training data: Observed data patterns and their category membership.  

Regression(continuous output):
- The goal is to estimate the relationships among the input and the output variables.
- Training data: Observed input variables and their corresponding continuous output variables.

![[Screenshot 2023-02-07 at 09.21.35.png]]


![[Screenshot 2023-02-07 at 09.24.24.png]]


![[Screenshot 2023-02-07 at 09.30.53.png]]

![[Screenshot 2023-02-07 at 09.31.03.png]]

![[Screenshot 2023-02-07 at 09.31.18.png]]

![[Screenshot 2023-02-07 at 09.31.31.png]]

![[Screenshot 2023-02-07 at 09.31.41.png]]