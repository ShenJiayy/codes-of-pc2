#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, mod = 998244353;
int a[N + 5], dp[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i < n; i ++)
        cin >> a[i];
    dp[n] = 1;
    for (int i = n - 1; i >= 1; i --) {
        int t = dp[i + a[i]];
        if (a[i] == a[i + 1]) {
            for (int j = 1; j <= n; j ++)
                dp[j] *= (n - 1 - i),
                dp[j] %= mod;
            dp[i] += t;
            dp[i + a[i]] += t;
        }
        else {
            for (int j = 1; j <= n; j ++)
                dp[j] *= 0,
                dp[j] %= mod;
            dp[i] += t;
            dp[i + a[i]] += t;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += dp[i], ans %= mod;
    cout << ans;
    return 0;
}