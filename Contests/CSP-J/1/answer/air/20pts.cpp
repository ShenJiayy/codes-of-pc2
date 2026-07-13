#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int l[N + 5], r[N + 5], blkcnt[N + 5], q[N + 5];
int solve() {
    int n, m, T;
    cin >> n >> m >> T;
    for (int i = 1; i <= m; i ++) 
        cin >> l[i] >> r[i];
    memset(blkcnt, 0, sizeof blkcnt);
    for (int t = 1; t <= T; t ++) 
        cin >> q[t];
    // Here below.
    for (int t = 1; t <= T; t ++) 
        for (int i = 1; i <= m; i ++)
            if (l[i] <= q[t] && q[t] <= r[i]) {
                blkcnt[i] ++;
                if (blkcnt[i] * 2 > r[i] - l[i] + 1) {
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