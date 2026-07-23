#include <cstdio>
#define int long long
const int N = 4e6, M = 2e3;
int dp[M + 5], curr;
int v[N + 5], w[N + 5];
inline int max(int a, int b) {
    if (a > b) return a;
    return b;
}
signed main() {
    int m, n;
    scanf("%lld%lld", &m, &n);
    for (int i = 1; i <= n; i ++) {
        int vv, ww, k;
        scanf("%lld%lld%lld", &vv, &ww, &k);
        for (int base = 0; (1 << base) <= k; base ++)
            curr ++, v[curr] = vv << base, w[curr] = ww << base, k -= 1 << base;
        if (k)
            curr ++, v[curr] = vv * k, w[curr] = ww * k;
    }
    for (int i = 1; i <= curr; i ++)
        for (int j = m; j >= w[i]; j --) 
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    int ans = 0; 
    for (int i = 0; i <= m; i ++)
        ans = max(ans, dp[i]);
    printf("%lld", ans);
    return 0;
}