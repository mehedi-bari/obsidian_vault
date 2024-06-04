## What is concurrency?
Concurrency is when multiple parts of a computation happen at the same time. Examples of "parts" might be:
- Instructions
- Threads
- Local Processes
- Remote Processes

And some examples of "computations" are:
- Functions
- Programs
- Distributed Systems (i.e. databases)

## Why use concurrency?
- To maximise resource utilisation
	- Pipelined processors
	- Out-of-order execution
	- Preemption
	- Relaxed consistency (coming up later)
- To increase performance
	- Multicore (only way to achieve high performance with current processors)
	- Massively parallel systems (only way to solve big problems, i.e. supercomputers)
	- Distributed systems (only way to run a global digital service)

## The problem with concurrency?
We don't think about programs concurrently. We expect from our programs that they will be:
- Atomic - That computations will happen in a single moment in time
- Ordered - That computations happen in a specific order

But in reality, even for a single core, local application these are not true:
- Granularity of atomicity - Computations beyond a certain level take time, and a processor will not wait nicely for long running computations when there are other things that may be done
- Interleaving - You cannot simply consider the one order you gave, you must also consider all other **consistent orderings**.

Of course, you **can** assume those things to be true for a single core application because the hardware essentially lies to you and pretends to not be concurrent. That's nice from the perspective of the program, but it is a lie nonetheless.

## Data Races
When two concurrent "parts" of the computation use a common piece of data (a register, a table in a database), the actions can be interleaved in many ways, most of which do not behave how you expect. Consider this function being run concurrently, twice at a time:
```C
int old_a = a;
a = a + 5;
```
This is actually many more instructions from the processor's perspective:
```C
register temp1 = a;
int old_a = temp1;
register temp2 = a;
temp2 = temp2 + 5;
a = temp2;
```
So how can this safely be interleaved?
```C
register temp1 = a;
int old_a = temp1;
register temp2 = a;
temp2 = temp2 + 5;
a = temp2;

register temp1 = a;
int old_a = temp1;
register temp2 = a;
temp2 = temp2 + 5;
a = temp2;
```
One after the other works fine.
```C
register temp1 = a;
int old_a = temp1;
register temp2 = a;
temp2 = temp2 + 5;

register temp2 = a;

a = temp2;

temp2 = temp2 + 5;

register temp1 = a;
int old_a = temp1;
register temp2 = a;
```
But this breaks it. Or is any one of these really the "correct" outcome in the first place?
Somehow the program needs to describe the constraints on interleaving and thus make the "correct" outcome explicit. In high level languages, this may be handled by safety/liveness properties (this comes later), and in low level languages there needs to be added code to coordinate the "parts" of the computation and ensure a partial order.

## Software Concurrency
- Threads
	- Independent streams of computation with shared state (same memory)
	- Interactions between threads is implicit: **they are reading/writing to the same data**
	- Coordination must be explicit
	- Communication is quick, and simple, but can be dangerous when trying to stop them from communicating from each other.
	- They can't access each other's **stack**.
- Processes
	- Each process has its own internal state
	- Interactions between processes are explicit; messages must be passed
	- They only communicate over things that the programmer wants to communicate.
	- Less coordination is needed.
	- Very Slow, and Very expensive.
- Nothing? (Let the compiler figure it out)
	- Very difficult to implement, though easier for functional languages.
	- Would be ideal if only it weren't so hard.

## Thread-based concurrency
The Basic coordination principle for threads is that access is shared only in **critical sections**. Only one thread is allowed in each critical section. Therefore, ciritical sections are effectively **atomic**.

We need two sections that makes it mutally exclusive:
- _preprotocol_ $\rightarrow$ confirms it is safe to enter or wait
- _postprotocol_ $\rightarrow$ announces that it is safe for others to enter

It is important that waiting time must be **limited**. A critical section has to always complete, otherwise it leads to **starvation**. It should be ideally **short** and **minimal** , which leads to faster code.

