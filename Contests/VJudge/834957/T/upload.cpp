#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int dp[N + 5][N + 5], d1[N + 5], d2[N + 5];
int n, m;
bool check(int t) {
	memset(dp, -0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
			for (int k = 0; k <= j; k ++)
				if (t - d1[i] * (j - k) >= 0)
					dp[i][j] = max(dp[i][j], dp[i - 1][k] + (t - d1[i] * (j - k)) / d2[i]);
	return dp[n][m] >= m;
}
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> d1[i] >> d2[i];
	int l = 0, r = 2e5, ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid))
			ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}