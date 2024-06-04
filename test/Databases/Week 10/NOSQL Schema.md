
		SQL vs NoSQL:
		- It is important to consider the queries, updates, and data processing. 
		- SQL have a document structure, and there is some wiggle room with atomicity.
  
  
		Embedding(Normalisation):
		- Captures relationship between data by storing data in a single document.
		- Acheived by embedding it inside a field or an array.


		Referencing:
		- Stores the relationship between data by
		- 
		- including links or references from one document to another.


		When to embed?
		-  Related items are fetched together e.g. customer, and what products they've ordered.
		- There is one-to-one relationship between two documents, so they're always going to be called together.
		- The document that is embedded is not a key document - which means it isn't called that often
		- If the data is not being altered that much - it is pretty static on the way it is setup.
		- Similar documents have similar volaitity.


		When to reference?
		- When embedding would cause large amount of dupliated ata
		- When embedded documents grow this would be very difficult to rertive the information.
		- To present more one to many or many-to-many relationships
		- The docuemnt is a key document
		- Requires for faster writes.




![[Screenshot 2022-12-01 at 21.44.20.png]]

- ONE TO MANY
![[Screenshot 2022-12-01 at 21.47.22.png]]

- REFERENCING
![[Screenshot 2022-12-01 at 21.49.31.png]]




