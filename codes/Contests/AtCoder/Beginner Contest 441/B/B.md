# B-Two Languages
> Notice
Time Limit: 2s
Memory Limit: 1024 MiB
Score: $200$ points

## Problem Statement
The AtCoder country has two offical languages, Takahashi-go and Aoki-go.
Both Takahashi-go and Aoki-go use some lowercase English letters to write words in those languages.
Takahashi-go uses only the characters contained in a string $S$ of length $N$, and Aoki-go uses only the characters contained in a string $T$ of length $M$.
You are given $q$ words $w_1, w_2, ..., w_q$ that are int the offical languages of the AtCoder country. For each word, characters contained in that word:
- It's confirmed to be a word in Takahashi-go
- It's confirmed to be a word in Aoki-go
- Neither can be determined.

## Contriaints
- $1\le N, M \le 26$
- $1\le Q\le 100$

## Input
From the Standard Input.
Format as:
```
n m
s
t
q
$w_1$
...
$w_q$
```

## Output
Print $q$ lines.
The $i$-th line should co