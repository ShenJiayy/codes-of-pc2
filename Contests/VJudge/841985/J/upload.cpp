#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int t[N + 5][4], dp[2][N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        cin >> t[i][1] >> t[i][2] >> t[i][3];
    int uptime = 0;
    memset(dp, 0x3f, sizeof dp);
    dp[0 & 1][0] = 0;
    for (int i = 1; i <= n; i ++) {
        uptime += max(t[i][1], max(t[i][2], t[i][3]));
        memset(dp[i & 1], 0x3f, sizeof dp[i & 1]);
        for (int j = 0; j <= uptime; j ++) {
            if (t[i][2])
                dp[i & 1][j] = min(dp[i & 1][j], dp[i - 1 & 1][j] + t[i][2]);
            if (j >= t[i][1] && t[i][1])
                dp[i & 1][j] = min(dp[i & 1][j], dp[i - 1 & 1][j - t[i][1]]);
            if (j >= t[i][3] && t[i][3])
                dp[i & 1][j] = min(dp[i & 1][j], dp[i - 1 & 1][j - t[i][3]] + t[i][3]);
        }
    }
    int ans = 9e18;
    for (int i = 0; i <= uptime; i ++)
        ans = min(ans, max(dp[n & 1][i], i));
    cout << ans;
    return 0; 
}
