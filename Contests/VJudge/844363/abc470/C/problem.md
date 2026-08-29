# abc470 - C

## 问题陈述

给定一个长度为 $N$ 的整数序列 $A=(A_1,A_2,\ldots,A_N)$。初始时，$A$ 的所有元素均为 $0$。

你将收到 $Q$ 个查询，需按顺序处理。查询分为两类，每类查询均采用以下其中一种格式给出：

-   `1 x`：将 $A_x$ 的值增加 $1$。
-   `2`：对于每个 $i=1,2,\ldots,N$，若 $A_i \geq 1$，则将 $A_i$ 的值减少 $1$。

请在处理完每个查询后，立即计算 $A_1, A_2, \ldots, A_N$ 的位异或（$\mathrm{XOR}$）。

> 什么是位异或（$\mathrm{XOR}$）？
> 非负整数 $A$ 和 $B$ 的位异或，记作 $A \oplus B$，定义如下：
> -   在 $A \oplus B$ 的二进制表示中，若 $A$ 和 $B$ 的二进制表示中，位于 $2^k$ 位（$k \geq 0$）的数字恰好有一个为 $1$，则该位为 $1$；否则为 $0$。
>
> 例如，$3 \oplus 5 = 6$（二进制表示为：$011 \oplus 101 = 110$）。
更一般地，$k$ 个非负整数 $p_1, p_2, p_3, \dots, p_k$ 的位运算 $\mathrm{XOR}$ 定义为 $(\dots ((p_1 \oplus p_2) \oplus p_3) \oplus \dots \oplus p_k)$，并且可以证明该值不依赖于 $p_1, p_2, p_3, \dots, p_k$ 的顺序。


## 要求

-   $1\le N\le 5\times 10^5$
-   $1\le Q\le 5\times 10^5$
-   $1\le x\le N$
-   所有数均为整数.

## 输入

The input is given from Standard Input in the following format:

```
$N$ $Q$
$\text{query}_1$
$\text{query}_2$
$\vdots$
$\text{query}_Q$
```

Each query is given in one of the following $2$ formats:

```
$1$ $x$
```
```
$2$
```

### Output

Output $Q$ lines.

The $i$\-th line $(1\le i\le Q)$ should contain the bitwise $\mathrm{XOR}$ of $A_1,A_2,\ldots,A_N$ for $A$ immediately after processing the $i$\-th query.

### Sample Input 1

```
2 5
1 2
1 2
1 1
2
2
```

### 输出示例 1

```
1
2
3
1
0
```

处理完第一个查询后，$A=(0,1)$。$0$ 与 $1$ 的按位 $\mathrm{异或}$ 运算结果为 $1$，因此第一行输出 $1$。

处理完第二个查询后，$A=(0,2)$。$0$ 与 $2$ 的位或运算结果为 $2$，因此第二行输出 $2$。

处理完第三个查询后，$A=(1,2)$。$1$ 与 $2$ 的位或运算结果为 $3$，因此第三行输出 $3$。

处理完第四个查询后，$A=(0,1)$。$0$ 和 $1$ 的位异或运算结果为 $1$，因此第四行输出 $1$。

处理完第五个查询后，$A=(0,0)$。$0$ 和 $0$ 的位异或运算结果为 $0$，因此第五行输出 $0$。

### Sample Input 2

```
3 8
1 2
1 3
1 1
1 2
1 1
2
1 3
1 1
```

### Sample Output 2

```
1
0
1
2
1
0
1
2
```