Take this example of a linear programming problem:
![[Screenshot 2023-03-28 at 17.00.10.png]]

First, we convert this into **slack form**:
- All the constraints are equalities (apart from the non-negativity constraint)
- In each equation there is a variable that appears only in that eqation and whose coefficient is 1.
Each of these formulae are inequalities, so they have a sort of "slack"; in the first equation, $-x_1 + x_2$ could equal 11, or 10, or 9, etc. In order to convert into slack form we want to convert every equation into an equality, so how do we represent this slack without an inequality? Introduce a **slack variable** to represent the amount that the left hand side of the equation is falling short of the right hand side:

![[Screenshot 2023-03-28 at 17.01.19.png]]

Using these equalities instead of the previous inequalities gives this slack form problem:![[Screenshot 2023-03-28 at 17.05.59.png.png]]A problem is in **slack form** if all of the constraints are equalities (apart from the non-negativity constraints), and each equation contains a **slack variable** which appears only in that equation and whose coefficient is 1.
Some more terminology:
- Slack variables are also called "basic variables"
- The other variables are called "non-basic variables"
- The solution where every non-basic variable is zero is called the "basic solution"

## Pivoting
Now that we have our problem in slack form, we can use a technique called **pivoting**. First, add every slack variable to every equation. Continuing on from the previous example:
![[Screenshot 2023-03-28 at 17.15.01.png]]
Lets also rewrite the objective function to make it match the format of the other equations:
![[Screenshot 2023-03-28 at 17.17.27.png]]

We can now represent this as an augmented matrix:
![[Screenshot 2023-03-28 at 17.17.49.png]]
And here is the objective function (note that the coefficient of the z is omitted)

So we have this representation of the problem:
![[Screenshot 2023-03-28 at 17.32.57.png]]
First, we have to pick the column that we want to pivot on. We use a simple heuristic; pick the objective function's largest value (that is, the one with the highest magnitude) and we decide to pivot on that column. In this example $-6$ is the largest, so we pivot on the $x_2$ column.

![](Pasted%20image%2020230307122308.png)
Now that we've chosen which non-basic variable we're going to swap, we have to chose the basic variable to swap it with. For each entry in the column, divide the value at the right by the value in the selected column; this is the **slack**. We select the row with the smallest slack, making the intersection of the selected column and row the **pivot**. In this example, we choose the $s_1$ row.![[Screenshot 2023-03-28 at 17.34.48.png]]
Our next objective is to manipulate this column such that the selected pivot has a value of 1 and the other values in the column are 0. We can only change each row by adding (or subtracting) multiples of the selected row, meaning many values that aren't in the selected row or column will also be changed. 
In this example, the pivot is already 1 so we don't need to change it. We must reduce the value in the second row by 1, so we replace it with $R_2 - 1R_1$. We must reduce the value in the third row by 5, so we replace it with $R_3 - 5R_1$. We must also increase the value in the objective row by 6, so we replace it with $R_\text{Obj} +6R_1$.
![](Pasted%20image%2020230307123454.png)
At the end of this iteration, we can read off a basic solution from the right of the matrices:![[Screenshot 2023-03-28 at 17.41.01.png]]
When $x_2 = 11, s_2 = 16, s_3 = 25$, 
the objective function (or the value of $z$, if you like) has become $66$.

We repeat this pivoting process until we reach the optimal solution; you know you have reached the optimal solution when there are no more negative numbers in the objective row.

We select $x_1$, as it's the only negative value!

Some more rules are shown here:
- You must select a negative number when deciding on the pivot column.
- You cannot pivot on a row with negative slack. (in this example, the first row where slack is $\frac{11}{-1}$.)

The $s_3$ row has the smallest slack, so we select this row for a pivot and then pivot. We divide the third row by seven to make the pivot equal 1, then make the other values 0 by adding multiples of the pivot row:
![[Screenshot 2023-03-28 at 17.53.38.png]]
We now have another basic solution, better than the last. However we still aren't finished, as there is still a negative value in the objective row. Some other notes:
- You can use the pivot row from either the old or new table if you would like. Usually using the new table is easier, since you just made it equal to 1, but this may not always be the case (such as in this example, where some similar fractions appear in the old table.)

