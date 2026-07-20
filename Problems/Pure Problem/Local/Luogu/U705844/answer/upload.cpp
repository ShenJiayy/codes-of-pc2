#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, mod = 998244353;
int a[N + 5], b[N + 5], s[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; i ++)
        s[i] = s[i - 1] + b[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int p = lower_bound(b + 1, b + m + 1, a[i]) - b;
        ans += (p - 1) * a[i] - s[p - 1];
        if (p <= m)
            ans += s[m] - s[p - 1] - (m - p + 1) * a[i];
        ans %= mod;
    }
    cout << ans;
    return 0;
}
