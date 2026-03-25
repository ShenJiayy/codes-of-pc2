#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3, M = 1e4;
int v[N + 5];
int dp[N + 5][M + 5];

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("1/in.in", "r", stdin);
	#endif
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; i ++)
		cin >> v[i];
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= w; j ++)
			dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - v[i]] + 1));
	cout << dp[n][w];
	return 0;
}