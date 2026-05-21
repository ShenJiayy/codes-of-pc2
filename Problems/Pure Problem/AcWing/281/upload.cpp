#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100, M = 1e5;
int a[N + 5], c[N + 5], vis[M + 5];
bool dp[M + 5];
signed main() {
	while (1) {
        int n, m;
        cin >> n >> m;
        if (!(n || m)) return 0;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        for (int i = 1; i <= n; i ++)
            cin >> c[i];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 1; i <= n; i ++) {
            memset(vis, 0, sizeof vis);
            for (int j = a[i]; j <= m; j ++)
                if (!dp[j] && dp[j - a[i]] && vis[j - a[i]] < c[i])
                    dp[j] = 1, vis[j] = vis[j - a[i]] + 1;
        }
        int ans = 0;
        for (int i = 1; i <= m; i ++)
            ans += dp[i];
        cout << ans << endl;
    }
    return 0;
}
