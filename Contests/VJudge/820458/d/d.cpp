#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
char s[N + 5];
int dp[N + 5][3];
signed main() {
	int n, a, b, c;
	cin >> n >> s + 1 >> a >> b >> c;
	memset(dp, 0x3f, sizeof dp);
	int ans = min(a, b) * n;
	for (int i = 1; i <= n; i ++) {
		dp[i][0] = min(a * (i - 1), dp[i - 1][2]);
		if (s[i] != 'R') dp[i][0] += c;
		dp[i][1] = dp[i - 1][0];
		if (s[i] != 'G') dp[i][1] += c;
		dp[i][2] = dp[i - 1][1];
		if (s[i] != 'B') dp[i][2] += c;
		ans = min(ans, dp[i][2] + (n - i) * b);
	}
	cout << ans;
	return 0;
}
