#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int blkcnt[N + 5], q[N + 5];
struct Node {
    int l, r, s;
} a[N + 5];
bool cmp(Node x, Node y) {
    if (x.l != y.l) return x.l < y.l;
    return x.r < y.r;
}
int solve() {
    int n, m, T;
    cin >> n >> m >> T;
    for (int i = 1; i <= m; i ++) 
        cin >> a[i].l >> a[i].r, a[i].s = a[i].r - a[i].l + 1;
    sort(a + 1, a + m + 1, cmp);
    map<int, Node> mp;
    for (int i = 1; i <= m; i ++)
        mp[a[i].l] = a[i];
    m = 0;
    for (auto kv : mp)
        a[++ m] = kv.second;
    memset(blkcnt, 0, sizeof blkcnt);
    for (int t = 1; t <= T; t ++) 
        cin >> q[t];
    // Here below.
    for (int t = 1; t <= T; t ++) 
        for (int i = 1; i <= m; i ++)
            if (a[i].l <= q[t] && q[t] <= a[i].r) {
                blkcnt[i] ++;
                if (blkcnt[i] * 2 > a[i].s) {
                    cout << t << endl;
                    return 0;
                }
            }
    cout << -1 << endl;
    return 0;
}
signed main() {
    freopen("air.in", "r", stdin);
    freopen("air.out", "w", stdout);
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}