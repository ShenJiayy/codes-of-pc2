#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 12;
int v[N + 5][N + 5], cost[(1 << N) + 5][(1 << N) + 5];
long long dp[N + 5][(1 << N) + 5];
void init(int n) {
	for (int i = 1; i < (1 << n); i ++)
        for (int j = i; j; j = (j - 1) & i) {
            if (j == i) continue;
            for (int t = 0, tmp; t < n; t ++, tmp = INF) {
                if (!(((i ^ j) >> t) & 1)) continue;
                for (int l = 0; l < n; l ++)
                    if ((j >> l) & 1)
                        tmp = min(tmp, v[l][t]);
                if (tmp >= INF) {
                    cost[j][i] = INF;
                    break;
                }
                else cost[j][i] += tmp;
            }
        }
}
long long solve(int x, int n) {
    for (int i = 0; i < 12; i ++)
        for (int j = 0; j < (1 << N); j ++)
            dp[i][j] = INF;
    dp[0][1 << x] = 0;
    long long ans = INF;
    for (int i = 1; i < n; i ++)
        for (int j = 1; j < (1 << n); j ++) {
            for (int k = j; k; k = (k - 1) & j) {
                if (k == j) continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1ll * i * cost[k][j]);
            }
            if (j == (1 << n) - 1) ans = min(dp[i][j], ans);
        }
    return ans;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 1) {
        printf("0");
        return 0;
    }
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            v[i][j] = INF;
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a --, b --;
        v[a][b] = v[b][a] = min(v[a][b], c);
    }
    init(n);
    long long ans = INF;
    for (int i = 0; i < n; i ++)
        ans = min(ans, solve(i, n));
    // for (int i = 0; i < (1 << n); i ++)
    //     for (int j = 0; j < (1 << n); j ++)
    //         cout << cost[i][j] << " ";
    // for (int i = 0; i < n; i ++)
    //     for (int j = 0; j < (1 << n); j ++)
    //         cout << dp[i][j] << " ";
    printf("%lld", ans);
    return 0;
}