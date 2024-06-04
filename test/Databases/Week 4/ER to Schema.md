1-1 Relationships:
- ![[Screenshot 2022-10-20 at 16.29.18.png]]
- Since the customer has participation, as each customer is connected to a single user. The FK attributes will reside inside Customer.
- ![[Screenshot 2022-10-20 at 16.31.56.png]]

1-to many example:
- Each order has one customer, so it has full participation. Therefore it will hold the FK
- ![[Screenshot 2022-10-20 at 16.33.00.png]]![[Screenshot 2022-10-20 at 16.34.27.png]]
Many-to-Many:
- In a many-to-many case the issue that normally occurs is that one may not need to exist for the other e.g. the product can still exist without there being an order.
- You also can't have multiple product ids for each order as that breaks atomicity.
- ![[Screenshot 2022-10-20 at 16.37.26.png]]
- The solution is to create a middle table, which has a 1-1 relationship on both sides.
	- They also become the primary key of the table.
- ![[Screenshot 2022-10-20 at 16.41.48.png]]

![[Screenshot 2022-10-20 at 19.47.47.png]]