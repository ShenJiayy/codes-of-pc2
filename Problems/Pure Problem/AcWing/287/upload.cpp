#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
int d[N + 5], dp[N + 5], res[N + 5];
bool vis[N + 5];
int dfs1(int id) {
    dp[id] = 0;
    vis[id] = 1;
    int ret = 0;
    for (auto nxt : g[id]) 
        if (!vis[nxt.id])
            ret += min(dfs1(nxt.id), nxt.w);
    vis[id] = 0;
    if (d[id] == 1) return g[id][0].w;
    dp[id] = ret;
    return ret;
} 
void dfs2(int id) {
    vis[id] = 1;
    for (auto nxt : g[id]) {
        if (vis[nxt.id]) continue;
        if (d[id] == 1)
            res[nxt.id] = nxt.w + dp[nxt.id];
        else res[nxt.id] = min(res[id] - min(dp[nxt.id], nxt.w), nxt.w) + dp[nxt.id];
        dfs2(nxt.id);
    }
    vis[id] = 0;
}
signed main() {
	int T;
    cin >> T;
    while (T --) {
        // Initalize
        for (int i = 1; i <= N; i ++)
            g[i].clear();
        memset(d, 0, sizeof d);
        memset(vis, 0, sizeof vis);
        memset(dp, 0, sizeof dp);
        memset(res, 0, sizeof res);

        // Input
        int n;
        cin >> n;
        for (int i = 1; i < n; i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            d[u] ++, d[v] ++;
        }

        // Solve
        dp[1] = dfs1(1);
        res[1] = dp[1];
        dfs2(1);

        // Output
        cout << *max_element(res + 1, res + n + 1) << endl;
    }
    return 0;
}