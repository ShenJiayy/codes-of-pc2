#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, lgN = 20;
vector<int> g[N + 5], g1[N + 5], g2[N + 5];
int n, dfn[N + 5], st[N + 5][lgN + 5], tmpstmp, dep[N + 5], ts[N + 5], ans[N + 5], s[N + 5], t[N + 5], dis[N + 5], buck1[N + 5];
unordered_map<int, int> buck2;
namespace lca {
    int get(int x, int y) {
        if (dfn[x] < dfn[y]) return x;
        return y;
    }
    void dfs(int id, int ft) {
        st[dfn[id] = ++ tmpstmp][0] = ft;
        dep[id] = dep[ft] + 1;
        for (int nxt : g[id])
            if (nxt != ft)
                dfs(nxt, id);
    }
    int query(int l, int r) {
        int sz = log2(r - l ++);
        return get(st[l][sz], st[r - (1 << sz) + 1][sz]);
    }
    int solve(int x, int y) {
        if (x == y) return x;
        int u = dfn[x], v = dfn[y];
        if (u > v) swap(u, v);
        int sz = log2(v - u);
        u ++;
        return get(st[u][sz], st[v - (1 << sz) + 1][sz]);
    }
    void init() {
        dfs(1, 0);
        for (int i = 1; (1 << i) <= n; i ++)
            for (int j = 1; j <= n - (1 << i) + 1; j ++)
                st[j][i] = get(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
    } 
}
int w[N + 5];
void dfs(int id, int ft) {
    int t1 = buck1[w[id] + dep[id]], t2 = buck2[w[id] - dep[id]];
    for (int nxt : g[id]) {
        if (nxt == ft) continue;
        dfs(nxt, id);
    }
    buck1[dep[id]] += ts[id];
    for (int nxt : g1[id]) 
        buck2[dis[nxt] - dep[t[nxt]]] ++;
    ans[id] += buck1[w[id] + dep[id]] - t1 + buck2[w[id] - dep[id]] - t2;
    for (int nxt : g2[id]) 
        buck2[dis[nxt] - dep[t[nxt]]] --, buck1[dep[s[nxt]]] --; 
}
signed main() {
	int m;
    cin >> n >> m;
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        // x <-> y
        g[x].push_back(y);
        g[y].push_back(x);
    }
    lca::init();
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    for (int i = 1; i <= m; i ++) {
        cin >> s[i] >> t[i];
        int lca = lca::solve(s[i], t[i]);
        dis[i] = dep[s[i]] + dep[t[i]] - 2 * dep[lca];
        ts[s[i]] ++;
        g1[t[i]].push_back(i);
        g2[lca].push_back(i);
        if (dep[lca] + w[lca] == dep[s[i]]) ans[lca] --;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << " ";
    return 0;
}
