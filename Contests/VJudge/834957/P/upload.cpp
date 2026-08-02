#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3, M = 2e4, mod = 998244353;
int dp[N + 5][M * 2 + 5], a[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans ++;
        for (int j = 1; j < i; j ++) {
            dp[i][a[i] - a[j] + M] += dp[j][a[i] - a[j] + M] + 1;
            dp[i][a[i] - a[j] + M] %= mod;
            ans += dp[j][a[i] - a[j] + M] + 1;
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}
