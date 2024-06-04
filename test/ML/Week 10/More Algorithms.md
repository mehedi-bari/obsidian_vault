After getting your clusters, it is important to validate whtether your clusters make sense. 
- Internal criteria(indexes) validates based on common sense without using external information
- External criteria(indexes) valdiate against the ground truth.

## Typical Internal Indexes:
Noramlly a good clustering results should have small within-cluster variance while large betweeen-cluster variance (where K is the cluster number:)
![[Screenshot 2023-05-09 at 10.26.05.png]]


## External Validation:
![[Screenshot 2023-05-09 at 10.36.37.png]]

 We can use the Rand Index to create some sort of a metric to help us see how well it has classed objects:
![[Screenshot 2023-05-09 at 10.42.13.png]]
![[Screenshot 2023-05-09 at 10.45.45.png]]


