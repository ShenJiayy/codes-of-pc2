#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e4, M = 5e3;
bool vis[N + 5];
struct Query {
    int l, r, c;
} q[M + 5];
bool cmp(Query x, Query y) {
    if (x.r != y.r)
        return x.r < y.r;
    return x.l < y.l;
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> q[i].l >> q[i].r >> q[i].c;
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i ++) {
        int sum = 0;
        for (int j = q[i].l; j <= q[i].r; j ++)
            sum += vis[j];
        if (sum > q[i].c) continue;
        q[i].c -= sum;
        for (int p = q[i].r; p >= q[i].l && q[i].c > 0; p --)
            if (!vis[p])
                vis[p] = 1, q[i].c --;
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += vis[i];
    cout << sum;
    return 0;
}
