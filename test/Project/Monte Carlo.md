Family of methods that. learn optimal $v_*(s)$ or $q_*(s,a)$ values based on **samples**. At the beginning will use a policy $\pi$ to tackle the task for an entire episode.

Using the value methodology, which returns the the expectation given a state $s$:
$v_\pi(s) = \mathbb{E} [G_t | S_t =s]$, and at the end of episode we will calculate the returns, $G$, 
$G_t = \sum ^{T-t-1}_{k=0} \gamma^k R_{t+k+1}$.  Then out **expected return** becomes $v_\pi = \frac{1}{N}\sum^N_{k=1}G_{s_k}$   

Using the q methodology, which returns the expectation given a state $s$ and action $a$: $q_\pi(s,a) = \mathbb{E}_\pi[G_t|S_t=s,A_t=a]$ and $G_t = \sum^{T-t-1}_{k=0} \gamma^k R{t+k+1}$, and then we can combine it with $Q_\pi(s,a) = \frac{1}{N} \sum^N_{k=1} G_{s,a_k}$

By the LLN, as $n \longrightarrow \infty$ and converges towards 1.
Advantages over DP:
- The estimate of a state value doesn't depend on the rest.
- The cost of estimating a state value is independent of the total number of states.

Use these return to update the value function and through it, the policy $\pi$ 
$G_t = R_{t+1} + \gamma R_{t+2} + \gamma^2 R_{t+3} + ... + \gamma^{T-t-1} R_{T}$
$G_{t+1} = R_{t+2} + \gamma R_{t+3} + \gamma^2 R_{t+4} + ... + \gamma^{T-t-1} R_{T}$

To improve the policy we cannot depend on $v(s)$ which requires the states on the next state, $s'$ and their expected rewards:
$$\pi'(s)= \max_a \sum_{s',r}p(s',r|s,a)[r+\gamma v_*(s')]$$
Instead we will choose the value with choose the value that will take the one with highest return for a given action, which is exactly what a q-value is:
$$q_(s,a)= \sum_{s',r}p(s',r|s,a)[r+\gamma v_(s')]$$
We will change the policy to take the action with the highest $q_\pi(s,a)$  which is exactly the same as: $\pi'(s) = arg \max_a q_\pi(s,a)$ 
Instead of a table of $V(s)$, we have a table of $Q(s,a)$ 

>The policy iteration methodology:
	$\pi_o \longrightarrow Q_{\pi_0} \longrightarrow \pi_1 \longrightarrow Q_{\pi_1} \longrightarrow ...  \longrightarrow Q_{\pi_*} \longrightarrow \pi_*$ 
	If action $a$ is optimal but has a bad estimate $Q(s,a)$ we will never pick it.
	The only way to avoid this is to explore all action every once in a while and update their $Q(s,a)$ estimates.
	The best way is to use stochastic policies where $\pi(a|s) >0$ , $\forall a \in A(s)$ 

Stochastic policy:
**On-policy learning**: Generates samples using the same $\pi$ that we're going to optimised
**Off-policy learning**: Generates samples with an exploratory policy $b$ different from one one we're going to optimise.


## Epsilon-Greedy policy
This is an on-policy strategy:
We will give a probability of $\epsilon$ select a random action. 
With probability 1-$\epsilon$ select the action with the highest $Q(s,a)$ 
So, $\pi(a|s)$  = $1 - \epsilon + \epsilon_r$, when a = $a*$  or $\epsilon_r$ when $a \neq a^*$  
where $\epsilon_r = \frac{\epsilon}{|A|}$ 
![[Screenshot 2023-11-09 at 11.54.12.png]]
![[Screenshot 2023-11-09 at 11.58.06.png]]


## Off-policy strategy
We have two policy: main and exploratory policy. The main policy is optimised on its own, but if there are extra gains to be made by using the exploratory policy, it will use that to form the new policy.
The new policy $b$ has to be able to explore all the actions that $\pi$ it can take. So, if $\pi(a|s) \gt 0$, then $b(s|a) \gt 0$. This is because the main policy has a probability greater than 0, and if the exploratory policy is 0, then it will not explore it any further.

The average return will not approximate the value under $\pi$ but under $b$:
$$ \mathbb{E_b}[G_t=s,A_t=a] = q_b(s,a)$$
We will apply a statistical technique which is used for estimating the expected values of a distribution by working with samples from another distribution:
$$W_t = \prod^{T-1}_{k=t} \frac{\pi(A_K|S_K)}{b(A_k|S_k)}$$
By correcting the returns using the importance sampling, we will approximate the value under $\pi$:
$$\mathbb{E}[W_tG_t|S_t=s] = v_\pi(s)$$
The update rules are:
- For each $Q(s,a)$ we will keep a list of observed values,, and then compute the average of each time we need to update $Q(s,a)$ 
- The better way is to use this update rule:
$$Q(s,a) \longleftarrow Q(s,a) + \frac{W_t}{C(s,a)[G-Q)s,a]}$$
where $C(s,a) = \sum^N_{k=1} W_k$ 




