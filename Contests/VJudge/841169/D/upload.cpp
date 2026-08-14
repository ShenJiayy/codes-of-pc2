#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3, M = 5e5;
vector<int> idx[N + 5];
struct Edge {
    int u, v, w;
} e[M + 5];
int t[N + 5], dp[N + 5][N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i ++)
        dp[i][i] = 0;
    for (int i = 1; i <= n; i ++)
        cin >> t[i], idx[t[i]].push_back(i);
    for (int i = 1; i <= m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w, e[i].u ++, e[i].v ++;
        dp[e[i].u][e[i].v] = min(dp[e[i].u][e[i].v], e[i].w),
        dp[e[i].v][e[i].u] = min(dp[e[i].v][e[i].u], e[i].w);
    }
    int T, last = 0;
    cin >> T;
    while (T --) {
        int x, y, now;
        cin >> x >> y >> now;
        x ++, y ++;
        for (int tme = last; tme <= now; tme ++)
            for (int each : idx[tme])
                for (int i = 1; i <= n; i ++)
                    for (int j = 1; j <= n; j ++)
                        dp[i][j] = min(dp[i][j], dp[i][each] + dp[each][j]);
        if (dp[x][y] > 9e12 || t[x] > now || t[y] > now)
            puts("-1"), cout << flush;
        else cout << dp[x][y] << endl;
        last = now + 1;
    }
    return 0;
}