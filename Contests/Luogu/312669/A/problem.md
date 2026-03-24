# P15351 [COCI 2025/2026 #4] 战斧牛排 / Tomahawk

## 题目描述

考虑一个 $n\times n$ 的矩阵 $A$，初始时 $A$ 中元素全为零。

以下约定：横行竖列；行从上到下编号 $1\sim n$，列从左到右编号 $1\sim n$。

$q$ 次操作：

- $\texttt{L}$ $x$：这里，$1\le x\le \lfloor \frac{n+1}{2}\rfloor$。
    - 对于 $i=1,\ldots,x$，将第 $i$ 列的所有格子加上 $(x-i+1)$。
- $\texttt{R}$ $x$：这里，$1\le x\le \lfloor \frac{n+1}{2}\rfloor$。
    - 对于 $i=1,\ldots,x$，将第 $(n-i+1)$ 列的所有格子加上 $(x-i+1)$。
- $\texttt{D}$ $x$：这里，$1\le x\le n$。
    - 对于 $i=1,\ldots,x$，将第 $(n-i+1)$ 行的所有格子加上 $(x-i+1)$。

在操作完后，求出矩阵的极差（最大值与最小值之差）。

## 输入格式

第一行，两个正整数 $n,q$（$1\le n\le 10^9$，$1\le q\le 10^5$）。

接下来 $q$ 行，每行一个字符 $s$ 和一个正整数 $x$。其中，$s\in \{\texttt{L},\texttt{R},\texttt{D}\}$。
- 当 $s=\texttt{D}$ 时，$1\le x\le n$；
- 否则，$1\le x\le \lfloor \frac{n+1}{2}\rfloor$。

## 输出格式

输出一行一个整数，表示极差（最大值与最小值之差）。

## 输入输出样例 #1

### 输入 #1

```
4 2
L 2
R 1
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
3 3
R 2
D 3
R 2
```

### 输出 #2

```
6
```

## 说明/提示

### 样例解释

样例一解释：

$\begin{bmatrix} 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 \end{bmatrix} \rightarrow \begin{bmatrix} 2 & 1 & 0 & 0 \\ 2 & 1 & 0 & 0 \\ 2 & 1 & 0 & 0 \\ 2 & 1 & 0 & 0 \end{bmatrix} \rightarrow \begin{bmatrix} 2 & 1 & 0 & 1 \\ 2 & 1 & 0 & 1 \\ 2 & 1 & 0 & 1 \\ 2 & 1 & 0 & 1 \end{bmatrix}$ 

样例二解释：

 $\begin{bmatrix} 0 & 0 & 0 \\ 0 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix} \rightarrow \begin{bmatrix} 0 & 1 & 2 \\ 0 & 1 & 2 \\ 0 & 1 & 2 \end{bmatrix} \rightarrow \begin{bmatrix} 1 & 2 & 3 \\ 2 & 3 & 4 \\ 3 & 4 & 5 \end{bmatrix} \rightarrow \begin{bmatrix} 1 & 3 & 5 \\ 2 & 4 & 6 \\ 3 & 5 & 7 \end{bmatrix}$ 



### 子任务

| 子任务编号 | 满分 | 限制 |
| :-: | :-: | :- |
| $1$ | $7$ | $n,q\le 20$ |
| $2$ | $22$ | $n,q\le 100$ |
| $3$ | $31$ | $n\le 1000$ |
| $4$ | $6$ | $n$ 为偶数 |
| $5$ | $4$ | 无额外限制 |