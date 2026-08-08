#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 400;
const int mod = 998244353;
bool inp[N + 5][N + 5];
int dp[N + 5][N + 5];
int c[N + 5][N + 5];
inline int getc(int n, int m) {
	return c[n + 1][m + 1];
}
inline void init() {
	c[0][0] = 1;
	for (int i = 1; i <= N + 3; i ++)
		for (int j = 1; j <= i; j ++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1], c[i][j] %= mod;
}
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		inp[u][v] = inp[v][u] = 1;
	}
	n *= 2;
	for (int i = 1; i <= n; i ++)
		dp[i + 1][i] = 1;
	init();
	for (int sz = 2; sz <= n; sz += 2)
		for (int l = 1, r = sz; r <= n; l ++, r ++) {
			if (inp[l][r])
				dp[l][r] = dp[l + 1][r - 1];
			for (int k = l + 1; k < r; k += 2)
				if (inp[l][k])
					dp[l][r] += dp[l + 1][k - 1] * dp[k + 1][r] % mod * getc(sz / 2, (k - l + 1) / 2) % mod, dp[l][r] %= mod;
		}
	cout << dp[1][n];
	return 0;
}
