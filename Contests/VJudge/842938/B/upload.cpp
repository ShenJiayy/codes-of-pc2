#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 18;
int a[N + 5], dp[N + 5][(1 << N) + 5];

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i ++)
        dp[1][1 << i - 1] = a[i];
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j < (1 << n); j ++)
            if (dp[i][j] < 9e12)
                for (int k = 1; k <= n; k ++)
                    if ((j | (1 << k - 1)) != j)
                        if (dp[i][j] + a[k] <= m)
                            dp[i][j | (1 << k - 1)] = min(dp[i][j | (1 << k - 1)], dp[i][j] + a[k]);
                        else
                            dp[i + 1][j | (1 << k - 1)] = min(dp[i + 1][j | (1 << k - 1)], a[k]);
    for (int i = 0; i <= n; i ++)
        if (dp[i][(1 << n) - 1] < 9e12) {
            cout << i;
            return 0;
        }
    puts("-1");
    return 0;
}