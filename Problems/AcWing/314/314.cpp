#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5000;
int a[N + 5], dp[N + 5], cnt[N + 5];
// dp[i]：1~i长度，cnt[i]：i的方案数

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int maxsz = 0;
    for (int i = 1; i <= n; i ++) {
        dp[i] = 1;
        for (int j = 1; j < i; j ++)
            if (a[i] < a[j])
                dp[i] = max(dp[j] + 1, dp[i]);
        maxsz = max(maxsz, dp[i]);
    }
    for (int i = 1; i <= n; i ++) {
        if (dp[i] == 1) cnt[i] = 1;
        for (int j = 1; j < i; j ++)
            if (dp[i] == dp[j] && a[i] == a[j])
                cnt[j] = 0;
            else if (dp[i] == dp[j] + 1 && a[i] < a[j])
                cnt[i] += cnt[j];
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        if (dp[i] == maxsz)
            ans += cnt[i];
    cout << maxsz << " " << ans;
    return 0;
}