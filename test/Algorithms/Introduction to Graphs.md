A **graph** is a collection of entities/nodes and the connections between them. For example, a collection of train stations and the rails connecting them.

## Directed Graphs
A **directed graph** is a graph in which the relation between nodes is one-way.
Strictly speaking, it is a set of nodes $V$ and edges $E$, where $E \subseteq V \times V$.
For example:
$V= \{1, 2, \dots, 9\}$
$E = \{(1, 2), (1, 3), (2, 4), \dots\}$
$V$ is the set of nodes in the graph, and $E$ is the set of relationships between nodes. Each tuple in the set represents a one-way connection, with the first number being the source and the second being the destination.

A **path** is a sequence of nodes $u_1, u_2, \dots, u_n$ such that $u_i \in V$ (all nodes in the sequence are in the graph) and $(u_i, u_{i+1}) \in E$ (all subsequent pairs are in the set of edges).
A **cycle** is a path that begins and ends at the same node, e.g. $2, 4, 9, 2$.
A **simple graph** is a graph with **no parallel edges** (no edges with the same start and end nodes) and **no loops** (nodes that point to themselves).
A **spanning subgraph** is a subgraph that contains all nodes in the graph.

## Operations on Graphs
![[Screenshot 2023-03-29 at 17.20.05.png]]
## Implementations
#### Adjacency Lists
Store a list/set of successors for each node. For example:
![[Screenshot 2023-03-29 at 17.20.53.png]]
```python
succs[1] = {2, 3}
succs[2] = {4, 5}
succs[3] = {6, 7}
succs[4] = {8, 9}
succs[5] = {}
succs[6] = {5}
succs[7] = {}
succs[8] = {}
succs[9] = {2}

```
- `Succs(u)` is very easy to implement
![[Screenshot 2023-03-29 at 17.21.59.png]]

#### Adjacency Matrix
Store a 2D array of boolean values, representing if a node is connected to another or not.
![[Screenshot 2023-03-29 at 17.26.02.png]]
- Stores $|V| \times |V|$ map of booleans
- Bad memory efficiency for sparse graphs
![[Screenshot 2023-03-29 at 17.26.46.png]]
#### Which to use?
Decide based on:
- How dense is the graph?
- What operations will be performed?
For example, a social media website may prefer an adjacency list due to the large number of users but the relatively small amount of relations between them.

## Traversal
Similar to [Tree Traversals](Search%20Tree.md#Traversal).

### Generic
1. Start at some node.
2. Add all nodes accessible from here to the `toExplore` list.
3. Check current node: can the goal be found here?
4. If not, add the current node to the `explored` list. Then, go to the first node in the `toExplore` list, removing it in the process.
5. Repeat from step 2 at this new node.
![[Screenshot 2023-03-29 at 17.40.38.png]]
In non-maths-speak:
```python
procedure Explore(s):
	D = new set containing s
	F = empty set
	while D is not empty:
		u = random_choice(D)
		D.insert(all nodes that u leads to)
		D.remove(u)
		F.insert(u)
	return F
```

### Depth First Search (DFS)
Same as the Generic algorithm, but using a LIFO structure (i.e. a stack) for D.
```python
procedure DFS(s):
	D = new stack containing s
	F = empty set
	while D is not empty:
		u = D.pop()
		D.push(all nodes that u leads to)
		F.insert(u)
	return F
```
There is also a recursive definition:
![[Screenshot 2023-03-29 at 17.50.31.png]]
In non-maths-speak:
```python
procedure DFSRec(s):
	return DFSRec(empty set, s)

procedureDFSRec(F, u):
	if not F.contains(u):
		F.insert(u)
		for all nodes that u leads to:
			F = DFSRec(F, v)
	return F
```
### Breadth First Search (BFS)
Same as the Generic algorithm, but using a FIFO structure (i.e. a queue) for D.
```python
procedure BFS(s):
	D = new queue containing s
	F = empty set
	while D is not empty:
		u = D.dequeue()
		D.enqueue(all nodes that u leads to)
		F.insert(u)
	return F
```
There is no such recursive definition for BFS.

## Topological Sorting
A set of tasks, e.g. a build sequence for software or a project's schedule, can be modelled using a directed graph. A topological sorting algorithm can find a valid sequence of tasks that respects the required order. 
![](Pasted%20image%2020230130132811.png)
Strictly speaking, the objective of a topological sorting algorithm is to find a sequence of nodes such that all edges point forwards. This is only possible if the graph has **no cycles**.

## Cycle detection with DFS
- Perform DFS, keeping a list of all finished nodes as usual.
	- When first encountering a node, mark it as O(pen)
	- Only when finished exploring all of its children, mark it as D(one)
	- Whenever we encounter an open node again, it's a cycle.
- When searching for nodes to add to the `toExplore` stack, check against the finished nodes.
- If an upcoming node is found that has already been explored (i.e. is in the list of finished nodes) then a cycle has been found.
![[Screenshot 2023-03-29 at 18.11.27.png]]

![[Screenshot 2023-03-29 at 18.11.00.png]]

