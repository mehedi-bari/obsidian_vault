For some graph, the MST is a subgraph that connects every node with the minimum total summative weight possible. MSTs are always acyclic by definition; they are trees.
As a formal problem:
![[Screenshot 2023-03-30 at 13.23.16.png]]

## Generic Greedy Strategy
A generic greedy strategy, which won't always be optimal.
```python
procedure genericMST(G, w):
	A = {}
	while A is not a spanning tree:
		E = find an edge that is safe for A
		A = A union {(u, v)}
	return A
```
Therefore the loop will continue, until:
- $A \subseteq$ some $MST$.
- $(u,v) \in T$: $(u,v) \notin A$ and $(u,v)$ is *safe*
- Executes |$V$| - 1 times 
- Tricky part is finding a *safe* edge
#### Correctness:
Piror to each iteration $A \subseteq$ some $MST$ 
Each step: determine $(u,v) \notin A$ to add to $A$ without violating this invariant:
- $A$ $\cup$ {$(u,w)$} $\subseteq T$    
- $(u,v)$ then a *safe* edge
 
## Cuts & Light Edges
If you have a graph $G=(V, E)$, then a cut $(S, V-S)$ of that graph is a partition of $V$.
A cut respects a set of edges $A$ if $A$ contains no edges which **cross** the cut. An edge **crosses** a cut if one of its endpoints is in $S$ and the other in $V - S$.
If you have a set of edges crossing a cut, the edge with minimal weight is called the **light edge**. (You can have many light edges.)
![[Screenshot 2023-03-30 at 13.37.13.png]]
In this example, the light edge is the one between Bonn and Karlsruhe.

## Recognising Safe Edges:
- Supposed that we have an Undirect graph $G = (V,E)$
	- $E =$ {$(u,v) | w(u,v) \neq \infty$ }
- $A \subseteq E$ included in some $MST$ for $G$
- $(S,V-S)$ any cut of $G$ that *respects* $A$ 
	- The cut removes the $MST$ is progress, and doesn't chop it up at all.
- $(u,v)$ a light edge crossing $(S,V-S)$
	- Now, imagine the light edge. So, that's the edge that connects out existing $MST$  in process to some other node, which is NOT inside the $MST$ in progres.
	- This edge has the **minimum weight**  that crosses the cut.
	- It is also **NOT** introducing any **cycles** as it isn't connecting with something that isn't already present inside of the $MST$
- $\Longrightarrow (u,v)$ is a *saf*e edge for $A$

## Kruskal's Algorithm
An algorithm to find an MST of a graph.
```python
procedure kruskal(G, w):
	A = {}  # set of edges in the MST
	D = empty disjoint set
	for each node v in G:
		D.make_set(v)  # add set {v} to the disjoint set structure
	sort edges in G by weight w ascending
	for each edge (u, v) in G:  # starting with the smallest weighted edge
		if D.find_root(u) != D.find_root(v):  # if the nodes are disconnected
			A = A.add((u, v))  # add edge to MST, connecting the nodes
			D.union(u, v)  # join the two sets in the disjoint set structure
	return A
```

#### Use of Disjoint Sets:
- $MAKESET(x) -$   creates a new set whose only member *and representative* is $x$
	- requires that $x$ not already in some other set
```python
procedure MAKESET(x):
	x.p = x #it is its own parent/representative
	x.rank = 0
	#Represents the upper bound on the number of edge in the longest simple path from the descendent lead to x.
```
- $FINDSET(x)-$ returns a pointer to the representative of the unique set containing $x$ 
	- *Path compression*: each node on the find path points directly to the root.
```python
procedure FINDSET(x):
	if x not equal x.p then
		x.p = FINDSET(x.p)
	return x.p
```
- $UNION(x,y)-$ unites the sets that contain $x$ and $y$ into a new set that is the union of these two sets.
	- It will have an implementation using the union by rank heuristic.
	- Root with a smaller rank  will point to a root with a larger rank.
![[Screenshot 2023-03-30 at 14.14.19.png]]
For a worked example, watch **the end of the second video in the MST week**.
#### Complexity
Depends on the implementation of the disjoint-set data structure. As long as path-compression and union-by-rank heuristics are used, it will be $O(|E|log|V|)$.

## Prim's Algorithm
Another algorithm for finding an MST.
```python
procedure prim(G, w, r):  # start from some arbitrary node r
	V = G.nodes
	for each node u in V:
		u.key = infinity
		u.parent = None
	r.key = 0
	Q = priority_queue(V)  # lower key has higher priority
	while Q is not empty:  # for all unconnected nodes
		u = Q.dequeue()  # take the node with the lowest incoming weight
		for each node v where w[u, v] != infinity:  # for each edge out of u
			# if this edge weighs less than the existing connection
			if Q.contains(v) and w[u, v] < v.key:   
				v.parent = u
				v.key = w[u, v]
```
#### Complexity
Depends on the implementation of the priority queue. If a fibonacci heap is used, it will be $O(|E| + |V|log|V|)$.