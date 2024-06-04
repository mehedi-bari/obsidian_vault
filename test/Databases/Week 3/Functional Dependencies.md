What is Functional Dependency?
- It is a constraint between two sets of attributes in a relation from a database.
- This is when one set of attributes determines the outcome of the other set of attributes
- X, Y are subsets of R, where R is the relation.
	- X --> Y
	- X is the determinant, and Y is the dependent.

What are the Advantages of FD?
- Helps reduces data reduntancy.
- Maintains the quality of the database.
- It helps determine relations and constraints.

![[Screenshot 2022-10-13 at 22.01.16.png]]



![[Screenshot 2022-10-13 at 22.02.19.png]]


![[Screenshot 2022-10-13 at 22.03.09.png]]



What is a Functional Dependency closure?
- F^+ or functional dependency closure is all the fuctional dependency that can be derived, given a set of FDs F.
- By given these, we can normalise the database.


What is the attribute closure dependency X^+?
- X^+ of an attribute set X are all the attributes that can be functioanlly determined from X.
- By determining the closure of X, we can find all the keys for the relation.
- ![[Screenshot 2022-10-13 at 22.19.00.png]]

-  All attributes must be functionally dependent on the key.
- ![[Screenshot 2022-10-13 at 22.31.43.png]]
- The primary key is chosen which consists of the minimal number of attributes to lead to all the attributes.
- ![[Screenshot 2022-10-13 at 22.32.06.png]]


