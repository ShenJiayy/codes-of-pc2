#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
int a[N + 5], dp[N + 5][N + 5];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset(dp, -0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int i = 2; i <= n; i ++)
        for (int j = 0; j < i; j ++)
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i] * (a[i] == a[i - 1])),
            dp[i][i - 1] = max(dp[i][i - 1], dp[i - 1][j] + a[i] * (a[i] == a[j]));
    int ans = 0;
    for (int i = 0; i < n; i ++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}
