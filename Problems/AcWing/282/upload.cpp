#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300;
int a[N + 5], dp[N + 5][N + 5], s[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i ++)
        dp[i][i] = 0;
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];
    for (int len = 2; len <= n; len ++)
        for (int l = 1, r = len; r <= n; r ++, l ++) {
            for (int i = l; i < r; i ++)
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
            dp[l][r] += s[r] - s[l - 1];
        }
    cout << dp[1][n];
    return 0;
}
