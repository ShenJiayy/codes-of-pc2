#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e4;
int l[N + 5], r[N + 5];
int ldp[N + 5], dp[N + 5], dp1[N + 5], dp2[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> l[i] >> r[i];
    l[1] = 1;
    r[n] = n;
    memset(dp, 0x3f, sizeof dp);
    ldp[1] = -1;
    for (int i = 1; i <= n; i ++) {
        memset(dp1, 0x3f, sizeof dp1);
        memset(dp2, 0x3f, sizeof dp2);
        for (int j = 1; j < l[i]; j ++)
            dp1[j] = min(
                ldp[j] + 1,
                dp1[j - 1] + 1
            );
        for (int j = r[i]; j <= n; j ++)
            dp1[j] = dp1[j - 1] + 1;
        for (int j = n; j > r[i]; j ++)
            dp1[j] = min(
                ldp[j] + 1,
                dp1[j + 1] + 1
            );
        for (int j = r[i]; j >= 1; j --)
            dp1[j] = dp1[j + 1] + 1;
        for (int j = 1; j <= n; j ++)
            dp[i] = min(dp1[j], dp2[j]);
        memcpy(ldp, dp, sizeof dp);
    }
    cout << ldp[n - 1];
    return 0;
}