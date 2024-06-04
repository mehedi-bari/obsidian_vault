Normalisation:
- Normalisation is the process of organising the data into databases, with a foucs of minimising reduncies in relations.
	- FD helps identify redundancy in relations
- There are three main types of normalistation:
	- ![[Screenshot 2022-10-14 at 07.49.32.png]]
	- Insertion Anomaly: Lets say we want to add a row, but we are missiing one of the data for a specific column. Therefore we fail to insert it in.
	- Deletion Anomaly: Lets say we delete the AI scientific group, then Ann Smith will sieze to exist.
	- Update Anomaly: Lets say Mata changes scientific group, and it changes only in row 2 not 3. This results in redunct and incorrect data.
- What are the advantages of it?
	- Prevents data redundancy
	- Offers data consistency 
	- Offeres flexibility in design and data management.
	- Enforces relational integrity 



![[Screenshot 2022-10-14 at 08.07.51.png]]
- We can't have multiple entries in a single row. Instead we put in a separate row.
- This allows atomicity. 


![[Screenshot 2022-10-14 at 08.08.02.png]]
- All the other non-key attributes must only dependent on the primary key.
- If it depends on a different attributes llike the candidate key, its better to make the candidate key a primary key in a different database. 

![[Screenshot 2022-10-14 at 08.14.26.png]]