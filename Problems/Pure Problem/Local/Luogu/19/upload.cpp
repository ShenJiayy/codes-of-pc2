#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300, mod = 998244353;
int dp[N + 5][N + 5][N + 5];
signed main() {
	int n, m, a, b, c, d, e, f;
    cin >> n >> m >> a >> b >> c >> d >> e >> f;
    set<pair<int, int>> track;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        track.insert({x, y});
    }
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; i + j <= n; j ++)
            for (int k = 0; i + j + k <= n; k ++) {
                int x = i * a + j * c + k * e, 
                    y = i * b + j * d + k * f;
                if (track.count({x, y}) == 1)
                    dp[i][j][k] = 0;
                else {
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] %= mod;
                    dp[i][j + 1][k] += dp[i][j][k];
                    dp[i][j + 1][k] %= mod;
                    dp[i][j][k + 1] += dp[i][j][k];
                    dp[i][j][k + 1] %= mod;
                }
            }
    int ans = 0;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; i + j <= n; j ++)
            ans += dp[i][j][n - i - j], ans %= mod;
    cout << ans;
    return 0;
}