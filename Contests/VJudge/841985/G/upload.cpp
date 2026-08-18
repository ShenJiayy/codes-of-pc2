#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000, M = 6000;
int a[N + 5], b[N + 5];
int dp[N + 5][M + M + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i] >> b[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0][M] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = -M; j <= M; j ++) {
            int dx = a[i] - b[i];
            dp[i][j + M] = min(dp[i - 1][j - dx + M], dp[i - 1][j + dx + M] + 1);
        }
    int ans = 9e18;
    for (int i = 0; i <= M; i ++) {
        ans = min(ans, dp[n][M - i]), ans = min(ans, dp[n][M + i]);
        if (ans <= M) {
            cout << ans;
            return 0;
        }
    }
    return 0;
}
