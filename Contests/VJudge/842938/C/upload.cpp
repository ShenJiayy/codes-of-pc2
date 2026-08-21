#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int g[N + 5][N + 5], dp[(1 << N) + 5][N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= n; j ++)
            cin >> g[i][j];
    memset(dp, 0x3f, sizeof dp);
    dp[1][1] = 0;
    for (int stat = 0; stat < (1 << n); stat ++)
        for (int j = 1; j <= n; j ++)
            if ((stat | (1 << j - 1)) != stat)
                for (int k = 1; k <= n; k ++)
                    if ((stat | (1 << k - 1)) == stat)
                        dp[stat | (1 << j - 1)][j] = min(dp[stat | (1 << j - 1)][j], dp[stat][k] + g[k][j]);
    int ans = 9e18;
    for (int i = 2; i <= n; i ++)
        ans = min(ans, dp[(1 << n) - 1][i] + g[i][1]);
    cout << ans;
    return 0;
}
