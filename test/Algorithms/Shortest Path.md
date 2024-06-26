Problem: Find the shortest path from some node to any other node in a graph, shortest meaning "the minimal number of edges".
BFS visits nodes in order of their distance from the starting node $s$, so could that be useful?
To solve the problem, introduce a *predecessor map*:
- For each node, store the node from which it was discovered
- Follow these nodes backwards until $s$ is reached
- By convention, $s$ is its own predecessor
## BFS Method![[Screenshot 2023-03-29 at 18.46.49.png]]
In non-maths-speak:
```python
def ShortestPaths(s):
	d = [s]
	found = {}
	predecessor = Map()
	predecessor[s] = s
	while d is not empty:
		u = d.dequeue()
		F.add(u)
		for all v that u leads to AND v not in found:
			D.enqueue(v)
			predecessor[v] = u
	return predecessor
```
Then to get the shortest path from the predecessor map:
```python
def GetPath(pred, u):
	p = [u]  # list representing a path, start as idx 0 
	# and end as idx n
	while pred[u] != u:  # while the starting node hasnt been reached
		u = pred[u]
		p = u + p 
	return p
```

## Shortest Paths in Weighted Graphs
Similar problem, but concerned with the total weight along the path as opposed to the number of nodes.

#### Representing a Weighted Graph
![[Screenshot 2023-03-30 at 11.49.35.png]]
Similar to an adjacency matrix, with weights instead of boolean true/false values. If two nodes are not connected, the weight is said to be $\infty$.![[Screenshot 2023-03-30 at 11.52.08.png]]
The weight of a path is simply the sum of the weights of all of the edges it takes.
If the weight is $\infty$, there was a non-existent edge in the path, and it isn't feasible.
![[Screenshot 2023-03-30 at 11.52.28.png]]
$\delta(u,v)$ is the shortest distance from node $u$ to node $v$. If no path exists, $\delta(u, v) = \infty$.

## Bellman Ford Algorithm
An algorithm to compute the shortest paths from some starting node $s$ to any other node.
In the context of this algorithm, shorten $\delta(s, v)$ to $\delta(v)$. Its always the same starting node anyway.
![[Screenshot 2023-03-30 at 11.58.25.png]]
1. Create estimate map, with the distance being $\infty$ for all edges but the one connecting the start node to itself, which is 0.
2. Check every edge in the graph; if this edge can be used to get to its end node faster than the current estimate in D, then replace that estimate.
3. Repeat step 2 $|V| - 1$ times. That is, the number of vertices in the graph minus one. (Not pictured in the pseudocode is that you can stop early when no distances are changed for a whole iteration.)
#### Example
https://www.youtube.com/watch?v=obWXjtg0L64

#### Correctness
**Claim**: For each round of iteration $I$, the estimated shortest paths in $D$ with maximum length $I$ are correct.

**Base case**: At the end of round 0, $D$ is precise up to length 0.
**Assume that**: at the end of round $i$, $D$ is precise up to length $i$.
**Show that**: At the end of round $i + 1$, $D$ is precise up to length $i + 1$.

1. It is true that the prefix of a shortest path is also a shortest path.
2. Consider the path "$s \rightarrow P \rightarrow u \rightarrow v$", which is a shortest path from $s$ to $v$ of length $i + 1$.
3. Therefore, "$s \rightarrow P \rightarrow u$" must be the shortest path from $s$ to $u$, of length $i$. We know that $D(u)$ is precise.
4. Round $i + 1$ relaxes the edge $(u, v)$.
5. Now, $D(v)$ is precise after round $i + 1$.

#### Complexity
- In the worst case, we do all $|V|$ iterations.
- Each round inspects $|E|$ edges.
- Relaxing an edge is $O(1)$.
- Therefore, the complexity is $O(|V||E|)$.

#### Negative Weight Cycles
A negative weight cycle is a cycle in a graph where the total weight is negative. For example,  consider c -> b -> d -> c on this graph. 
![[Screenshot 2023-03-30 at 12.14.26.png]]
The Bellman Ford algorithm, unlike some other similar algorithms, is not thwarted by negative weight cycles. Due to its finite amount of iterations, the algorithm will always halt, and if an estimated weight changes on the final iteration then it can only be because of a negative weight cycle.

- There are 4 edges, so it will iterate 4 times, however after the $4^{th}$ one there are still changes, which means that it was able to detect a negative weight cycle.
- It is also important to note that it wasn't able to find the shortest path.

