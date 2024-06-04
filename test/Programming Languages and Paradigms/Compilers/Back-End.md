We are now done with the front/middle-end and have reached the back-end, and we have some (partially) optimised IR that needs to be converted to the final target code. The broad strokes of this issue are:
- We need to select the right instructions in the target language - this is a pattern matching problem
- We need to perform further optimisations, this time according to the specific capabilities of the target platform

The concrete steps involved in the back-end are:
- Instruction selection: map the intermediate representation into target code
- Register allocation: Decide which values will reside in which registers (only applies to an assembly/machine code target)
- Instruction scheduling: Reorder operations to hide latency (e.g. in pipelined and superscalar systems)

We could solve all of these independently, but they all end up being inter-related.

## Instruction Selection
This step is essentially pattern matching; we need to match certain IR patterns to snippets of target code. It is easy to make locally optimal choices (i.e. just choose the most optimal instructions for the current pattern) but making a globally optimal program is an NP-complete problem. Note that in this step we assume we have enough registers to represent all values.
For ongoing examples, assume a RISC-like target language defined like this:
![[Screenshot 2023-04-05 at 17.18.19.png]]
#### Arithmetic expressions
We can adopt a simple tree walk scheme, and emit code in **post-order**:
![[Screenshot 2023-04-05 at 17.21.02.png]]
This (extremely simple) method simply represents each variable as a load from memory, and each operator as the corresponding operation. Any literals are also loaded into a register. This method demonstrates some issues that must be handled when generating code for arithmetic expressions:
- What about values that have already been loaded into registers?
	- We need to modify the IDENTIFIER case.
- Why evaluate the left subtree first and not the right?
	- You should evaluate the most demanding (i.e. requiring the most registers) subtree first (this is the Sethi-Ullman labelling scheme)
- You might need a second pass to minimise register usage and improve performance.
- The compiler could also be taking advantage of commutativity and associativity for integers to improve code.
- You might also be able to reduce multiplications down to shifts and adds, depending on the values in the expressions. For example:
	- $325x = 256x+64x+4x+x$ 
	- On some systems, integer multiplication may be significantly slower than other operations.

#### Array references
The compiler needs to decide on a memory storage scheme for N-dimensional array elements:
- Row-major order: store as a sequence of consecutive rows (most common)
	- `A[1, 1], A[1, 2], A[1, 3], A[2, 1], A[2, 2], A[2, 3]`
	- Derive an element's place with the formula $\text{baseAddr} + w\cdot(i\cdot(m+1)+j)$ where n, m are the array sizes `[n][m]`, i, j are the desired locations `[i][j]` and w is the size of an element.
- Column-major order: store as a sequence of consecutive columns (FORTRAN does it this way):
	- `A[1, 1], A[2, 1], A[3, 1], A[1, 2], A[2, 2], A[3, 2]`
	- Derive an element's place with the formula $\text{baseAddr} + w\cdot(j\cdot(m+1)+i)$ where n, m are the array sizes `[n][m]`, i, j are the desired locations `[i][j]` and w is the size of an element.

#### Control Flow
- `if expr then stmt1 else stmt2`
	1. Evaluate the expression to true or false
	2. If true, fall through to the `then` block, otherwise branch to the else
	3. If false, branch to the else, otherwise fall through to the `then` block
- While loop, for loop, do loop (e.g. `while (expr) do stmt`)
	1. Evaluate expr
	2. If false, branch beyond the end of the loop, if true fall through to stmt
	3. At the end of stmt, re-evaluate expr
	4. If true, branch to the start of the loop, if false, fall through
- Complex boolean expressions can also be evaluated using treewalk, but it requires more. For example:
	- Short-circuiting. the expression `x != 0 && y / x > 1` **requires** short circuiting to prevent a divide by zero. May also apply to higher-level things, e.g. `while (file.notEmpty() && file.readByte() != "\0")` requires short circuiting to prevent the program from trying to read past the end of a file.

#### Procedures/Functions/Methods
Procedures are fundamental to building complex software, but they are a high-level abstraction that has no analogue in low-level hardware. The compiler needs to generate code that emulates the behaviour of procedures. For each call, the calling method must arrange some memory in preparation for the call (**pre-call**), the called function must set up its own memory for variables and such (**prologue**), the called function must discard its memory after it's done (**epilogue**) and the caller must then clean up the memory it set up for calling (**post-return**).
![[Screenshot 2023-04-12 at 11.59.15.png]]
This is a costly abstraction which the compiler will attempt to avoid if at all possible. For example, the compiler may **inline** some functions, meaning it will insert the function directly into the caller, avoiding all of this calling overhead. This results in code duplication, and the compiler must decide somehow if the trade-off between code size and speed is worth it.

