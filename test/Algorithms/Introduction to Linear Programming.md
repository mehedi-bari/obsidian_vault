Linear Programming is an algorithm that allows you to find the optimal value for some algebraic expression while following a system of constraints. For example:

> A farmer has a field of size $A$ square metres. He wants to know how much barley he should plant ($x_b$) and how much wheat he should plant ($x_w$) in order to maximise profit. The sale price of one square metre of barley is $S_b$, and the sale price of one square metre of wheat is $S_w$

Therefore, in this case the objective of the problem is to maximise the total sale price of both crops, i.e. to maximise $S_bx_b + S_wx_w$. This is subject to some constraints; he only has $A$ square metres of field to plant in. Therefore, $x_b + x_w$ ≤ $A$

These constraints can be represented as this: $F_bx_b + F_wx_w \leq F$ where $F$ is the total amount of fertilser he has. $P_bx_b + P_wx_w \leq P$ where $P$ is the total amout of pesticide he has. 

Therefore this entire problem can be expressed using the 4 equations. Notes: any linear programming problem can be expressed as linear relationships. The constraints are inequalities (always ≤), and all variables must be greater than or equal to zero.


## Visualising as a Graph

This problem, having two variables, can be represented as a graph. This may be helpful for envisioning the problem, though you'd never do this in practise. Lets take the problem for some arbitrary values:
$A=4, F=P=30, F_b=2,F_w=10,P_b=10,P_w=2,S_b=5,S_w=4$  
Then plugging them into the equation you get:
Maximise $5x_b + 4x_wx_b \leq 4, 2x_b+10x_w \leq 30, 10x_b+2x_w \leq30$ (and implicitly $x_b, x_w \geq 0$     

If you take $x_b$ and $x_w$ as the two axes of the graph, you can plot the constraints as lines, with the exclusive area (or the inclusive area, if you like) shaded in. In this graph, $x_b$ is horizontal and $x_w$ is vertical: 
![[Screenshot 2023-03-28 at 14.55.07.png]]

The red line on this graph is **the formula that you are trying to maximise**. The optimal value of the formula is the value for which the line is touching just one point of the constraints.

## Standard Form
To express this problem in standard form: Maximise: 5��+4�� Constrained by: ��+��≤4 2��+10��≤30 10��+2��≤30 And: ��,��≥0 The function you are maximising is called the **Objective Function**. Another way to say "constrained by" would be "subject to", i.e. "Maximise the objective function subject to these constraints".

For example, let's convert this problem to standard form: 
![[Screenshot 2023-03-28 at 15.12.37.png]]

Implicitly, you can tell the objective is to maximise the council's approval rating. This can be given by: $6x_{sr}+3{x_h}+1x_{sc}$.  As for constraints, the council has a budget of £300,000 so we must limit the amount of money spent:$10,000x_{sr}, +10,000x_{h} +10,000x_{sc} \leq{300,000}$  which you can simplify down to:  $x_{sr}+{x_h}+x_{sc} \leq 30$. 

The government requires they spend at least £10,000 pounds on homelesssness, and social care: $10,000x_h + 10,000x_{sc} \geq 100,000$
We have to simplify and then convert this one to use a greater than or equal to: $x_h +x_{sc} \geq 10, -x_h -x_{sc} \leq -10$ And we have to say that these variables are non-negative: $x_{sr},x_{h},x_{sc} \geq 0$ 

The final problem is this: 
	Maximise: $6x_{sr}+3{x_h}+1x_{sc}$
	Constraints: $x_{sr}+{x_h}+x_{sc} \leq 30, -x_h -x_{sc} \leq -10$ 
	And: $x_{sr},x_{h},x_{sc} \geq 0$ 

Here is another example, watch the video for the full explanation: [![](https://github.com/coop152/obsidian-vaults/raw/main/Algorithms%20and%20Data%20Structures%20(26120)/Semester%202/Pasted%20image%2020230228134650.png)https://login.manchester.ac.uk/cas/login?service=http%3A%2F%2Fvideo.manchester.ac.uk%2Flogin%2Fcas%2Fj_spring_cas_security_check
![[Screenshot 2023-03-28 at 15.28.36.png]]
Option 1:
- Since you are minimising the cost, you could say that the weight of the meatloaf should be 1, since we are trying to minimise the cost.
 ![[Screenshot 2023-03-28 at 15.30.42.png]]
Option2:
- Since we know the weight we can work with $0.25$ of the total weight of beef and pork.
![[Screenshot 2023-03-28 at 15.34.09.png]]


## Matrix Representation

A linear programming problem can also be represented as a matrix.![[Screenshot 2023-03-28 at 15.38.19.png]]