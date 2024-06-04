	Master/Slave:
	- Requests go through the master
	- Master limits the scalability
	- Single Point of Failure

	Couchbases's appraoch Master/Master:
	- It has a max shards 1024.
	- It stops it from getting too large.
	- It uses hash, and then puts the shards(vBuckets) into buckets.
	- There is also a cluster map, which contains all the nodes, and its respective shards(vBuckets.)
	- If there is a node failure, the other nodes can still communicate with each other.


![[Screenshot 2023-01-04 at 19.58.39.png]]

![[Screenshot 2023-01-04 at 19.58.55.png]]


![[Screenshot 2023-01-04 at 20.06.41.png]]



		Things that need attention:
	 -  SDK needs to access all the clusters, so it needs to correct ports in order to acess it.
	 - There's a timeout period, so it doesn't hold up and slow down performance.
	 - Couchbase SDK uses lazy opertation. It stops loads of accesses to the databases.

		ACID:
		- Atomicity: A group of operations either all success or fail
		- Conistency: Data will never be in an invalid state. If you add some data, you may not get the changes immediately. This is because of the latency in the settings. This may affect your development.
		- Inoc
		- D

- Cluster > Bucket > Collection
- 



 


