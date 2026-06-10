#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500, K = 20;
vector<int> g[N + 5];
int dis[N + 5][K + 5], n, m, k;
bool vis[N + 5][K + 5];
void dfs(int id, int stp) {
    if (stp > k || vis[id][stp]) return ;
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
        memset(dis, 0, sizeof dis);
        memset(vis, 0, sizeof vis);
        dfs(i, 0);
        for (int j = 1; j <= k; j ++) {
            int cnt = 0;
            for (int k = 1; k <= n; k ++)
                cnt += vis[k][j];
            cout << cnt << " ";
        }
        cout << endl;
    }
    return 0;
}
