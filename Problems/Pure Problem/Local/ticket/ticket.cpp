#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int dp[N + 5][N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n + 1; i ++)
        dp[1][i] = 1;
    for (int i = 2; i <= n + 1; i ++)
        for (int j = i; j <= n + 1; j ++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    cout << dp[n + 1][n + 1];
    return 0;
}
