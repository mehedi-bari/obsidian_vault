Reinforcement learning is learning from an unknown **stochastic environment.** Reinforcement learning is inspired by animal learning, where **agents**, like a mouse, learn by interacting with their environment to receive rewards. It works by taking AI agents and putting them in an environment, and take actions, and as a result of these action it is rewarded. 

It merges concepts from computer science, neuroscience, economics, and mathematics to develop algorithms that maximise long-term rewards.

In reinforcement learning, the algorithm makes **predictions*** about the expected future cumulative reward. Those predictions should be **consistent**. Errors are computed between predictions made at consecutive time steps.

#### Computational Framework:
- At each time $t$, the agent perceives the **state** of the environment.
- Based on the perception, it chooses an **action**.
- The action leads to a numerical **reward**.
- There is also the environment like for pac-man, it is the ghosts, maze and food.
- Find a way of choosing actions, called a **policy** which **maximises the agent's long-term expected return.**

## Predictions: Value Functions:
- $\pi$  is a **policy** - what action should be taken at each state.
- The **return** is a measure of future cumulative reward $$G_t = R_{t+1} + \gamma R_{t+2} + \gamma^2 R_{t+3}...$$
- $\gamma$ is called the **discounting factor**(between 0-1) and de-values rewards further in the future.
- Helpful to think of $\gamma$ as the probability of continuing the trajectory.
- The **value function of a state s at time t, given $\pi$** is the expectation of the return
![[Screenshot 2023-10-11 at 21.26.10.png]]
Given a state $S$ and $A$ a set of policy, we can calculate the expectation.

### How do we estimate value functions?
We can sample the expectations. This doesn't depend on the environment and can alway be done. The tree represents the interactions the agent has had. The actions, and the trajectory it takes is dependent on the policy $\pi$. The agent observes the return $G_{t}$. We have a learning rate/step size $\alpha$.
$$V(S_t) \longleftarrow V(S_t) + \alpha[G_t - V(S_t)]$$
This is known as the **Monte Carlo Approach.**
![[Screenshot 2023-10-11 at 21.51.05.png]]
#### Markov Decision Process:
- Next state and reward only depends on the current state and action, not the past history
- It can be considered as a probability model, where what's the probability of the next reward  and next state given the current state actions.
![[Screenshot 2023-10-11 at 21.39.07.png]]
- Returns have a recursive form: $G_t = R_{t+1} + \gamma G_{t+1}$ 
- From the value function definition:
![[Screenshot 2023-10-11 at 21.40.52.png]]
- Markovian property allows breaking up the expectation, to produce Bellman equations:
![[Screenshot 2023-10-11 at 21.42.37.png]]


An incremental version of this equation, we can update $S_t$ based on current estimates of the values $s'$ of all its successors and averaged according to the policy $\pi$. This is sort of a **Breath First Search**, and it will consider all possible next choices, and also next states, and it won't go any further. This is opposite to the **MC** approach which involves more **Depth First Search.**
![[Screenshot 2023-10-11 at 21.43.17.png]]
## Temporal-Difference(TD):
Can we combine these two methods! The solution of **Temporal-Difference** (TD).
$$V(S_t) \longleftarrow V(S_t) + \alpha[R_{t+1} + \gamma V(S_t) -V(S_t)]$$
![[Screenshot 2023-10-11 at 22.00.44.png]]
- Value estimate at time step $t$: $V(t)$
- Value estimate at time step $t+1$ : $R_{t+1} + \gamma V(S_{t+1} ) - V(S_t)$ 
- If $v$ is parameterised by $w$, then change $w$ so to minimise the TD-error. However this algorithm cannot be analysed using gradient descent, but using fixed point tools.
$$ W_{t+1} = w_t + \alpha \delta_t \Delta_wV_w(S_t)$$

## Multi-step backups:
- Reinforcement learning often relies on backups, which can be limited in accuracy due to factors like the value of the next state and the Markov property of the environment.
- In cases where the environment is partially observable or V estimates are inaccurate, stop backups or multi-step backups provide a way to blend PD and Monte Carlo targets.
- These techniques involve truncating the agent's return, providing a more adaptable approach to reinforcement learning.
- In reinforcement learning, N-step TD targets use rewards and the value of the state at a future time step (T+N) as a surrogate, with the discounting causing this value to diminish compared to the infinite-step TD.
- N-step backups in RL offer a trade-off between different time steps for estimating state values.
- The infinite-step TD is akin to the Monte Carlo algorithm in RL.
- Monte Carlo method have a high variance and TD has a higher bias.
![[Screenshot 2023-10-12 at 10.43.26.png]]



## Eligibility Traces:
Eligibility traces are a key concept in reinforcement learning that play a crucial role in updating value estimates and attributing credit to earlier states and actions in an agent's learning process. They are used primarily in Temporal Difference (TD) learning algorithms, such as TD(λ), and help bridge the gap between the TD and Monte Carlo methods.

