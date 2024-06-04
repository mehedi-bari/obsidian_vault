## K-means Clustering:
Set two random centers, which will represent the two different clusters.
Calculate all the distance from the two centers, and find which one of the two centers is the closest.
![[Screenshot 2023-05-08 at 19.27.18.png]]

Then we need to calculate the new center, by using the points in the clusters, and finding the average of all the points.
![[Screenshot 2023-05-08 at 19.29.11.png]]

You repeat this  but you use the new center.
![[Screenshot 2023-05-08 at 19.33.19.png]]
Stop repeating when there is not change in the membership of each cluster.

#### Comments on K-means:
The iterative process minimises the within-custer sum of squares cost, which means it is the same as solving a minimisation problem:
![[Screenshot 2023-05-08 at 19.38.52.png]]
The Complexitiy is $O(TKN)$, where $N$ = number of data points, $K$ cluster number, and $T$ = iteration number.
It usually converges, but could converge to an unwanted solution.

Issues:
- Need to specify the number of clusters in advance.
- Unable to handle noisy data and outliers.
- Not suitable to discover clusters for complex data patterns.

## Hierarchical Clustering:
It groups objects into a **tree of clusters***, resulting in nested partitions layer by layer. It layers dta set sequentially, with no need to know cluster number in advance.

Agglomerative (bottom -up strategy):
- Start from treating each data point as a lcuster (atomic cluster.)
- Then **merge** the atomic clusters into larger and larger clusters.
Divisive (top-down strategy):
- Start from treating all data points as one single cluster.
- Then **divide** this cluster into smaller and smaller clusters.
![[Screenshot 2023-05-08 at 19.48.20.png]]


#### How does agglomerate algorithm work?
Find calculate the distance between all the data points, which acts like the clusters.
![[Screenshot 2023-05-08 at 20.03.07.png]]

We examine the distance, and we find the clusters which has the smallest value which are $C4$ and $C6$. 
After merging them, you need to re-calculate the distance between the clusters. More specifically, the clusters with the newly formed cluster. 
Note you need to choose the **method of finding the new distances**. You can use sinlge-link, complete-link, and average link. 
![[Screenshot 2023-05-08 at 20.08.29.png]]


Live, Die, Repeat.
![[Screenshot 2023-05-08 at 20.09.43.png]]

#### Finally!
![[Screenshot 2023-05-08 at 20.10.32.png]]
**Lifetime** of a cluster is then value between the new cluster is emulsified  subtract when it was first created
You can create clusters by maxing veritcal cuts at any point in the graphs, and it will give you the cluster groups, and the number of clusters. 
Different cuts will usually give you different number/types of clusters.


#### It still has cons:
- Sensitive to cluster distance measures.
- Sensitive to noise and outliers.
- It is less efficent with $O(N^2logN)$, where $N$ is then number of data points.