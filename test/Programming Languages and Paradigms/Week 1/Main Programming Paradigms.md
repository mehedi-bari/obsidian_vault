What are the main programming paradigms and sub-paradigms?
- Imperative
	- Programmer describes the sequence of statements manipulating the program state. It is like following a receipe.
	- EXAMPLES:
		- Structured(or procedural)
		- Object Oriented
		- Concurrent
- Declarative
	- The programmer here describes the meaning/results of computations.
	- A really good example is HTML!
	- They have a higher level of abstraction, which means it can be never convulted when the program becomes big.
	- They're usually used for document reading, and sturctured data storage.
	- EXAMPLES: 
		- Functional
		- Concurrent

Imperative - Structured: 
	-  Previously, if you look at machine language at Intel assembly language. There are loads of jumps and  calls, which created an unstructured, and spaghetti like structure. 
	- There wasn't any control flow operations. The imperative system added loops, which brought order.
	- Some examples of Imperative lanauges are C and Fortran.

Imperative - OOP:
	- Encapsulation of code and the associated data into objects.
	- This gives birth to polymorphism, and inheritance. 
	- AD: because it enables control flow, it makes it easier to write large programs and to reason about and understand the code.

Imperative - Concurrent:
	- The concurrrent paradigms explains how to things running at the same time on different cores can communicate with each other.
	- How they can share particular data structures/threads/ processes. 


Declarative - Functional:
	- Calling and composing functions to describes the program.
	- ![[Screenshot 2022-10-05 at 10.37.04.png]]
	- First class or higher order functions are runctions that can be passed on to other function, and functions can also return a function.
	- Loops are usually implemented with recusion.
	- There are only functions so they've no global state, which means it is more secure, and easier to debug.

Declarative - Concurrent:
	- When we need less synchroisation, we can use this model.
	- This means there are no need for locks, and this makes it easier to access.
	-  An example for this is when you get client and server requests.
	-  Soliditiy is a good concurrent language.



![[Screenshot 2022-10-05 at 10.56.23.png]]