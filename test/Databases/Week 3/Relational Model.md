- The relational model takes the Entity relation model and takes it a bit further.
- In the relational model, we see access to different tables with unique keys, likes customer ID, order ID etc.
- The cocept of the entity actually becomes a table.
- ER concepts to the Relation Model;:
	- Entity -> Relation
	- Entity Attributes -> Relation Attributes
	- Identifies -> Primary Keys
	- Relationship -> FK/joining table

![[Screenshot 2022-10-13 at 20.09.48.png]]![[Screenshot 2022-10-13 at 20.10.13.png]]
The Key:
- The key is an unqiue attribute. 
- This helps us uniquely identify a row in a table.
- It also joins tables together.
- There are three types of keys:
	- PK(underlined), Candidate Key, and FK.
- What is the candidate key? A set of attributes that uniquely identifies a row.
- How do choose a PK?
	- You choose one from the candiate keys.
	-  It has to be unique
	- Non-null
	- Never changing
	- Simple(better if one attribute)
	- Is a number (faster than strings)
![[Screenshot 2022-10-13 at 20.25.24.png]]
![[Screenshot 2022-10-13 at 20.28.50.png]]
- If we remove something from the customer table, we would also remove it in the order table.
- We have to make sure when deleting and updating results, and it is consistent in the foreign and parent table.

![[Screenshot 2022-10-13 at 20.31.54.png]]




1-1 relationships:
- We usually want to put the foreign key where there is a 1-1 relationship. Look at the example below:
- We have that a user can have 0 to many orders, but if we have a customer it must have a user, and each customer can at max like to one user. 
- This means it makes sense to have customer as the primary key, and users as the foreign key.
- ![[Screenshot 2022-10-13 at 21.00.57.png]]


1-to many relationship:
- Similar to 1-1 relationship model, we have that full particiation for order. As for each order there needs to be a customer, and the maximum number of customer is also one. We have full paritipation.
- Therefore we would use customer id as the foriegn key
- ![[Screenshot 2022-10-13 at 21.02.55.png]]
Many-many:
- In this situation we would have a bit of complication. As both of the relations are actively pariticipating.
- We would have each unique order multiple product ids, and that would break atomicity. As we can't store different values in a single attribute. 
- ![[Screenshot 2022-10-13 at 21.20.53.png]]
- The solution would be to create a table with one to many as an intermediate
- ![[Screenshot 2022-10-13 at 21.24.35.png]]![[Screenshot 2022-10-13 at 21.26.37.png]]
- At this point all many-to-many relationships should have been resolved.


For weak entities:
- The foreign key is usually a parent in this case it is the order id.
- ![[Screenshot 2022-10-13 at 21.35.00.png]]