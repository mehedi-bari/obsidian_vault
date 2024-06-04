Database Application Design Phase:
 - The phase follows the strucutre of data requirements => conceptual design => logical design => physical design.
 - Data requirements: User should be able to place an order, or save their order.
 - Conceptual Data Model: The main categories should be able to be understood by people like customers, orders, and products. 
	 - Also known as conceptual schema.
	 - The provide a high level description of data requirements.
	 - They've sysematic mapping to have a detailed model.
 - Logical Data Model: They should be understood by managers, and it provides more information about information about the 3 entities
	 - Also known as logical schema.
	 - They represent the data strucutres that will eventually be implementd into the database - agnostic to the DBMS.
	 - They include info about the the entities and their relationship.
 - Physical Data Model: The last step before the database, and provides information about the database will be modeled.
	 - Represents the data structures as they will be implented to a specific DBMS.

Conceptual: Only contains the information in table
Logical: Contains information about the structures like FK/PK etc
Physical: Contains information about the varchar, int and the types.


Entity-Relationship(ER):
 -  Suppose we have an online bussines. We will have a cusotmer, order and a product, and these are called the entities. 
 - Each entitiy will have certain characteristics, and these are called the attributes
	 - Customers: Name, phone number, and delivery address (cusomter id)
	 - Order: reference no, shipping date (order id)
	 - Products: quantity, type (product id)
 - At least one of the attributes should be unique- which is called the identifies
	 - they marked in the diagram with an identifier.
- There are different types of attributes.
	-  Compositve and Simple/atomic
	- Single valued and multi-valued
	- Stored and Derived
	- Null valued and Complex valued(composite and multivalued)
		- Examples:
			- Composite: name(first and last), delivery (house no, postcode)
			- Simple/Atomic: customer id
			- Single valued: membership type
			- Multivalued: telphone { phone, landline}, email {different emails}
			- Stored: DOB
			- Derived: Current Age
			- NULL-valued: Membership points {they may not be in a membership}
			- Complex valued: preferred delivery details {emails, with their house address}
- A relaionship is where it connects two or more entities with meaning. It is called binary when two, and tertiary when three.