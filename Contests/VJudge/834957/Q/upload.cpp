#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000000, inf = 29634862;
int a[N + 5], dp[N + 5][3];
int min(int a, int b, int c) {
	return min(a, min(b, c));
}
signed main() {
	// 我们构造 f[j][i]，其表示前 j 个数以 i(i=−1,0,1) 结尾的最少改变次数。
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], a[i] ++;
	memset(dp, 0x3f, sizeof dp);
	dp[1][a[1]] = 0;
	for (int i = 2; i <= n; i ++)
		for (int j = 0; j < 3; j ++) {
			if (a[i] == 0) {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = inf;
				dp[i][2] = dp[i - 1][2] + 2;
			}
			if (a[i] == 1) {
				dp[i][0] = dp[i - 1][0] + 1;
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
				dp[i][2] = dp[i - 1][2] + 1;
			}
			if (a[i] == 2) {
				dp[i][0] = dp[i - 1][0] + 2;
				dp[i][1] = dp[i - 1][0] + 1;
				dp[i][2] = min(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
			}
		}
	int ans = min(dp[n][0], dp[n][1], dp[n][2]);
	if (ans >= inf - 10)
		puts("BRAK");
	else cout << ans;
	return 0;
}