There used to be a problem which reading and writing atomic variabes that control access to the critical section. However it is not an issue due to atomic instructions:
- Exchange $\rightarrow$ swap two memory locations.
- Fetch-And-Add $\rightarrow$ read, then add, them write back.
- Compare-And-Swap(CAS) $\rightarrow$ modify a variable only if it has a certain value, and return the old value.

```c++
int CAS(int* com, int old, int new) {
	atomic {
		int temp = *com;
		if (temp == old) *com = new;
		return temp;
	}
}
```
![[Screenshot 2023-04-13 at 12.42.51.png]]


#### Locks:
Controls access to ciritcal section
acquire()/lock():
- Asks for access to critical section.
- Go to sleep if occupied.
release()/unlock():
- Leave ciritical section
- Wake up threads sleeping on this lock.
![[Screenshot 2023-04-13 at 12.48.56.png]]
Sleep instead of keep trying $\rightarrow$ better utilisation, energy efficency, **avoids starvation**

#### Semaphores:
Control concurrent access to a limited resource
wait():
- Acquires the resouces.
- Decrements a counting variable(which indicates the availaiblity of the resouce) if positive.
- Otherwise sleep.
signal():
- Releases the resource.
- Increments the counting variable if positive.
- Otherwise, wake up a thread.

>Semaphores limit the number of threads working on a resource.
   They allow threads to communicate with each others, and they can coordinate a shared space, and go to sleep if no resource is available. Then wake up if something changes.

#### Monitors
Mutual exclusion to an objection(monitor lock)
Plus support for signalling (monitor condition variable)
wait():
- Called when a condition is true(like the buffer is full)
- This condition incicates whether the computation can progress.
- Joins the waiting queue, releases the monitor lock, and sleep.s
signal()/notify():
- Called by a thread when it makes the condition true.
- The front of the waiting queue wakes up


## Process-baed concurrency:
Thread-based based concurrency is good because it has low overhead, but it isn't always possible like in multi-node systems. It also hard to reason about the correctness.

Process communicate via messages. Everything between two messages is effectively atomic. Mesages are exchanges connects processes.

Remote Procedure Calls(RPC):
- Sender waits for receiver to reply e.g. Solidity, web applications
- They don't run at the same time.
- It is the simplest one to reason about, but little concurrency.
- Send and reply are atomic.

Synchronous Messages:
- Sender waits, for receiver to get the message, e.g. Go, Python Pipes
- The idle period is shorter than RPC.
- It is still easy to reason about, but a lot of communication overhead.
- When send() returns, we know the message has been recieved.
- Send is atomic, reply is atomic, but state might have changed between them.

Asynchronous Messages (AS):
- Sender sends the messsage and continues execution immediately.
- It is not as easy to reason about, but minimal communication overhead.
- No guarantee that the message is received 
- Buffers are needed for managing messages.

The choice is critical for the concurrency semantics of the program.
![[Screenshot 2023-04-13 at 14.10.58.png]]


## High Level Concurrency:
Threads uses mutal exclusion $\rightarrow$ it is tedious because you need to identify all the critical sections, and then can be solved then. Therefore it can be hard to get right.
Processes uses message passing $\rightarrow$ it is also very tedious and can be slow 

They do not solve high-level concurrency bugs:
- Deadlock $\rightarrow$ cycle of processes all wait for the next process in the cycle to leave a critical section.
- Livelocks $\rightarrow$ cycle of processes all try to enter a critical section but they all fail.
- Starvation $\rightarrow$ procces cannot progress, waiting forever to enter a critical section.
- Incosistent states are still possible. 

The main strategy is that we need to reason about the program's correctness:
-  **Safety properites** $\rightarrow$ should alway be true.
	- Like in the case of the philosopher, they should never have the same chopstick
- **Liveness property** $\rightarrow$ should eventually be true
	- every philosopher will eat noodles.

