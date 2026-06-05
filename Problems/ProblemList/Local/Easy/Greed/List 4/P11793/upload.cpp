#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4, INF = 0x3f3f3f3f3f3f3f3f;
int a[N + 5], dp[N + 5];
signed main() {
	int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
        int minn = a[i], maxn = a[i];
        for (int j = i - 1; j >= max(i - m, 0ll); j --) {
            minn = min(minn, a[j + 1]), maxn = max(maxn, a[j + 1]);
            int cost = k + (i - j) * (maxn - minn);
            if (dp[j] < INF && dp[j] + cost < dp[i])
                dp[i] = dp[j] + cost;
        }
    }
    cout << dp[n];
    return 0;
}
