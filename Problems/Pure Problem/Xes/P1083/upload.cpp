#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int a[N + 5], d[N + 5], n, s[N + 5];
struct Query {
    int d, s, t;
} q[N + 5];
bool check(int k) {
    memset(d, 0, sizeof d);
    for (int i = 1; i <= k; i ++) 
        d[q[i].s] += q[i].d, d[q[i].t + 1] -= q[i].d;
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + d[i];
    for (int i = 1; i <= n; i ++)
        if (s[i] > a[i])
            return 0;
    return 1;
}
signed main() {
	int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> q[i].d >> q[i].s >> q[i].t;
    int l = 1, r = m, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (!check(mid))
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    if (ans != -1)
        cout << "-1\n" << ans;
    else puts("0");
    return 0;
}
