#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1.5e5;
int g[N + 5][5];
int res[N + 5][5][64];
int ans[N + 5][5];
void dfs(int rt, int id, int ft, int dep) {
    if (dep > 3) return ;
    res[rt][dep][++ res[rt][dep][0]] = id;
    for (int i = 1; i <= g[id][0]; i ++)
        if (g[id][i] != ft)
            dfs(rt, g[id][i], id, dep + 1);
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u][++ g[u][0]] = v;
        g[v][++ g[v][0]] = u;
    }
    for (int i = 1; i <= n; i ++) {
        dfs(i, i, 0, 0);
        for (int j = 1; j <= 3; j ++)
            for (int k = 1; k <= res[i][j - 1][0]; k ++)
                res[i][j][++ res[i][j][0]] = res[i][j - 1][k];
        for (int j = 0; j <= 3; j ++) {
            sort(res[i][j] + 1, res[i][j] + res[i][j][0] + 1);
            res[i][j][0] = unique(res[i][j] + 1, res[i][j] + res[i][j][0] + 1) - res[i][j] - 1;
            for (int k = 1; k <= res[i][j][0]; k ++)
                ans[i][j] += res[i][j][k];
        }
    }
    int T;
    cin >> T;
    while (T --) {
        int x, k;
        cin >> x >> k;
        cout << ans[x][k] << endl;
    }
    return 0;
}