![[Screenshot 2023-10-12 at 10.57.52.png]]
$$w_{t+1} = w_t + \alpha \delta_t \mathbf{z}_t$$
$$Z_{-1} = 0$$
$$ z_t = \gamma \mathbf{z}_{t-1} + \Delta \hat{v}(S_t,\mathbf{w}_t)$$
-  Implementation of reinforcement learning involves the use of an eligibility trace vector, which starts with an initialisation to zero.
- When a state is encountered, the eligibility vector is updated, and it gradually fades over time with a parameter denoted as $\gamma$ 
- This fading mechanism helps manage errors in states that are farther away in the agent's past when using function approximation in reinforcement learning.![[Screenshot 2023-10-12 at 11.05.06.png]]


## Control Problem:
Focuses on the control problem, which involves estimating the optimal policy for a finite Markov decision. **Bellman** showed there is an **unique optimal value function** and **at least one corresponding optimal policy**. We can use the **optimal value function** over states $v(s)$ = $max$ $v_{\pi}(s)$, by finding $v_{\pi}$ over all the policies at a particular state.

There is also a different value function called the **action value function** denoted as $q_*(s,a)$. The use of $q_*(s,a)$  is to encourage the agent to explore its environment and consider actions different from what the policy would typically choose, promoting a broader understanding of the available choices. This is especially important at the initial time frame.
![[Screenshot 2023-10-12 at 11.19.19.png]]
#### 1st Approach: Value Iteration:
In this approach $v_*$ of $s$ is computed by maximising over the agents actions $a$ and we use the idea of recursion to derive the two equations which has a relationship between the value of a state $s$, and value of the next state $s'$. This is usually turned into an update rule.
![[Screenshot 2023-10-12 at 11.44.25.png]]

![[Screenshot 2023-10-12 at 11.45.40.png]]



#### Model Based Reinforcement learning
It is an approaches which applies a learned model instead of exact model for making decisions in an unknown environment. It uses a dynamic programming approach.
- Takes trajectories and estimates the reward and transition model, $\tilde{p}(s',r|s,a)$ using maximum likelihood methods, and supervised learning methods. 
- Then we can use dynamic programming with the approximate model:

![[Screenshot 2023-10-12 at 11.55.38.png]]

- Dynamic programming for reinforcement learning has a fundamental problem as it requires considering all possible next states and actions, which can be problematic when dealing with continuous or large state and action spaces.
- In the case of a game like Go, the state space is discrete but extremely vast (size 10^170), and the action space is also very large, with around 100 possible actions.
- This problem highlights the need for alternative methods like reinforcement learning to handle complex scenarios where dynamic programming is impractical.
- Solution: **sample and use function approximation** 


#### 2nd Option: Model-Free Value-Based RL:
- Take trajectories and estimate the action-value function directly, where the optimal policy is determined by the greedy approach with respect to this value function.
- Optimal policy is then simply greedy: $\mathbf{A}_t = argmaxq_a(S_t,a)$


## Exploration is Needed:
- Agents need to explore their environment to learn the values of different actions.
- An example of exploration is illustrated in the environment "Deep Sea" where an agent, like a diver, starts at the ship and seeks a treasure chest, uncertain of its contents.
-  Agents in reinforcement learning should not always follow the currently known optimal actions but should explore other actions to learn from them.
- Exploration methods in reinforcement learning can be categorised into four basic types, with the first category(randomisation) involving adding noise to the greedy policy of the agent, as seen in the epsilon-greedy algorithm.
	- Deep-sea randomisation may not be effective in reinforcement learning as it can hinder the agent's progress.
-  Another approach is "optimism in the face of uncertainty," where the agent assumes unvisited states contain valuable rewards. Like UCB algorithm.
	- It highlights the potential problem of excessive optimism in reinforcement learning, as it can lead to the agent exploring the entire environment, which may not be efficient in large environments.
- Another approach is probability matching: select actions according to their probability  of being best e.g. Thompson sampling.
	- Thompson sampling involves a Bayesian approach and maintaining uncertainty estimates, which can be computationally expensive.
- Final approach is plan to explore, using Bayes-Adaptive MDP. This is the best, and the most computational expensive.

## Learning:
There are two types of learning on-policy learning(sarsa), and of-learning policy (q-learning).

#### Sarsa: On-Learning Policy
- Always learn the action-value of the current policy. 
- It almost acts near-greedily wrt to the current action-value estimates.
- The agent updates its parameters using TDR with $Q$ values instead of $V$ values and employs the gradients of the $Q$ functions to distribute errors to various parameters.
- $\alpha$ is the learning rate
#### Q-learning: Off-policy learning:
- It uses the value iteration equation for action-values:
![[Screenshot 2023-10-12 at 13.05.09.png]]
- It uses a sampled version in which the agent is at a particular state $S_t$ and chooses a particular action $A_t$ which is $Q(S_t,A_t)$ 
- Then it observed a reward but then imagines that from the next state $S_{t+1}$ onwards, what would the possible action to be, denoted as $a'$ .
![[Screenshot 2023-10-12 at 13.09.08.png]]
- In the tabular case, we can show that the outcome converges to the best possible outcome regardless of the behaviour policy so long as the behaviour policy is sufficiently exploratory. 
- However, with approximation functions most of the theoretical results are negative, and can cause **divergence**.
###### Function Approximation:
We need function approximation for Q-learning
