#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000, mod = 1e9 + 7;
int dp[N + 5][N + 5];
signed main() {
	int n, m;
	cin >> n >> m;
	dp[2][2] = 1;
	for (int i = 2; i <= m; i ++)
		for (int j = 2; j <= n; j ++) {
			dp[i + 1][j + 1] += dp[i][j],
			dp[i + 1][j + 1] %= mod;
			if (i + j <= n)
				dp[i + 1][i + j] += dp[i][j],
				dp[i + 1][i + j] %= mod;
			dp[i][j + 2] += dp[i][j],
			dp[i][j + 2] %= mod;
		}
	int ans = 0;
	for (int i = 1; i <= m; i ++)
		ans += 2 * (m - i + 1) % mod * (dp[i][n] + dp[i][n - 1]) % mod, ans %= mod;
	cout << ans;
	return 0;
}
