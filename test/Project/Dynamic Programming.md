There are two conditions for Dynamic programming:
- The optimal solution to all subproblems produces the optimal solution to the original problem. We want to pick the policy that maximises in every single state.
- The solutions to the subproblems are mutually dependent. 

We have two main equations:
$$v_*(s)= \max_a \sum_{s',r}p(s',r|s,a)[r+\gamma v_*(s')]$$
$$q_*(s,a)= \sum_{s',r}p(s',r|s,a)[r+\gamma \max_{a'}q_*(s',a')$$
## Value Iteration
If we look at the two Bellman equations it shows that that the current state depends on the next state $s'$ 
DP turns thee into update rules, and have a value table which will have the states:
$$V(s) \longleftarrow  \max_a \sum_{s',r}p(s',r|s,a)[r+\gamma V(s')]$$
However, we need to know in advance how the state changes and what rewards we get from performing each action in each state.
DP solves problems using **expected values** and not trial or error.
We need to find all the states in advance, and it is usually done when the environment is known, and so all the states can be calculated like a rubic cube. 

The first step everything has -1, except the goal. Every iteration it sets a step and sets everything that it has found to a certain value and the others increase. It does this until it has done it for all possible states.

## Policy iteration
A process that alternately improves the estimated values and the policy.
It does this by :
- **Evaluation** of the value, and reflect the values of the present state following the previous values.
- By using the value function we have found we find **improvement**.

**Evaluation**:
This depends on the probability of the policy, whereas the action iteration depends on the probability of the action.
$$V(s) \longleftarrow \sum_a \pi(s|a) \max_a \sum_{s',r}p(s',r|s,a)[r+\gamma V(s')]$$
Each iteration gets close to $v_\pi$ so $v_0 \longrightarrow v_1 \longrightarrow v_2... \longrightarrow v_\pi$ 

**Iteration**:
Does the policy improve the first action?
We need to use the $q_\pi(s,a)$, which finds the expectation for a given state and a given action the return. So for the given state is it better to follow the policy or change action and change the policy to yield a better a state.

So if $q_\pi(s,\pi'(s)) \gt v_\pi(s)$ then $v_{\pi'}(s) = v_\pi(s)$
> So if one of the $q$ values is better than the current state, we will modify the policy to take that state/policy. The new $\pi'$ only differ in the action $a$.

$$\pi'(s)= \max_a \sum_{s',r}p(s',r|s,a)[r+\gamma v_*(s')]$$



