#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3;
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
int dis[N + 5], cnt[N + 5];
bool vis[N + 5];
bool spfa(int s, int n) {
    queue<int> q;
    memset(dis, 0x3f, sizeof dis);
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int t = q.front();
        vis[t] = 0;
        q.pop();
        cnt[t] ++;
        if (cnt[t] > n)
            return 1;
        for (Node nxt : g[t])
            if (dis[nxt.id] > dis[t] + nxt.w) {
                dis[nxt.id] = dis[t] + nxt.w;
                if (!vis[nxt.id]) {
                    vis[nxt.id] = 1;
                    q.push(nxt.id);
                }
            }
    }
    return 0;
}
signed solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        g[i].clear();
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        if (w >= 0)
            g[v].push_back({u, w});
    }
    if (spfa(1, n))
        puts("YES");
    else puts("NO");
    return 0;
}
signed main() {
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}