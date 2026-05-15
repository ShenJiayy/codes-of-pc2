#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, M = 1048576;
int a[N + 5][N + 5], dp[M + 5][N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            cin >> a[i][j];
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int stat = 1; stat < (1 << n); stat ++)
        for (int j = 0; j < n; j ++)
            if (stat >> j & 1)
                for (int k = 0; k < n; k ++)
                    dp[stat][j] = min(dp[stat][j], dp[stat ^ 1 << j][k] + a[j][k]);
    cout << dp[(1 << n) - 1][n - 1];
    return 0;
}
