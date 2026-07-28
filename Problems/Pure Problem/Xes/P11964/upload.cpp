#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500;
int n, m, k;
vector<int> g[N + 5];
bool vis[N + 5][N + 5];
void dfs(int id, int stp) {
    if (stp > k) return ;
    if (vis[id][stp]) return ;
    vis[id][stp] = 1;
    for (int nxt : g[id])
        dfs(nxt, stp + 1);
}
signed main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) {
        memset(vis, 0, sizeof vis);
        dfs(i, 0);
        for (int j = 1; j <= k; j ++) {
            int res = 0;
            for (int l = 1; l <= n; l ++)
                res += vis[l][j];
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}
