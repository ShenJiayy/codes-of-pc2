### 问题陈述

给你一个整数 $N$ 和一个长度为 $N - 1$ 的整数序列 $D = (D_1, D_2, \ldots, D_{N-1})$ 。

求满足以下条件的 $(1, 2, \ldots, N)$ 的排列 $P = (P_1, P_2, \ldots, P_N)$ 的模数 $998244353$ 的个数。

- 对于每个 $1 \le i \le N - 1$ ，设 $P_a$ 和 $P_b$ 分别是 $(P_i, P_{i+1}, \ldots, P_N)$ 中数值最大和第二大的元素；然后是 $|a - b| = D_i$ 。

### Constraints

-   $2 \le N \le 2 \times 10^5$
-   $1 \le D_i \le N - i$
-   All input values are integers.

### Input

The input is given from Standard Input in the following format:

```
$N$
$D_1$ $D_2$ $\ldots$ $D_{N-1}$
```

### Output

Output the number, modulo $998244353$, of permutations satisfying the condition.

### 样本输出 1

```
4
```

例如，我们可以验证 $(2, 3, 1)$ 是否满足以下条件。

- 我们有 $(P_1, P_2, P_3) = (2, 3, 1)$ 。最大值为 $P_2$ ，第二大值为 $P_1$ ，以及 $|2 - 1| = 1 = D_1$ 。
    
- 我们有 $(P_2, P_3) = (3, 1)$ 。最大值是 $P_2$ ，第二大值是 $P_3$ ，以及 $|2 - 3| = 1 = D_2$ 。
    

有四种排列满足条件： $(1, 2, 3), (1, 3, 2), (2, 3, 1), (3, 2, 1)$ .因此，输出 $4$ 。