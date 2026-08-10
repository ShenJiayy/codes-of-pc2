#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500, mod = 998244353, M = 1e6;
int a[N + 5][N + 5];
map<int, int> dp[N + 5][N + 5];
int gcd(int x, int y) { return (y==0)?x:gcd(y, x % y); }
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> a[i][j];
	dp[1][1][gcd(a[1][1], m)] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			if (a[i - 1][j] != -1)
				for (auto k : dp[i - 1][j])
					dp[i][j][gcd(m, k.first * a[i][j])] += k.second,
					dp[i][j][gcd(m, k.first * a[i][j])] %= mod;
			if (a[i][j - 1] != -1)
				for (auto k : dp[i][j - 1])
					dp[i][j][gcd(m, k.first * a[i][j])] += k.second,
					dp[i][j][gcd(m, k.first * a[i][j])] %= mod;
		}
	cout << dp[n][n][m];
	return 0;
} 