## Register Allocation
The initial code generated by instruction selection makes use of an unbounded number of registers (**virtual registers**) but the true machine only has a limited number. The task of register allocation is to produce code which only uses a limited amount of registers, while minimising the number of loads and stores (**spills**). This step, like all the others, must be efficient.
Assume for this section a RISC-like (that is, three-address) type of code.
#### Definitions
- **Basic Block**: A maximal length segment of code with no branches.
- **Local Register Allocation**: allocating registers within a single Basic Block
- **Global Register Allocation**: allocating registers across an entire procedure (many Basic Blocks).
- **Allocation**: Choosing what to keep in the registers.
- **Assignment**: Choosing which register each allocated value will stay in.
	- Note that modern processors commonly have many classes of registers, e.g. general purpose vs floating point. This can be a complication for allocation and assignment, as there is likely to be interaction between them.
- **Complexity**: Only simplified cases of local allocation and assignment are solvable in linear time; the rest (including global allocation, even for just 1 register) are NP-complete. We need heuristics!

#### Live Ranges
The basic problem is that we need to allocate a number registers for a basic block.
Naive appraoch: All occurences ofa  avariable to the same register.
Realistic: Compute a set of live ranges and use their name space.

A value of a variable is **live** between its definition and its uses:
- From definitions and uses
- From definition to last use is the **live range**
- Can represent live range as an interval $[i ,j]$ in basic block  

Overall we can calculate the number of registers we need to allocate for a basic block using $MAXLIVE$: 
- let $MAXLIVE$ be the maximum number of values live at an instruction.
- $k$, the number of physical registers available.
	- If $MAXLIVE \leq k$ allocation is trivial
	- If $MAXLIVE \ge k$ some values must be saved to memory(**spilling**)

![[Screenshot 2023-04-12 at 12.19.21.png]]



#### Basic Local Register Allocation
Top-down register allocation:
- Reserve the registers for the most frequently used values. All other values are loaded from/stored to memory when needed
- Problem: a value that is heavily used in one part of the code but rarely used in the next part of the code will still occupy a register.

Bottom-up register allocation(Best algo):
- Keep a pool of registers; assign one reigster when  a vlaue is intialised (start of the live range); return register to the pool at the end of the live range.
- If at some point we ened to assign a reigster but there is no register in the pool, select the register that is used farthest in the future, store its value and return it (this is known as spilling.)

#### Register Allocation via graph colouring
The idea is that we can use the live ranges that d onot interfere can share the same reigster. 
The Algorithm:
- Construct live ranges.
- Build interference graph
- Try to construct a k-colouring of the graph.
- Map colours onto physcial registers
#### Building an interference graph
![[Screenshot 2023-04-12 at 12.31.31.png]]

#### Constructing a k-colouring
![[Screenshot 2023-04-12 at 12.33.01.png]]


## Instruction Scheduling
**Instruction Latency**: there is a usually a length of time which has elapsed from the time the insturction was issued until the time the results can be used.
The problem:  Given a code fragment, for some target machine, and letencies for each individual instruction, reorder instructions to minimise execution time.
![[Screenshot 2023-04-12 at 13.00.11.png]]


The process:
- Build a **precedence**(data dependence) graph
- Compute a priority function for the nodes of the graph
- Use list scheduling to construct a schedule, one cycle at a time

#### Building a precedence graph
- [ ] ![[Screenshot 2023-04-12 at 15.12.24.png]]

#### Priority functions
![[Screenshot 2023-04-12 at 15.13.38.png]]

![](Pasted%20image%2020230315132342.png)
## List scheduling
- All the ready operations are collected, and then sorted with the heuristic ofthe heightest weight.
- The one with the highest weight is chosen.
- After a node is completed, new nodes that are dependent on it and now ready are added to the list. 
- This is done recursively until it finishes.
![[Screenshot 2023-04-12 at 15.21.49.png]]

Register allocation interferes with insturction scheduling:
- Register allocation estircts the choices for scheduling. 
- If scheduling is done first it can also effect register allocation but to a lesser extent.
