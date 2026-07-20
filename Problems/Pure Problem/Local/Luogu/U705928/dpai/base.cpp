#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], b[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    int ans = 9e18;
    for (int i = 1; i <= n; i ++) {
        int p = lower_bound(b + 1, b + m + 1, a[i]) - b;
        ans = min(ans, abs(a[i] - b[p]));
        if (p > 1)
            ans = min(ans, abs(a[i] - b[p - 1]));
    }
    cout << ans;
    return 0;
}
