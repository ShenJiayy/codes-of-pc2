#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 12, MOD = 1e8;
const int STATUS_MAX = 1 << N;
int a[N + 5], dp[N + 5][STATUS_MAX + 5];
bool b[N + 5][N + 5], lv[STATUS_MAX + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int m, n;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%lld", &b[i][j]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            a[i] = (a[i] << 1) + b[i][j];
    const int StatusMax = (1 << m) - 1;
    for (int i = 0; i <= StatusMax; i ++) {
        if (!(i & (i >> 1)) && !(i & (i << 1))) {
            lv[i] = 1;
            if ((i & a[1]) == i)
                dp[1][i] = 1;
        }
    }
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j <= StatusMax; j ++)
            if (lv[j] && (j & a[i - 1]) == j)
                for (int k = 0; k <= StatusMax; k ++)
                    if (lv[k] && (k & a[i]) == k && !(j & k)) {
                        dp[i][k] += dp[i - 1][j];
                        dp[i][k] %= MOD;
                    }
    }
    int ans = 0;
    for (int i = 0; i <= StatusMax; i ++)
        ans += dp[n][i], ans %= MOD;
    printf("%lld", ans);
    return 0;
}