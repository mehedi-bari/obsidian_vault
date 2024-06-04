Temporal Difference (TD) is a family of methods that learn the optimal $v_*(s)$ or $q_*(s,a)$ values based on experience.  It is a combination of Monte Carlo methods as well as DP. 

>We update $Q$ and $\pi$ every time the agent  takes an action. This means the policy evaluation and improvement is always happening during the episode, and not happening at the end. So, improves from the start to the end.

Remember the q equation:
$$q_\pi(s,a) = \sum_{r,s'}p(r,s'|s,a)[r+\gamma \sum
_{a'}\pi(a'|s')q_\pi(s'|a')]$$
$p(r,s'|s,a)$ this is $R_{t+1}$ and $S_{t+1}$ 
$\pi(a'|s')$ is $A_{t+1}$ 

$q_\pi(s'|a')$ is $Q$ from the table which is estimated as $R_{t+1} + \gamma Q(S_{t+1},A_{t+1})$
Then we will compare the two estimates which is known as the temporal difference error  $R_{t+1} + \gamma Q(S_{t+1},A_{t+1}) - Q(S_t,A_t)$

This method uses bootstrapping update equation:
$$Q(S_t,A_t) \longleftarrow (1-\alpha)Q(S_t,A_t) + \alpha[R_{t+1} + \gamma Q(S_{t+1},A_{t+1}-Q(S_t,A_t))]$$

## SARSA (On-policy):
The SARSA name comes the 5 values involved in the update rule: $S_t, A_t, R_{t+1}, S_{t+1}, A_{t+1}$  ... SARSA 
The update rule for this is :$$Q(S_t,A_t) \longleftarrow Q(S_t,A_t) + \alpha[R_{t+1} + \gamma Q(S_{t+1},A_{t+1}-Q(S_t,A_t))]$$The $\epsilon$-greedy policy $\pi$ picks the next action, used to update $Q(S_t,A_t)$ ![[Screenshot 2023-11-10 at 18.44.38.png]]
## Q-Learning (off-learning):
There is a target policy and an exploratory policy($\pi(b)$)
The update rule for this is:$$Q(S_t,A_t) \longleftarrow Q(S_t,A_t) + \alpha[R_{t+1} + \gamma Q(S_{t+1},\pi(S_{t+1})_-Q(S_t,A_t))]$$
Updates of $Q(S_t,A_t)$ are based on the best available action:
$A_{t+1} = \pi(S_{t+1}) = arg \max_a Q(S_{t+1},a)$
![[Screenshot 2023-11-10 at 19.42.38.png]]




# N-step TD
This is the SARSA algorithm:
$$Q(S_t,A_t) \longleftarrow Q(S_t,A_t) + \alpha[R_{t+1} + \gamma Q(S_{t+1},A_{t+1}-Q(S_t,A_t))]$$
Every time we update $Q(S_t,A_t)$  we use the estimate estimate which is $R_{t+1}+ \gamma Q(S_{t+1},A_{t+1})$. This part is known as bootstrapping. We don't have to wait for future rewards, it can be replaced by an estimate! This 1-step bootstrapping

2-step bootstrapping: $R_{t+1} + \gamma R_{t+2} + \gamma^2Q(S_{t+2}, A_{t+2})$ 
3-step bootstrapping: $R_{t+1} + \gamma R_{t+2} + \gamma^2 R_{t+3} + \gamma^4Q(S_{t+4}, A_{t+3})$ 
n-step bootstrapping: $R_{t+1} + \gamma R_{t+2} + ... + \gamma^{n-1} R_{t+n} + \gamma^nQ(S_{t+n}, A_{t+n})$ 

n-step **return** estimate $G_{t:t+n} = R_{t+1} + \gamma R_{t+2} + ... + \gamma^{n-1} R_{t+n} + \gamma^nQ(S_{t+n}, A_{t+n})$ 
Then we can change the update rule:
$$Q(S_t,A_t) \longleftarrow Q(S_t,A_t) + \alpha[G_{t:t+n}-Q(S_t,A_t))]$$


if $n \geq T$ which is where we compute every possible state, then it becomes the **Monte Carlo** method, which is
$$ G_{t:t+n} = G_t = R_{t+1} + \gamma R_{t+2} + ... + \gamma^{n-1} R_{t+n}$$


Therefore N-step TD is the **middle** ground between the Monte Carlo and TD.