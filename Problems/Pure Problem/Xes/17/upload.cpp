#include <bits/stdc++.h>
using namespace std;
#define int long long
const int T = 1e5;
int a[T + 5][5], dp[T + 5][5];
signed main() {
	int n, m = 0;;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int t, p;
        cin >> t >> p;
        cin >> a[t][p];
        m = t;
    }
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= m; i ++) 
        for (int j = 0; j <= 4; j ++) {
            dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if (j + 1 < 5)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
            dp[i][j] += a[i][j];
        }
    int ans = -9e18;
    for (int i = 0; i <= m; i ++) 
        for (int j = 0; j <= 4; j ++) 
            ans = max(ans, dp[i][j]);
    cout << ans;
    return 0;
}
