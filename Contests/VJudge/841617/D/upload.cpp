#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200;
int dp[N * 2 + 5][N * 2 + 5][N + 5][2];
struct Node {
	int p, t;
} a[N * 2 + 5];
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) 
		cin >> a[i].p, a[i + n + 1].p = a[i].p + m;
	for (int i = 1; i <= n; i ++) 
		cin >> a[i].t, a[i + n + 1].t = a[i].t;
	a[n + 1] = {m, (int)-1e18};
	memset(dp, 0x3f, sizeof dp);
	dp[n + 1][n + 1][0][0] = dp[n + 1][n + 1][0][1] = 0;
	for (int j = n + 1; j <= 2 * n + 1; j ++)
		for (int i = n + 1; j - i <= n; i --)
			dp[i][j][0][1] = a[j].p - m,
			dp[i][j][0][0] = m - a[i].p;
	int ans = 0;
	for (int len = 1; len <= n; len ++)
		for (int l = 1, r = len + 1; l <= n + 1 && r <= 2 * n + 1; l ++, r ++)
			for (int i = 1; i <= len; i ++) {
				dp[l][r][i][0] = min(dp[l][r][i][0], dp[l + 1][r][i][0] + a[l + 1].p - a[l].p);
				dp[l][r][i][0] = min(dp[l][r][i][0], dp[l + 1][r][i][1] + a[r].p - a[l].p);
				// 同理可得
				dp[l][r][i][1] = min(dp[l][r][i][1], dp[l][r - 1][i][1] + a[r].p - a[r - 1].p);
				dp[l][r][i][1] = min(dp[l][r][i][1], dp[l][r - 1][i][0] + a[r].p - a[l].p);

				if (dp[l + 1][r][i - 1][0] + a[l + 1].p - a[l].p <= a[l].t)
					dp[l][r][i][0] = min(dp[l][r][i][0], dp[l + 1][r][i - 1][0] + a[l + 1].p - a[l].p);
				if (dp[l + 1][r][i - 1][1] + a[r].p - a[l].p <= a[l].t)
					dp[l][r][i][0] = min(dp[l][r][i][0], dp[l + 1][r][i - 1][1] + a[r].p - a[l].p);
				// 同理可得
				if (dp[l][r - 1][i - 1][1] + a[r].p - a[r - 1].p <= a[r].t)
					dp[l][r][i][1] = min(dp[l][r][i][1], dp[l][r - 1][i - 1][1] + a[r].p - a[r - 1].p);
				if (dp[l][r - 1][i - 1][0] + a[r].p - a[l].p <= a[r].t)
					dp[l][r][i][1] = min(dp[l][r][i][1], dp[l][r - 1][i - 1][0] + a[r].p - a[l].p);
				for (int j = 0; j < 2; j ++)
					if (dp[l][r][i][j] < 9e15)
						ans = max(ans, i);
			}
	cout << ans;
	return 0;
}