#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 12, INF = 0x3f3f3f3f;
int g[N][N], val[(1 << N)][(1 << N)], dp[N][(1 << N)];
void init(int n) {
    for (int i = 1; i < (1 << n); i ++)
        for (int j = i; j; j = (j - 1) & i) {
            if (j == i) continue;
            for (int t = 0, tmp; t < n; t ++, tmp = INF) {
                if (!(((i ^ j) >> t) & 1)) continue;
                for (int l = 0; l < n; l ++)
                    if ((j >> l) & 1)
                        tmp = min(tmp, g[l][t]);
                if (tmp >= INF) {
                    val[j][i] = INF;
                    break;
                }
                val[j][i] += tmp;
            }
        }
}
int solve(int rt, int n) {
    for (int i = 0; i < N; i ++) 
        for (int j = 0; j < (1 << N); j ++) 
            dp[i][j] = INF;
    dp[0][1 << rt] = 0;
    int ans = INF;
    for (int i = 1; i < n; i ++)
        for (int j = 1; j < (1 << n); j ++) {
            for (int k = j; k; k = (k - 1) & j) {
                if (k == j) continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + i * val[k][j]);
            }
            if (j == (1 << n) - 1) ans = min(ans, dp[i][j]);
        }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int n, m;
    cin >> n >> m;
    if (n == 1) 
        return puts("0"), 0;
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < n; j ++) 
            g[i][j] = INF;
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --, b --;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    init(n);
    int ans = INF;
    for (int i = 0; i < n; i ++)
        ans = min(ans, solve(i, n));
    cout << ans;
    return 0;
}