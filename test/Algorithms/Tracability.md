## Classes of Problems
- **P**: Problems solvable in polynomial time (e.g. $O(n^c)$)
- **NP**: problems that are **verifiable** in polynomial time, or are solvable in polynomial time **by a non-deterministic machine**. **P** is a subset of **NP**.
- **NP-Hard**: Problems that are at least as hard as every problem in **NP**.
- **NP-Complete**: Problems that are in both **NP** and **NP-Hard**.

All of the classes are related like this:
![[Screenshot 2023-05-09 at 16.02.42.png]]

## Encodings
#### Decision Problems
Decision problems are problems with a yes or no output, e.g.
- Is element $e$ in list $L$? `SEARCH(e, L)`
- Is there a path from nodes $u$ to $v$ in a directed graph $G$, with at most $k$ edges? `PATH(G, u, v, k)`
- Does a boolean combinatorial circuit C have a set of inputs that make its output 1? `CIRCUIT-SAT(C)`

The other kind of problem is an **optimisation problem**, where you try to find a value, for example Travelling Salesman.

## Abstract and Concrete Inputs
In the descriptions of problems, our inputs are **abstractly defined**. When making an algorithm, we need a **concrete** representation of our inputs, i.e. and actual representation that could be applied in a computer program.
We use a standard encoding of integers and lists to a binary representation so we can serialise anything and encode it. As long as any encoding we use is **polynomially related** to these standard encodings, then our results will hold.

Note that the encoding of numbers is logarithmic in their value. The binary encoding of a number $n$ takes $k = \log_2{n}$ bits. Therefore, an algorithm that is linear in $n$ is exponential in $k$:
$$O(n) = O(2^k)$$
For example, consider primality checking - this is linear in the value.
Dynamic programming solutions often give solutions that are linear in the **value** of the input, not its size.
This is called **pseudo-polynomial**.

## Language of a Decision Problem
With our standard encodings, we can assume that all inputs are binary strings. 
With this, an alternative interpretation of a decision problem is therefore the set of binary strings where the answer is 1. This is the **language** of the decision problem.
The same name is often used to refer to a problem and its language:
![[Screenshot 2023-05-10 at 14.10.35.png]]
## What is the class P?
There is some algorithm $A$ which takes a bitstring $x$ and either accepts ($A(x) = 1$) or rejects ($A(x) = 0$) it.
The language $L$ is **decided by** $A$ if $A(x) = 1$ for all bitstrings $x$ in $L$, and $A(x) = 0$ otherwise.
It is decided in polynomial time if there exists a constant $k$ such that for any $n$-length bitstring $x$ in $L$, the algorithm $A$ runs in time $O(n^k)$.
By this definition, we can formalise the informal definition:
> A problem is in $P$ if it is solvable in polynomial time

to this:
>![[Screenshot 2023-05-10 at 14.11.24.png]]

## What is the class NP?
#### An example - The Vertex Cover Problem
> Given a graph $G = (V, E)$ and an integer $k$, is there a subset $C \subseteq V$ such that $|C| \leq k$ and for every $(u, v) \in E$ either $u \in C$ or $v \in C$?

We can check if some $C$ is a solution in $O(kn)$ - just check that each edge has an end in C.
Therefore, a brute-force algorithm can check all $2^n$ subsets of $V$ to see if such a subset exists.
This solution $C$ is a **polynomial-time verifiable certificate** for the vertex cover problem. 
#### More examples - SAT problems
> **SAT Problem**
> Given a boolean expression $B$ over variables $V$, does there exist an assignment $A$ of truth values to $V$ that makes $B$ true?

Aside: SAT is the **canonical NP-Complete problem** - that is, it was the first problem to be proven NP-Complete.

> **3-SAT Problem**
> Given a set $B$ of 3-clauses over variables $V$, is there an assignment $A$ of truth values to $V$ that makes each clause in $B$ true?

> **2-SAT Problem**
> Given a set $B$ of 2-clauses over variables $V$, is there an assignment $A$ of truth values to $V$ that makes each clause in $B$ true?

Solving the regular SAT problem is exponential in terms of the number of variables, making it **NP**. 3-SAT is also **NP**, though not in the same manner. 2-SAT is **P**, which means that you **can not** reduce SAT or 3-SAT problems to 2-SAT problems.
#### NP as Polynomial-time Verification
A verification algorithm A for a problem takes an input x and a certificate $y$ such that.
![[Screenshot 2023-05-10 at 13.42.36.png]]


A nondeterminisitc machine is a theoretical machine that can try all possible computations at the same time. 
The **class NP**: A problem is in NP if there exists an algorithm that solves it in polynomail time on a nondeterministic machine. 
Hence, Nondeterminisitc Polynomial time. But this is the same definition  as before. The polynomail computation is a polynomical length certificate.

#### NP as Nondeterministic Computation
A nondeterministic machine is a theoretical machine that can try all possible computations at the same time.
Another definition of the class NP is this:
> A problem is in NP if there exists an algorithm that solves it in polynomial time on a nondeterministic machine.

