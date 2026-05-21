#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30;
int dp[N + 5][N + 5][N + 5][N + 5][N + 5], f[8], s[8];
int solve(int k) {
    // int n = 0;
    memset(s, 0, sizeof s);
    for (int i = 1; i <= k; i ++)
        cin >> f[i];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= 5; i ++)
        if (k >= i)
            s[i] = f[i];
    dp[0][0][0][0][0] = 1;
    for (int a = 0; a <= s[1]; a ++)
        for (int b = 0; b <= s[2]; b ++)
            for (int c = 0; c <= s[3]; c ++)
                for (int d = 0; d <= s[4]; d ++)
                    for (int e = 0; e <= s[5]; e ++) {
                        if (a < s[1])
                            dp[a + 1][b][c][d][e] += dp[a][b][c][d][e];
                        if (b < s[2] && b < a)
                            dp[a][b + 1][c][d][e] += dp[a][b][c][d][e];
                        if (c < s[2] && c < b)
                            dp[a][b][c + 1][d][e] += dp[a][b][c][d][e];
                        if (d < s[2] && d < c)
                            dp[a][b][c][d + 1][e] += dp[a][b][c][d][e];
                        if (e < s[2] && e < d)
                            dp[a][b][c][d][e + 1] += dp[a][b][c][d][e];
                    }
    return dp[s[1]][s[2]][s[3]][s[4]][s[5]];
}
signed main() {
	while (1) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        cout << solve(n) << endl;
    }
    return 0;
}