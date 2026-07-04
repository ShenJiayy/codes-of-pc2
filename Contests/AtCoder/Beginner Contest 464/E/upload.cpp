#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int blocked[N + 1], n, m, T, p[N + 1], q[N + 1];
char ans[N + 1], c[N + 1];
inline int hs(int x, int y) {
    return (x - 1) * m + y;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> T;
    for (int i = 1; i <= T; i ++)
        cin >> p[i] >> q[i] >> c[i];
    for (int i = 1; i <= n * m; i ++)
        ans[i] = 'A';
    for (int t = T; t >= 1; t --) {
        for (int i = 1; i <= p[t]; i ++) {
            for (int j = blocked[i] + 1; j <= q[t]; j ++)
                ans[hs(i, j)] = c[t];
            blocked[i] = max(blocked[i], q[t]);
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            cout << ans[hs(i, j)];
        cout << '\n';
    }
    return 0;
}
