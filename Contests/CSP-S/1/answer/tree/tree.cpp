#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[20], p[20];
bool g[20][20];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset(g, 0, sizeof g);
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    int cnt = 0;
    for (int rt = 1; rt <= n; rt ++) {
        p[1] = rt;
        for (int i = 1, curr = 1; i <= n; i ++)
            if (i != rt)
                p[++ curr] = i;
        bool task = 0;
        do {
            if (p[1] != rt) break;
            bool valid = 1;
            for (int i = 1; i <= n; i ++) {
                bool ok1 = 0;
                for (int j = 1; j < i; j ++)
                    if (g[p[j]][p[i]])
                        ok1 = 1;
                if (!ok1 && i != 1 || i > a[p[i]]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                task = 1;
                break;
            }
        } while (next_permutation(p + 1, p + n + 1));
        cnt += task;
    }
    cout << cnt << endl;
}
signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int T;
    cin >> T;
    while (T --)
		solve();
    return 0;
}
