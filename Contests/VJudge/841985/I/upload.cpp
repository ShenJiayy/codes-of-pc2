#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100, M = 1e6;
int v[N + 5], c[N + 5];
int dpj[M + 5], dpr[M + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> v[i];
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    int maxn = 0, sum = 0;
    for (int i = 1; i <= n; i ++)
        maxn = max(maxn, v[i] * v[i]),
        sum += v[i] * c[i];
    if (sum < m)
        return puts("-1"), 0;
    memset(dpr, 0x3f, sizeof dpr);
    dpr[0] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = v[i]; j <= maxn; j ++)
            dpr[j] = min(dpr[j], dpr[j - v[i]] + 1);
    memset(dpj, 0x3f, sizeof dpj);
    dpj[0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= c[i]; j *= 2) {
            for (int k = m + maxn; k >= j * v[i]; k --)
                dpj[k] = min(dpj[k], dpj[k - j * v[i]] + j);
            c[i] -= j;
        }
        if (c[i])
            for (int k = m + maxn; k >= c[i] * v[i]; k --)
                dpj[k] = min(dpj[k], dpj[k - c[i] * v[i]] + c[i]);
    }
    int ans = 9e18;
    for (int i = m; i <= m + maxn; i ++)
        ans = min(ans, dpj[i] + dpr[i - m]);
    if (ans > 9e12)
        puts("-1");
    else cout << ans;
    return 0;
}