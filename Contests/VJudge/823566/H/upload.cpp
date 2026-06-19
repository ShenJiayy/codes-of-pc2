#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4, mod = 998244353;
vector<int> g[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
const int inv2 = fp(2, mod - 2, mod);
int son[N + 5], anc[N + 5], belong[N + 5], direct[N + 5];
bool vis[N + 5], valid[N + 5];
void init(int id, int ft, int bel) {
    if (vis[id] || id == 1) return ;
    vis[id] = son[id] = 1;
    anc[id] = anc[ft] + 1;
    if (ft == 0)
        valid[id] = 1;
    else valid[id] = 0;
    belong[id] = bel, direct[id] = valid[id];
    for (int nxt : g[id]) {
        init(nxt, id, bel);
        son[id] += son[nxt];
    }
}
namespace inTree {
    int ans[N + 5];
    bool vis[N + 5];
    void solve(int id) {
        if (vis[id]) return ;
        if (id == 1) return ;
        vis[id] = 1;
        ans[id] = son[belong[id]] + anc[id] - son[id] + 1, ans[id] %= mod;
        ans[id] *= inv2, ans[id] %= mod;
        for (int nxt : g[id]) 
            solve(nxt);
    }
}
// 垃圾代码请重构43-62
namespace ouTree {
    int ans[N + 5];
    bool vis[N + 5];
    void add(int id, int val) {
        if (vis[id]) return ;
        if (id == 1) return ;
        vis[id] = 1;
        ans[id] += val;
        for (int nxt : g[id])
            add(nxt, val);
    }
    void solve() {
        for (int s : g[1])
            for (int t : g[1])
                if (s != t) {
                    memset(vis, 0, sizeof vis);
                    add(t, direct[t] * (son[t] - 1) % mod * fp(direct[s] + direct[t], mod - 2, mod) % mod);
                }
    }
}
int ans[N + 5];
void merge(int n) {
    for (int i = 1; i <= n; i ++)
        ans[i] = inTree::ans[i] + ouTree::ans[i] + 1, ans[i] %= mod;
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    direct[1] = 1;
    for (int nxt : g[1]) 
        init(nxt, 0, nxt);
    for (int nxt : g[1]) 
        inTree::solve(nxt);
    ouTree::solve();
    merge(n);
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << " ";
    return 0;
}
