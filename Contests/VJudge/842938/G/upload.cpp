#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5, M = 20;
int a[N + 5], dp[(1 << M) + 5], s[N + 5][M + 5], box[M + 5];
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		memcpy(s[i], s[i - 1], sizeof s[i - 1]);
		s[i][a[i]] ++, box[a[i]] ++;
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for (int stat = 1; stat < (1 << m); stat ++) {
		int l = 0;
		for (int j = 1; j <= m; j ++)
			if (stat | (1 << j - 1) == stat)
				l += box[j];
		for (int j = 1; j <= m; j ++)
			if (stat | (1 << j - 1) == stat)
				dp[stat] = min(dp[stat], dp[stat ^ (1 << j - 1)] + box[j] - s[l][j] + s[l - box[j]][j]);
	}
	cout << dp[(1 << m) - 1];
	return 0;
}
