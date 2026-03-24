# A-Black Square
> Notice
Time Limit: 2s
Memory Limit: 1024 MiB
Score: $100$ Points

## Problem Stament
There is a grid with $10^{100}$ rows and $10^{100}$ columns.
In what follows, the ceil at the $i$-th row from the top and $j$-th column from the left is denoted as ceil $(i, j)$
In this grid, only the $100\times 100$ rgion with ceill $(p, q)$ as the top-left ceil is painted black, and all other ceils are painted white.
Determine whether ceil $(i, j)$ is painted black.

## Constraints
- $1\le p, q, i, j\le 10^4$
- $p, q, i, j$ are intergers.

## Input
Given from Standard Input.
Format as:
```
p q
x y
```

## Output
If the ceil $(i, j)$ is painted black, print `Yes`; otherwise, print `No`.

## Sample Inputs & Outputs
```
See ./sample/
```