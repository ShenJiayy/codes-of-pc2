#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, M = 1e6, mod = 998244353;
int c[N + 5], d[N + 5], inv[M + 5], mul[M + 5], ans = 1;
vector<int> g[N + 5];


// 根据题意，每个结点上都有一只松鼠，并且每个结点的松鼠能够收集的糖果集合可能会与该点的子孙结点中的松鼠能够收集的糖果集合发生冲突。但很明显子孙节点上的松鼠能够收集的糖果集合一定是该点的子集。
// 为了解决冲突，我们可以先让子孙结点的松鼠收集糖果，然后再让当前结点的松鼠在那些剩余的糖果中再进行收集。
// 对于整棵树的收集顺序，可以先让叶子结点的松鼠进行收集，然后再逐步向上依次解决非叶子结点的松鼠，最后解决根结点。

int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
void init() {
    mul[0] = 1;
    for (int i = 1; i <= M; i ++)
        mul[i] = mul[i - 1] * i % mod;
    inv[M] = fp(mul[M], mod - 2, mod);
    for (int i = M - 1; i >= 0; i --)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int dfs(int id) {
    int last = c[id];
    for (int nxt : g[id])
        last += dfs(nxt);
    if (last < d[id]) {
        ans = 0;
        return 0;
    }
    for (int i = last; i > last - d[id]; i --)
        ans = ans * (i % mod) % mod;
    ans *= inv[d[id]], ans %= mod;
    return last - d[id];
}
signed main() {
    init();
	int n;
    cin >> n;
    for (int i = 2; i <= n; i ++) {
        int ft;
        cin >> ft;
        g[ft].push_back(i);
    }
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    for (int i = 1; i <= n; i ++)
        cin >> d[i];
    dfs(1);
    cout << ans;
    return 0;
}
