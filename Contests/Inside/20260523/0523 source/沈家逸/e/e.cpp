#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
vector<int> g[N + 5];
bool vis[N + 5];
int n, m;
void dfs(int id, int ft) {
    if (vis[id]) return ;
    vis[id] = 1;
    for (int nxt : g[id]) {
        if (nxt == ft) continue;
        dfs(nxt, id);
    }
}
signed main() {
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i ++) {
        memset(vis, 0, sizeof vis);
        dfs(i, 0);
        int cnt = 0;
        for (int i = 1; i <= n; i ++)
            cnt += vis[i];
        cout << cnt << endl;
    }
    return 0;
}