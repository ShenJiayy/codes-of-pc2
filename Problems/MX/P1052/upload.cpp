#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
int a[N + 5], dp[N + 20], dist[N + 5];
bool vis[N + 5];
signed main() {
	int l, s, t, m;
    cin >> l >> s >> t >> m;
    if (s == t) {
        int cnt = 0;
        for (int i = 1; i <= m; i ++) {
            int x;
            cin >> x;
            if (x % s == 0)
                cnt ++;
        }
        // 排序？？？？没必要的哈
        cout << cnt;
        return 0;
    }
    for (int i = 1; i <= m; i ++)
        cin >> a[i];
    sort(a + 1, a + m + 1);
    dist[m + 1] = min(l - a[m], 100ll);
    l = 0;
    for (int i = 1; i <= m; i ++)
        dist[i] = min(90ll, a[i] - a[i - 1]), 
        l += dist[i], vis[l] = 1;
    l += dist[m + 1];
    memset(dp, 0x3f, sizeof dp); dp[0] = 0;
    for (int i = 1; i <= l + 9; i ++) {
        for (int j = s; j <= t; j ++) 
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[j] + vis[i]);
    }
    int ans = 9e18;
    for (int i = l; i <= l + 9; i ++)
        ans = min(ans, dp[i]);
    cout << ans;
    return 0;
}