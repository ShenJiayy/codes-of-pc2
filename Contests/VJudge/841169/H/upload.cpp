#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 250;
struct Node {
    int id, v;
} a[N + 5];
int dis[N + 5][N + 5], ans[N + 5][N + 5];
bool cmp(Node x, Node y) {
    return x.v < y.v;
}
int max(int a, int b, int c) {
    return max(a, max(b, c));
}
signed main() {
    int n, m, T;
    cin >> n >> m >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].v, a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    memset(dis, 0x3f, sizeof dis);
    memset(ans, 0x3f, sizeof ans);
    for (int i = 1; i <= n; i ++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[a[i].id][a[j].id] = min(dis[a[i].id][a[j].id], dis[a[i].id][a[k].id] + dis[a[k].id][a[j].id]),
                ans[a[i].id][a[j].id] = min(ans[a[i].id][a[j].id], dis[a[i].id][a[j].id] + max(a[i].v, a[j].v, a[k].v));
    while (T --) {
        int u, v;
        cin >> u >> v;
        cout << ans[u][v] << endl;
    }
    return 0;
}
