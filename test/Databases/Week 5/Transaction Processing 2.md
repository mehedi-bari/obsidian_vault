	 Desirable Properties of Transactions:
	- Atomicity:: All the transactions complete successfully, or it fails.
	- Consistency Preservation: The database should go from one consistent state to another consistent state.
	- Isolation: The transaction should be working alone, but working and communicating with other transactions.
	- Durability or Permanency: Changes should be permenant.

Schedules:
- b = begin, e = end; w = write; r = read; a = abord; c = commit;
![[Screenshot 2022-11-15 at 10.38.33.png]]
![[Screenshot 2022-11-15 at 10.39.27.png]]

	Conflicting Operations in a Schedule:
	- They belong to different transactions.
	- They access the same item X
	- At least one of the operations is a write
![[Screenshot 2022-11-15 at 10.51.35.png]]

	Serialisation:
	- Serial transactions always give us the correct result.
	- Non-serial can be a bit of hit or miss.
	- We want to make serialisable schedules. 
	- The most common way to approach equivalence of sheducles is by using conflict equivalance.
	- We can test serialisability by using graphs:
		- If there is a loop it isn't serialisable.

![[Screenshot 2022-11-15 at 11.32.38.png]]


