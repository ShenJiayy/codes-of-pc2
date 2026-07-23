#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000;
struct Edge {
    int u, v, w, b;
} e[N + 5];
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
int dis[N + 5], dis1[N + 5], disn[N + 5];
bool vis[N + 5];
bool operator < (Node x, Node y) {
    return x.w > y.w;
}
void dijkstra(int id, int maxn) {
    priority_queue<Node> q;
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    dis[id] = 0;
    q.push({id, 0});
    while (!q.empty()) {
        Node t = q.top();
        q.pop();
        if (vis[t.id]) continue;
        vis[t.id] = 1;
        for (Node nxt : g[t.id])
            if (dis[nxt.id] > dis[t.id] + e[nxt.w].w && e[nxt.w].b <= maxn) {
                dis[nxt.id] = dis[t.id] + e[nxt.w].w;
                q.push({nxt.id, dis[nxt.id]});
            }
    }
}
void dfs(int id) {
    if (vis[id]) return ;
    vis[id] = 1;
    for (Node nxt : g[id])
        dfs(nxt.id);
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w >> e[i].b;
        g[e[i].u].push_back({e[i].v, i});
        g[e[i].v].push_back({e[i].u, i});
    }
    memset(vis, 0, sizeof vis);
    dfs(1);
    if (vis[n] == 0) 
        return puts("-1"), 0;
    int ans = 9e18;
    for (int i = 1; i <= m; i ++) {
        dijkstra(1, e[i].b);
        memcpy(dis1, dis, sizeof dis);
        dijkstra(n, e[i].b);
        memcpy(disn, dis, sizeof dis);
        // 1~e[i].u -> e[i].v ~ n
        ans = min(ans, min(dis1[e[i].u] + disn[e[i].v], dis1[e[i].v] + disn[e[i].u]));
    }
    cout << ans;
    return 0;
}