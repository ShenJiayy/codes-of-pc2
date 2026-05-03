#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, mod = 998244353;
char s[N + 5];
int dp[N + 5][10];
signed main() {
	scanf("%s", s + 1);
	int cnt = 0;
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i ++) {
		// dp[i][c] 1~i, last=c
		for (int j = 0; j < 3; j ++)
			if (s[i] == j + 'a')
				dp[i][j] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + 1) % mod;
			else
				dp[i][j] = dp[i - 1][j];
	}
	cout << (dp[len][0] + dp[len][1] + dp[len][2]) % mod;
	return 0;
}