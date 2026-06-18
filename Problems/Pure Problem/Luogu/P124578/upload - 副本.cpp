#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], b[N + 5], c[N + 5];
signed main() {
    freopen("softcream.in", "r", stdin);
    freopen("softcream.out", "w", stdout);
	int n, m, p, q;
    cin >> n >> m >> q >> p;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    for (int i = 1; i <= q; i ++)
        cin >> c[i];    
    int cmin = *min_element(c + 1, c + q + 1), cmax = *max_element(c + 1, c + q + 1);
    sort(b + 1, b + m + 1);
    int ans = -1e9;
    for (int i = 1; i <= n; i ++) {
        // b=P-a-0.5(min{C}+max{C})
        double bp = p - (cmin + cmax) / 2 - a[i];
        int fp = lower_bound(b + 1, b + m + 1, bp) - b, c;
        if (fp == 1)
            c = b[1];
        else if (fp == m + 1)
            c = b[m];
        else if (b[fp] - bp < bp - b[fp - 1])
            c = b[fp];
        else c = b[fp - 1];
        // max(|a+b+min{C}-P|,|a+b+max{C}-P|)
        int s1 = abs(a[i] + c + cmin - p), s2 = abs(a[i] + c + cmax - p);
        ans = max(ans, max(s1, s2));
    }
    cout << ans;
    return 0;
}
