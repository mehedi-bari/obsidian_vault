	What are transaction processing?
	-  Transaction processing systems are systems with large databases and hundreds of concurrent users.

	What is a single user DBMS?
	- A DBMS is single user if one person can access the system at a time.
	- Therefore a DBMS is multiuser if it enables muliple users at a time.
	- Conurrency is acheived by using multiprogramming
		- The OS does this by contact swtiching/context switching. It does this by interleaving.
![[Screenshot 2022-11-15 at 09.45.35.png]]



	Read and Write and DBMS Buffers:
	 - If the information is not inside the buffer, we read from the secondary storage to the buffer.
	 - This information can be used by the program memory. 
	 - When the program writes, the prgrom writres it to the DBMS Buffer.
	 -  The information is not stored/updated until the program is not terminated or if there was a commit.
	 - The reason why we use the buffer, as if something goes wrong, we have the orginial state.

	Concurrent ACCESS issues:
		- If we didn't have concurrency control, it would affect the integrity of the database. 
		- We could have a lost read.
		- A temporary update/dirty read 
		- Incorrect summary.
		- Unrepeatable read.
	
![[Screenshot 2022-11-15 at 10.10.07.png]]
- We had lost a bit of information [red square],  because it was written in memory after it was read.
- NOTE: Whenever a transaction is submitted to a DMBS for execution, the system needs to make sure that all the operations have been completed successfully- COMMITTED. 
- If something goes wrong it must not update - ABORTED. 

![[Screenshot 2022-11-15 at 10.19.37.png]]
- The item X is written as 79, but it is set as 80, because T1 fails; T1 is set back to its original starting value. 

		What could go wrong?
			- System crash
			- Transaction Error
			- Logical Errors (bank value going less than 0)
			- Disk Failure
			- Physical Problems

