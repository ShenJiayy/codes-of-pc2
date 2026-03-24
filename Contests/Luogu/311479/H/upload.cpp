#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], dp[N + 5], s[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];
    // dp[i]表示在1~i中删去某些数的答案最大
    memset(dp, 0x3f, sizeof dp);
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    dp[1] = a[1];
    for (int i = 1; i <= n + 1; i ++) {
        for (int j = max(1ll, i - m - 1); j < i; j ++)
            dp[i] = min(dp[i], dp[j] + s[i - 1] - s[j]);
    }
    cout << dp[n + 1];
    return 0;
}