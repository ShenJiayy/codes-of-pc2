#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 10000, M = 1000, INF = 0x3f3f3f3f3f3f3f3f;
int up[N + 5], down[N + 5], dp[N + 5][M + 5];
struct Pipe { 
    int p, u, d; 
} p[N + 5];
bool cmp(Pipe x, Pipe y) {
    return x.p < y.p;
}
bool pipeid[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++) 
        cin >> up[i] >> down[i];
    for (int i = 1; i <= k; i ++)
        cin >> p[i].p >> p[i].d >> p[i].u;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= m; i ++)
        dp[0][i] = 0;
    for (int i = 1; i <= k; i ++)
        pipeid[p[i].p] = i;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            if (j + down[i - 1] <= m)
                dp[i][j] = min(dp[i][j], dp[i - 1][j + down[i - 1]]);
            if (j >= up[i - 1]) {
                dp[i][j] = min(
                    dp[i][j], 
                    min(
                        dp[i][j - up[i - 1]], 
                        dp[i - 1][j - up[i - 1]]
                    ) + 1
                );
            }
            if (j == m)
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            int pid = pipeid[i];
            if (!pid) continue;
            int minh = p[pid].d, maxh = p[pid].u;
            if (!(maxh > j && j > minh))
                dp[i][j] = INF;
        }
    bool ist = 0;
    for (int i = 0; i <= m; i ++)
        if (dp[n][i] != INF)
            ist = 1;
    cout << ist;
    return 0;
}