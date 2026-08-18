#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 248;
int a[N + 5], dp[N + 5][N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset(dp, -0x3f, sizeof dp);
    for (int i = 1; i <= n; i ++)
        dp[i][i] = a[i];
    int maxn = *max_element(a + 1, a + n + 1);
    for (int sz = 2; sz <= n; sz ++)
        for (int l = 1, r = sz; r <= n; l ++, r ++)
            for (int k = l; k < r; k ++)
                if (dp[l][k] == dp[k + 1][r]) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + 1);
                    maxn = max(maxn, dp[l][r]);
                }
    cout << maxn;
    return 0;
}