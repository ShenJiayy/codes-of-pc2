#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Node {
    int id, w;
};
struct Point {
    int id, w, lim;
};
vector<Point> g[N + 5];
bool operator > (Node x, Node y) {
    return x.w > y.w;
}
int dis[N + 5];
bool vis[N + 5];
void dijkstra(int s, int lim) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty()) {
        Node t = q.top();
        q.pop();
        if (vis[t.id]) continue;
        vis[t.id] = 1;
        for (Point nxt : g[t.id])
            if (dis[nxt.id] > dis[t.id] + nxt.w && nxt.lim >= lim) {
                dis[nxt.id] = dis[t.id] + nxt.w;
                q.push({nxt.id, dis[nxt.id]});
            }
    }
}
signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> vals;
    for (int i = 1; i <= m; i ++) {
        int u, v, w, lim;
        cin >> u >> v >> w >> lim;
        vals.push_back(lim);
        g[u].push_back({v, w, lim});
        g[v].push_back({u, w, lim});
    }
    int ans = 0;
    for (int lim : vals) {
        dijkstra(1, lim);
        if (dis[n] < 9e12)
            ans = max(ans, lim * (int)(1e6) / dis[n]);
    }
    cout << ans;
    return 0;
}