With this in mind, we apply the final iteration, using the old value of the row instead to simplify calculations:
![[Screenshot 2023-03-28 at 18.08.00.png]]
There are no more negative numbers in the objective row; this is the optimal basic solution. We can read off the optimal values to get:
$x_1 = 15, x_2 = 12$
$s_1 = 14, s_2 = 0, s_3 = 0$
$z = 132$
The slack values are irrelevant to the original problem, so they can be discarded. 
#### Why do we stop pivoting?
Our rule is that we stop pivoting when the objective row contains no negative values. FBut why does this work? Consider that these rows represent equations. That first example can be written as:
$z -10x_1 + 0x_2 + 6s_1 + 0s_2 + 0s_3 = 66$
Remember the non-negativity constraints; $x_1$ and $x_2$ is either 0 or a positive number; a negative coefficient in this formula is subtracting a positive number from $z$, thus reducing $z$'s value. If we want to maximise $z$, we therefore need to remove these negative coefficients.

## Special Cases
#### The origin isn't a feasible solution Artificial Variables)
Consider the following example:
![[Screenshot 2023-03-29 at 10.10.19.png]]
The second constraint removes the origin from the set of feasible solutions. The graph looks like this:
![[Screenshot 2023-03-29 at 10.14.07.png]]
If we convert this to slack form and try to solve using simplex, we get this tableaux:![[Screenshot 2023-03-29 at 10.14.21.png]]
Our basic solution does **not** satisfy the non-negativity constraints.
The solution is to add some new variables called **artificial variables** that will allow $x_1=0, x_2=0$ to be a valid solution to any of the equations where this problem arises. We then penalise the inclusion of these variables in the the objective function, so that they will go to 0 when the optimal solution is reached.
So, lets add an artificial variable to the problem equation:
![[Screenshot 2023-03-29 at 10.36.57.png]]
We add this artificial variable to the objective function, multiplied by a coefficient M1 which we take to be arbitrarily large. Here is the tableaux:
![[Screenshot 2023-03-29 at 10.37.23.png]]
![](Pasted%20image%2020230314141315.png)
First step is to pivot on column with $M_1$ in it. The only row with a usable slack is the second one (and it will always be the one corresponding to the equation with the artificial variable in it), so pivot on that row.![[Screenshot 2023-03-29 at 10.42.18.png]]Remember that $M_1$ is an arbitrarily large number. We now begin simplex as usual, in this case picking $-3-2M_1$ as the pivot column as it is the most negative (highest negative amount of the arbitrarily large $M_1$)

![[Screenshot 2023-03-29 at 10.43.29.png]]

The final solution is $x_1=10, x_2=0$. The value of the artificial variable can be ignored.
#### The solution space is unbounded
Consider this example:

![[Screenshot 2023-03-29 at 10.44.47.png]]
When drawn as a graph, it looks like this:
![[Screenshot 2023-03-29 at 10.45.18.png]]
You can see that the solution space goes on forever. If you attempt to solve this with the regular method, you will eventually reach a situation where all of the slacks are negative, thus making it unsolvable. Simplex cannot solve unbounded problems; if you encounter one, it is most likely that a constraint is missing.
You can tell if the solution space is there exists a valid entering variable (i.e. a column with a negative value in the objective row) where all of the co-efficients in that column are negative. For example:![[Screenshot 2023-03-29 at 10.56.46.png]]You can tell this is an unbounded problem because $x_1$ is a valid entering variable but all of its coefficients are negative.

#### There is zero slack (degeneracy)

The rule is that you can pick a row with zero slack if the co-efficient for the entering variable is positive (the number you divided by to get the slack, the one in the crossover between the row and column). If none of the zero slack rows have a positive entering variable, then we can choose the entering variable with the smallest positive slack.

