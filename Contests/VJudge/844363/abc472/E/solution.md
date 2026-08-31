[E - Odd Cycle](/contests/abc472/tasks/abc472_e) 题解 作者：[en\_translator](/users/en_translator)
---------------------------------------------------------------------------------------------

* * *

直入正题，以下算法是有效的：

-   取一棵生成树，并为每个顶点赋予颜色 $0$ 或 $1$，使得对于生成树中的所有边 $(u, v)$，都有 $C_u \ne C_v$。
    
-   检查每个未包含在生成树中的边 $(u, v)$。
 
 -   若 $C_u = C_v$，则取生成树上构成 $(u, v)$ 路径的顶点序列，这正是我们所需要的；将其打印出来并终止程序。
        
    -   若 $C_u \ne C_v$，则忽略该边。
 
-   若程序尚未终止，则不存在奇数环。
 

* * *

#### 证明

首先，让我们验证该算法找到的顶点序列是否有效。不难验证它构成一个环。此外，树的颜色交替变化，如 $0, 1, \dots, 1, 0$，因此端点颜色相同意味着顶点个数为奇数。

反之，若该算法未找到环，则所有边 $(u, v)$ 均满足 $C_u \ne C_v$。 这表明遍历一条边时颜色总是会翻转，因此任何始于颜色为 $0$ 的顶点、终于颜色为 $0$ 的顶点的环，其遍历的边数均为偶数（颜色为 $1$ 的情况亦然）。因此，该图不存在奇数环。

* * *

这种“没有奇数环” $\Leftrightarrow$ “可用 $0$ 和 $1$ 上色的”图，被称为 **二部图**。

* * *

示例代码

为简化起见，采用了几个技巧。首先，我们构造一棵生成树并同时检查颜色。

此外，我们不直接在生成树中寻找 $(u,v)$ 路径，而是分别取 $(u,1)$ 路径和 $(v,1)$ 路径，然后剔除分支前的公共部分。

```
def solve():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for i in range(m):
 u, v = map(int, input().split())
        g[u-1].append(v-1)
 g[v-1].append(u-1)
 
 c = [-1] * n
    p = [-1] * n
    c[0] = 0
    
    st = [0]
    while st:
 u = st.pop()
 for v in g[u]:
 if col[v] == -1:
 col[v] = col[u] ^ 1
 par[v] = u
                st.append(v)
 elif col[u] == col[v]:
 a, b = [], []
 
 x = u
 while x != -1:
 a.append(x)
 x = p[x]
    
                x = v
 while x != -1:
 b.append(x)
 x = p[x]
 
 while a[-1] == b[-1]:
 w = a.pop()
 b.pop()
    
                ans = a + [w] + b[::-1]
 print(len(ans))
 print(*[x+1 for x in ans])
 return 
    
    print(-1)
    return 

t = int(input())
for i in range(t):
    solve()
```

发布于：10天前  
最后更新于：10天前