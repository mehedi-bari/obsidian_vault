## Markov decision process(MDP):
It involves discrete-time stochastic control process.
	$\square$  Time moves forward in finite intervals $t \in \{1,2,3,...\}$
	$\square$  Future states depend only partially on the action taken.
	$\square$  It is based on decision making to reach target state.
The agent interacts with the environment. Based on the initial state, $S_t$, it takes an action, $A_t$, which causes a **change in the environment** as a result it causes a change in $S_{t+1}$, and then receives a reward from the environment, $R_t$, which gives feedback to the Agent. 
This usually used for every control task.

This is the idea of it: $(S,A,R,P)$
$\square$  Set of possible states for the task
$\square$  Set of actions that can be taken in each of the states
$\square$  Set of rewards for each pair $(s,a)$ pair.
$\square$  Probabilities of passing form one state to another when taking each possible action.

#### Types of Markov decision process
There are **finite** and **infinite** processes:
$\square$  finite: like a maze which has finite routes, and finite controls
$\square$  infinite: like driving a car and its speed

There are episodic and continuing:
$\square$  Episodic terminates after a certain goal
$\square$  Continuing doesn't have a terminating condition.

#### Trajectory and Episode
$\square$  Trajectory: elements that are generated when the agent moves from one state to anther. $\tau = S_0,A_0,R_1,S_1,A_1,R_2,S_2$
$\square$  Episode: trajectory from the initial state of the task to the terminal state $\tau =S_0,A_0,R_1,S_1,A_1,R_2,S_2,...,R_T,S_T$ 

### Reward vs Return 
The goals of the task are represented by the rewards($R_t$). We want to maximise the sum of rewards. However short term reward can worsen long-term results. e.g. capturing a piece in chess can make us in a worsen position. So we want to maximise long term reward.

Reward: $R_t$ 
Return: $G_t= R_{t+1} +R_{t+2}+R_{t+3}+...+R_T$ 

We want to maximise the long term expected return.


### Discount factor
Let's say the agent does it task properly in both occasions, but in one case it does it in the shortest time, but the second case the agent completes the task, but takes longer. So, they both return 1, but one is better than the other. We want to apply a **discounting factor** to indicate that it could do better.

We will multiply future rewards by a discounting factor $\gamma$ 
$G_0 = R_1 + \gamma R_2 + \gamma^2R_3 + \gamma^3R_+ ...+ \gamma^{T-t-1}R_T4$ where $\gamma \in [0,1]$

### Policy
Policy is the function that decides what action take in a particular state.
$\pi : S \longrightarrow A$ 
Probability of  taking action a in state s: $\pi (a|s)$  
Action $a$ taken in state $s$: $\pi(s)$ 

There are two types of policy:
Stochastic: $\pi(s) = [p(a_1), p(a_2),...,p(a_n)]$  so $\pi(s)=[0.3,0.2,0.5]$
Deterministic: $\pi(s) \longrightarrow a$ so $\pi(s) =a_1$

>We want to maximise the sum of discounted rewards.
>We must find the optimal policy $\pi$


### Expectations:
**State value**:
It is the expected return when starting with a particular state. It is linked to the policy of $\pi$.
$v_\pi(s) = \mathbb{E}[G_t|S_t=s]$ 
$v_\pi(s) = \mathbb{E}[ R_{t+1} +R_{t+2}+R_{t+3}+...+R_T| S_t=s]$ 
**State-action pair**:
$q_\pi(s,a) = \mathbb{E}[G_t|S_t=s,A_t=a]$ 
$q_\pi(s,a) = \mathbb{E}[ R_{t+1} +R_{t+2}+R_{t+3}+...+R_T| S_t=s,A_t=a]$ 


### Bellman equation
It is another form of the state value equation for a particular policy:
$$v_*(s)=\sum_a \pi(a|s) \sum_{s',r}p(s,r|s,a)[r+\gamma v_\pi(s')]$$
These are the bellman optimality equations:
$$v_*(s)= \max_a \sum_{s',r}p(s',r|s,a)[r+\gamma v_*(s')]$$
$$q_*(s,a)= \sum_{s',r}p(s',r|s,a)[r+\gamma \max_{a'}q_*(s',a')$$