This is equivalent to the definition as before.

## What is the class NP-Complete?
> A problem given by language $L$ is NP-Complete (or NPC) if:
> 1. $L \in NP$
> 2. Every problem in $NP$ can be reduced to $L$ ($L' \leq_p L \text{ for all } L' \in NP$)

(Note: if 1. is not true but 2 is, then the problem is NP-Hard instead of NP-Complete)

The obvious problem here is that there are infinitely many problems in NP, so proving a problem NP-Complete ought to be impossible.
This can be solved by using a useful property of the $\leq_p$ operator. As it is transitive, we can show that $L$ is reduced to by everything in NP by showing that L is **reduced to by an existing NPC problem**. That is, $A \leq_p L \text{ for some } A \in NPC$.
This still doesn't solve the issue, because that requires at least one problem to be proven NP-Complete by other means first. So how do you show the first NP-Complete problem? You achieve this using the **Cook-Levin Theorem** (which is in next week's content).




## Reductions
You have a problem $A$ and a problem $B$. If you can solve problem $B$ using problem $A$, then there are properties of both problems that you can infer based on the other.

More formally, we can define it as such:
> For two languages/problems $A$ and $B$, when we say "$A$ is reducible to $B$" it means that we can use $B$ to solve $A$. ($A \leq_p B$)

For example, 
(A): You are lost in a city and you need to find your way back to your hotel.
(B): You need to find a map of the city.
If you can find a map to the city, then you can find your hotel; you can reduce A to B.
Finding your hotel cannot be "harder" than finding a map; if you've found a map then you can always find your hotel.
**If finding a map is easy, then finding the hotel must be easy. If finding the hotel is hard then finding a map must be hard.**
That said, if finding the hotel is easy then we can't say much about the difficulty of finding a map. (Finding the map must be *at least* as hard as finding the hotel, but it could be much harder; perhaps you didn't even bother finding a map and just asked for directions instead)
Similarly, if finding a map is hard then we can't say much about the difficulty of finding the hotel. (Finding the hotel is at most as hard as finding a map, but there might be an easier way).
In summary, The reducible problem ($A$) is **at most as hard as** the problem it is reduced to ($B$), but it may be easier. The problem that it is reduced to ($B$) is **at least as hard as** the reducible problem ($A$), but it may be harder.
(There is a visualisation in the video that might be useful, video 4 around 4 mins)
That gives these rules:
- If you can find a hard problem $A$ that reduces to another problem $B$, then you know that $B$ is also hard.
- If you can find an easy problem $B$ that another problem $A$ reduces to, then you know that $A$ is also easy.

#### Poly-time Mapping Reducibility
> $A$ is "polynomial time mapping reducible" to B (that is, $A \leq_p B$) if there is a polynomial time function $f$ where $w \in A$ iff $f(w) \in B$.

That is, if you can find a polynomial-time function which maps the set of solutions for $A$ exactly to the set of solutions for $B$, then $A$ is reducible to $B$. Non-solutions should also map to non-solutions.

#### Decision vs Optimisation problems
> Let $D(x, k)$ be a decision problem, and let $O(x)$ be an optimisation problem of the form "For some input $x$, find a maximal/minimal $k$ such that $D(x, k)$ holds".

For a concrete example, consider `CLIQUE` and `OPTCLIQUE`:
> CLIQUE(G, k) is the decision problem that decides if a graph G contains a clique of size k.
> OPTCLIQUE(G) is the optimisation problem that computes the largest clique in G and returns it's size k.

Since we are using CLIQUE to solve OPTCLIQUE, we can say that OPTCLIQUE reduces to CLIQUE.
However, if we can solve OPTCLIQUE then we can also definitely solve CLIQUE; run OPTCLIQUE and return true if the answer is equal to k. Since you can use OPTCLIQUE to solve CLIQUE, we can also say that CLIQUE reduces to OPTCLIQUE.
In this case, both problems must be the same difficulty.
(Note that decision problems will never be harder than the associated optimisation problems.)

## What is the class NP-Complete?
> A problem given by language $L$ is NP-Complete (or NPC) if:
> 1. $L \in NP$
> 2. Every problem in $NP$ can be reduced to $L$ ($L' \leq_p L \text{ for all } L' \in NP$)

(Note: if 1. is not true but 2 is, then the problem is NP-Hard instead of NP-Complete)

The obvious problem here is that there are infinitely many problems in NP, so proving a problem NP-Complete ought to be impossible.
This can be solved by using a useful property of the $\leq_p$ operator. As it is transitive, we can show that $L$ is reduced to by everything in NP by showing that L is **reduced to by an existing NPC problem**. That is, $A \leq_p L \text{ for some } A \in NPC$.
This still doesn't solve the issue, because that requires at least one problem to be proven NP-Complete by other means first. So how do you show the first NP-Complete problem? You achieve this using the **Cook-Levin Theorem** (which is in next week's content).