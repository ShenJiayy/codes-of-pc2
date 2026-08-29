### 问题陈述

给定一个 $(1, \dots, N)$ 的排列 $P = (P_1, \dots, P_N)$。

按顺序处理 $Q$ 个查询。查询分为以下两种类型：

-   `1 x y`：交换 $P_x$ 和 $P_y$ 的值。
-   `2`：构造满足以下条件的 $(1, \dots, N)$ 的排列 $P' = (P'_1, \dots, P'_N)$，并将 $P_1, \dots, P_N$ 的值分别替换为 $P'_1, \dots, P'_N$。（可以证明这样的 $P'$ 唯一存在。）
    -   对于满足 $1 \leq i \leq N$ 的每个整数 $i$，有 $P_{P'_i} = i$。

处理完所有查询后，输出 $P_1, \dots, P_N$ 的值。


### Constraints

-   $2 \leq N \leq 5 \times 10^5$
-   $1 \leq Q \leq 5 \times 10^5$
-   $(P_1, \dots, P_N)$ is a permutation of $(1, \dots, N)$.
-   $1 \leq x < y \leq N$ for queries of type $1$.
-   All input values are integers.

### Input

The input is given from Standard Input in the following format:

```
$N$ $Q$
$P_1$ $P_2$ $\cdots$ $P_N$
$\mathrm{query}_1$
$\vdots$
$\mathrm{query}_Q$
```

Here, $\mathrm{query}_q$ represents the $q$\-th query, and is given in one of the following two formats:

```
$1$ $x$ $y$
```
```
$2$
```

### Output

Output the values of $P_1, \dots, P_N$ after processing all queries, separated by spaces, on one line.

### Sample Input 1

```
5 5
2 1 3 5 4
1 2 4
2
1 2 3
1 3 4
2
```

### 输出示例 1

```
4 5 2 1 3
```

在处理完每个查询后，$P_1, \dots, P_N$ 的值如下：

-   处理完第一个查询后，$P = (2,5,3,1,4)$。
-   处理完第二个查询后，$P = (4,1,3,5,2)$。
-   处理完第三个查询后，$P = (4,3,1,5,2)$。
-   处理完第四个查询后，$P = (4,3,5,1,2)$。
-   处理完第五个查询后，$P = (4,5,2,1,3)$。

### Sample Input 2

```
7 4
3 7 5 6 4 2 1
2
2
2
2
```

### Sample Output 2

```
3 7 5 6 4 2 1
```

### Sample Input 3

```
10 8
7 3 2 4 8 5 10 9 1 6
2
1 4 10
1 6 9
2
1 9 10
1 3 10
2
1 4 6
```

### Sample Output 3

```
3 10 2 8 6 7 1 5 9 4
```