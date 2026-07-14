#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], dp[N * 2 + 5];
signed main() {
	memset(dp, -0x3f, sizeof dp);
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	dp[0] = a[0];
	for (int i = 0; i < n; i ++)
		for (int j = i + l; j <= i + r; j ++)
			dp[j] = max(dp[j], dp[i] + a[j]);
	int maxn = 0;
	for (int i = n; i <= n * 2; i ++)
		maxn = max(maxn, dp[i]);
	cout << maxn;
	return 0;
}
