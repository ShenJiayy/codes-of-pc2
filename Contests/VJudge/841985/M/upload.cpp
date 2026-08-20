#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 150;
int du[N + 5][N + 5], dd[N + 5][N + 5], dp[N + 5][N + 5];
int ans[N + 5], val[N + 5], a[N + 5];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> val[i];
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	memset(du, -0x3f, sizeof du);
	memset(dd, -0x3f, sizeof dd);
	memset(dp, -0x3f, sizeof dp);
	for (int i = 1; i <= n; i ++)
		dd[i][i] = du[i][i] = 0,
		dp[i][i] = val[1], dp[i][i - 1] = 0;
	for (int len = 2; len <= n; len ++)
		for (int l = 1, r = len; r <= n; l ++, r ++) {
			for (int k = l; k < r; k ++)
				if (a[k] + 1 == a[r])
					du[l][r] = max(du[l][r], du[l][k] + dp[k + 1][r - 1]);
				else if (a[k] - 1 == a[r])
					dd[l][r] = max(dd[l][r], dd[l][k] + dp[k + 1][r - 1]);
			for (int k = l; k < r; k ++)
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
			for (int k = l; k <= r; k ++) {
				int pos = 2 * a[k] + 1 - a[l] - a[r];
				if (1 <= pos && pos <= n)
					dp[l][r] = max(dp[l][r], du[l][k] + dd[k][r] + val[pos]);
			}
		}
	int maxn = 0;
	for (int r = 1; r <= n; r ++) {
		ans[r] = ans[r - 1];
		for (int l = 1; l <= r; l ++)
			ans[r] = max(ans[r], ans[l - 1] + dp[l][r]);
		maxn = max(maxn, ans[r]);
	}
	cout << maxn;
	return 0;
}
