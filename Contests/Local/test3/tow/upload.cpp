#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 40;
int dp[N + 5][N + 5];
signed main() {
	// Code here.
    int n;
    cin >> n;
    cout << (1ull << n - 1) << endl;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++) {
            for (int k = 1; k <= j - 1; k ++)
                dp[i][j] += dp[i - k][j];
            for (int k = 0; k <= j; k ++)
                dp[i][j] += dp[i - j][k];
        }
    for (int i = 1; i <= n; i ++)
        cout << dp[n][i] << " ";
    return 0;
}
