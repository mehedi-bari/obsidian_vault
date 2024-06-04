# State Aggregation
We create an interval, and group them together and use this to represent state. Then we can stores this continuous data, in a discrete table. We can choose the number of states. Usually, we can increase the states, which can improve performance, but it can cause large computation and memory costs. 

You can also have multiple states like n-dimensional, and divide the area/volume in a state space. This is more complex, and requires more calculations. e.g. for a n-dimensions, we can use squares.


# Tile Coding 
This is generalisation of state aggregation in which $n$ independent aggregations are created. We compute many different state aggregations, and they're independent of each other. Then we take the **average**.

Step1 : divide each state dimensions into segments
Step 2: expand or shrink the value range.
Step 3: Displace the segments, by a displacement vector. 
Step 4: Repeat steps 1 to 3$n$



This is very slow!