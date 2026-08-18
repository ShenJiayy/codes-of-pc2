#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300;
int dp[N + 5][N + 5][2], a[N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int cnt = 1; cnt <= n; cnt ++) {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i ++)
            dp[i][i][0] = dp[i][i][1] = m - abs(a[i]) * cnt;
        for (int len = 2; len <= cnt; len ++)
            for (int l = 1, r = len; r <= n; l ++, r ++)
                dp[l][r][0] = max(
                    dp[l + 1][r][0] - (a[l + 1] - a[l]) * (cnt - len + 1),
                    dp[l + 1][r][1] - (a[r] - a[l]) * (cnt - len + 1)
                ) + m,
                dp[l][r][1] = max(
                    dp[l][r - 1][1] - (a[r] - a[r - 1]) * (cnt - len + 1),
                    dp[l][r - 1][0] - (a[r] - a[l]) * (cnt - len + 1)
                ) + m;
        for (int l = 1; l <= n; l ++)
            for (int r = l; r <= n; r ++)
                ans = max(ans, dp[l][r][0]), 
                ans = max(ans, dp[l][r][1]);
    }
    cout << ans;
    return 0;
}