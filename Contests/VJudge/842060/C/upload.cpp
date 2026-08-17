#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3000;
int a[N + 5], fir[N + 5], lst[N + 5], cnt, dp[N + 5][N + 5];
inline bool check(int l, int r, int val) {
	return l <= fir[val] && lst[val] <= r;
}
int dfs(int l, int r) {
	if (l > r)
		return 0;
	if (dp[l][r] < -9e12)
		dp[l][r] = max(-dfs(l + 1, r) + check(l, r, a[l]), -dfs(l, r - 1) + check(l, r, a[r]));
	return dp[l][r];
}
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (fir[a[i]] == 0)
			cnt ++, fir[a[i]] = i;
		lst[a[i]] = i;
	}
	memset(dp, -0x3f, sizeof dp);
	int a = dfs(1, n) + cnt; a /= 2;
	cout << a << ":" << cnt - a;
	return 0;
}