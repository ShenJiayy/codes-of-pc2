#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, M = 2000;
int a[N + 5];
bool dp[M + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int ans = 0;
    for (int stat = 0; stat < (1 << n); stat ++)
        if (__builtin_popcount(stat) == n - m) {
            memset(dp, 0, sizeof dp);
            dp[0] = 1;
            int sum = 0;
            for (int i = 1; i <= n; i ++)
                if ((stat >> i - 1) & 1) {
                    sum += a[i];
                    for (int j = sum; j >= a[i]; j --)
                        dp[j] |= dp[j - a[i]];
                }
            int res = 0;
            for (int i = 1; i <= sum; i ++)
                res += dp[i];
            ans = max(ans, res);
        }
    cout << ans;
    return 0;
}
