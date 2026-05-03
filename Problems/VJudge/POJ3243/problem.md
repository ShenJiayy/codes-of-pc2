# POJ3243 - Clever Y
## Desription
Little Y finds there is a very interesting formula in mathematics: 
$X^Y \mod Z = K$.

Given $X, Y, Z$, we all know how to figure out $K$ fast. However, given $X, Z, K$, could you figure out $Y$ fast?

## Input
Input data consists of no more than $20$ test cases. For each test case, there would be only one line containing $3$ integers $X, Z, K$ $(0 \le X, Z, K \le 109)$.

Input file ends with $3$ zeros separated by spaces.

## Output
For each test case output one line. Write `"No Solution"` (without quotes) if you cannot find a feasible $Y$ $(0 \le Y < Z)$. Otherwise output the minimum $Y$ you find.