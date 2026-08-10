#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500, mod = 998244353, M = 1e6;
int mp[M + 5], mmp[N + 5], a[N + 5][N + 5], dp[N + 5][N + 5][N + 5];
int gcd(int x, int y) { return (y==0)?x:gcd(y, x % y); }
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> a[i][j];
	int cnt = 0, bm = m;
	for (int i = 2; i <= m; i ++)
		if (m % i == 0) {
			mp[i] = ++ cnt;
			mmp[cnt] = i;
			while (m % i == 0)
				m /= i;
		}
	m = bm;
	dp[1][1][gcd(a[1][1], m)] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			if (a[i - 1][j] != -1)
				for (int k = 1; k <= cnt; k ++)
					dp[i][j][gcd(m, mmp[k] * a[i][j])] += dp[i][j - 1][k],
					dp[i][j][gcd(m, mmp[k] * a[i][j])] %= mod;
			if (a[i][j - 1] != -1)
				for (int k = 1; k <= cnt; k ++)
					dp[i][j][gcd(m, mmp[k] * a[i][j])] += dp[i - 1][j][k],
					dp[i][j][gcd(m, mmp[k] * a[i][j])] %= mod;
		}
	cout << dp[n][n][cnt];
	return 0;
} 
