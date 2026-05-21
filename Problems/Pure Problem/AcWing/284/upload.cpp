#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300, mod = 1e9;
char s[N + 5];
int dp[N + 5][N + 5];
signed main() {
	cin >> s + 1;
    int n = strlen(s + 1);
    if (n % 2 == 0) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i ++)
        dp[i][i] = 1;
    for (int len = 3; len <= n; len += 2)
        for (int l = 1, r = len; r <= n; l ++, r ++) 
            if (s[l] == s[r])
                for (int k = l; k < r; k += 2)
                    if (s[k] == s[r])
                        dp[l][r] = (dp[l][r] + dp[l][k] * dp[k + 1][r - 1]) % mod;
    cout << dp[1][n];
    return 0;
}