#include <bits/stdc++.h>
using namespace std;
#define int unsigned int
const int mod = 2147483648, N = 4000;
int dp[N + 5][N + 5];
signed main() {
	int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= n; j ++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
                dp[i][j] += dp[i][j - i] % mod, dp[i][j] %= mod;
        }
    cout << (dp[n][n] % mod - 1 + mod) % mod;
    return 0;
}
