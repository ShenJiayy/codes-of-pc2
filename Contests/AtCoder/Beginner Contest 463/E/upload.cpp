#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
int dis[N + 5], x[N + 5], n, m, y;
bool operator <(Node x, Node y) {
    return x.w > y.w;
}
void dijkstra(int id) {
    priority_queue<Node> q;
    q.push({id, 0});
    memset(dis, 0x3f, sizeof dis);
    dis[id] = 0;
    while (!q.empty()) {
        int t = q.top().id;
        q.pop();
        for (Node nxt : g[t])
            if (dis[nxt.id] > dis[t] + nxt.w)
                dis[nxt.id] = dis[t] + nxt.w,
                q.push({nxt.id, dis[nxt.id]});
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> y;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i ++)
        cin >> x[i];
    for (int i = 1; i <= n; i ++)
        g[i].push_back({0, x[i]});
    g[0].push_back({n + 1, y});
    for (int i = 1; i <= n; i ++)
        g[n + 1].push_back({i, x[i]});
    dijkstra(1);
    for (int i = 2; i <= n; i ++)
        cout << dis[i] << " ";
    return 0;
}
