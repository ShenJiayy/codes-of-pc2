#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3;
int box[128], dp[N + 5][2];
char s[N + 5];
signed main() {
	int T;
	cin >> T;
	while (T --) {
		cin >> s + 1;
		int n = strlen(s + 1);
		memset(box, 0, sizeof box);
		for (int i = 1; i <= n; i ++)
			box[s[i]] ++;
		if (box['L'] + box['R'] - box['B'] != 1) {
			puts("0");
			continue;
		}
		memset(dp, 0, sizeof dp);
		// for (int i = 1; i <= n; i ++)
		// 	dp[i][i][0] = (s[i] == 'L'), dp[i][i][1] = (s[i] == 'R');
		// for (int sz = 2; sz <= n; sz ++)
		// 	for (int l = 1, r = sz; r <= n; l ++, r ++) 
		// 		for (int k = l; k < r; k ++) {
		// 			dp[l][r][0] |= dp[l][k][0] && dp[k + 1][r][1], 
		// 			dp[l][r][1] |= dp[l][k][0] && dp[k + 1][r][1];
		// 			if (s[k] == 'B' && k > l)
		// 				dp[l][r][0] |= dp[l][k - 1][0] && dp[k + 1][r][1],
		// 				dp[l][r][1] |= dp[l][k - 1][0] && dp[k + 1][r][1];
		// 		}
		// cout << (dp[1][n][0] || dp[1][n][1]) << endl;
		// dp[i][i][0] 
	}
	return 0;
}
