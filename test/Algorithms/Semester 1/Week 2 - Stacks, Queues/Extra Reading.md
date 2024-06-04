Stacks:
 - Stacks work on the basis of last in first out basis (LIFO.)
 - If you use an array as an implementation:
	 - This results in time complexity of O(n)
	 - However there is a fixed amout of size.
	 - You can fix this by either using a linked list, or making the size of the array big enough
- The push and pop methods: ![[Screenshot 2022-10-07 at 19.03.44.png]] 
- You will find that when working C, and C++ stacks play a really important role in the runtime environment uses stacks.
	- Each thread in the runtime environment has its own private stack called the method stack.
		- The method stack keeps information about the variables.
	- Most importantly, it keeps track of which thread are in operation, and they have descriptors called frames.
	- Each one of these have a special register called the program counter, and this used to find what to return to after.
	- The top of the method stack is called the running stacks, and the non-used ones are called the suspended stack.
	- When a frames finishes, it is poped out of the stack.
				![[Screenshot 2022-10-07 at 19.54.37.png | 400x500]]
Recursion :
