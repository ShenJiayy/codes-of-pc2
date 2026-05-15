#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3830;
int a[N + 5], dp[2][N + 5][2];
void solve(int n, int b) {
    for (int i = 2; i <= n; i ++)
        for (int j = 0; j <= min(i, b); j ++) {
            dp[i & 1][j][0] = max(dp[i - 1 & 1][j][0], dp[i - 1 & 1][j][1]);
            if (j) dp[i & 1][j][1] = max(dp[i - 1 & 1][j - 1][0], dp[i - 1 & 1][j - 1][1] + a[i]);
        }
}
signed main() {
	int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset(dp, -0x3f, sizeof dp);
    dp[1][0][0] = dp[1][1][1] = 0;
    solve(n, b);
    int res = max(dp[n & 1][b][0], dp[n & 1][b][1]);
    memset(dp, -0x3f, sizeof dp);
    dp[1][0][0] = 0;
    dp[1][1][1] = a[1];
    solve(n, b);
    res = max(res, dp[n & 1][b][1]);
    cout << res;
    return 0;
}
