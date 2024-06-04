Cluster analysis is the task of **grouping a set of objects** so that object in the same group are more similar to each other than to those in other groups.
Clustering is **unsupervised** learning. Ther eare no predefined classes and training data.  e.g. Eucldiean Distance, Cosine Similarity, Minikowski distance, Manhattan distance.
![[Screenshot 2023-05-08 at 19.07.16.png]]
The lower the distance value, the more similar they're.
Then re-ordering gives the relationship, and the clusters.
![[Screenshot 2023-05-08 at 19.07.57.png]]

- It is important to decide which mode of calculating distance you're going to use.
- The number of clusters is treated as a hyperparameter.
- There are some clustering algorithms that attempt to decide a cluster number for you, but they're require other types of hyper-parameters.

## Cluster Distance Measures:
We can calculate the distance/similarity betweeen two data points, how can you measure the distance between two data clusters?
#### Single-Link measure:
It is the smallest between a data point in one cluster and a data point in the other cluster.
![[Screenshot 2023-05-08 at 19.14.45.png]]
Suppose you choose 4 from each cluster. Therefore there will 16 total calculations that will need to be done. Then the minimum of the distance is set as the distance.
#### Complete-link measure: 
It is the largest distance between a data point in one cluster and a data point in the other cluster.
![[Screenshot 2023-05-08 at 19.16.50.png]]
#### Average-Link measure:
It is the averages distance between data points in one cluster and data points in the other cluster.
![[Screenshot 2023-05-08 at 19.18.11.png]]



### EXample:
![[Screenshot 2023-05-08 at 19.20.18.png]]