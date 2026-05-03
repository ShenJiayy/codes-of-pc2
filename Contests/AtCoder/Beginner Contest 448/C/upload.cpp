#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, lgN = 20;
int a[N + 5], st[N + 5][lgN + 5], n;
int zuoyi(int x, int y) {
    return x << y;
}
void init() {
    for (int i = 1; i <= n; i ++)
        st[i][0] = a[i];
    for (int sz = 1; zuoyi(1, sz) <= n; sz ++)
        for (int l = 1, r = l + zuoyi(1, sz) - 1; r <= n; l ++, r ++)
            st[l][sz] = min(st[l][sz - 1], st[l + zuoyi(1, sz - 1)][sz - 1]);
}
int query(int l, int r) {
    if (r < 1 || l > n || l > r) return 9e10;
    if (l < 1) l = 1;
    if (r > n) r = n;
    int sz = log2(r - l + 1);
    return min(st[l][sz], st[r - zuoyi(1, sz) + 1][sz]);
}
signed main() {
    int q;
    cin >> n >> q;
    a[0] = a[n] = 1e9;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    init();
    while (q --) {
        int k;
        cin >> k;
        int ans = 9e18, last = 0;
        for (int i = 1; i <= k; i ++) {
            int pt;
            cin >> pt;
            // cout << query(last + 1, pt - 1) << " ";
            ans = min(ans, query(last + 1, pt - 1));
            last = pt;
        }
        // cout << query(last + 1, n) << " ";
        ans = min(ans, query(last + 1, n));
        cout << ans << endl;
        // int l, r;
        // cin >> l >> r;
        // cout << query(l, r) << endl;
    }
    return 0;
}