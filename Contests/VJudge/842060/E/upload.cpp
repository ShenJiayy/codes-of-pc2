#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6, N = 2e5;
struct Node {
    int x, y, id;
} a[M + 5];
bool cmpx(Node x, Node y) {
    if (x.x != y.x) 
        return x.x < y.x;
    return x.y < y.y;
}
bool cmpy(Node x, Node y) {
    if (x.y != y.y)
        return x.y < y.y;
    return x.x < y.x;
}
struct Point {
    int id, w;
};
vector<Point> g[N + 5]; 
bool operator >(Point x, Point y) {
    return x.w > y.w;
}
int dis[N + 5];
bool vis[N + 5];
void dijkstra(int s) {
    priority_queue<Point, vector<Point>, greater<Point>> q;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty()) {
        Point t = q.top();
        q.pop();
        if (vis[t.id]) continue;
        vis[t.id] = 1;
        for (Point nxt : g[t.id])
            if (dis[nxt.id] > dis[t.id] + nxt.w) {
                dis[nxt.id] = dis[t.id] + nxt.w;
                q.push({nxt.id, dis[nxt.id]});
            }
    }
}
signed main() {
    int n, m;
    cin >> n >> m;
    n = m + 2;
    int s = n - 1, t = n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y, a[i].id = i;
    sort(a + 1, a + n + 1, cmpx);
    for (int i = 1; i < n; i ++)
        if (a[i].x == a[i + 1].x) {
            g[a[i].id].push_back({a[i + 1].id, a[i + 1].y - a[i].y << 1});
            g[a[i + 1].id].push_back({a[i].id, a[i + 1].y - a[i].y << 1});
        }
    sort(a + 1, a + n + 1, cmpy);
    for (int i = 1; i < n; i ++)
        if (a[i].y == a[i + 1].y) {
            g[a[i].id + n].push_back({a[i + 1].id + n, a[i + 1].x - a[i].x << 1});
            g[a[i + 1].id + n].push_back({a[i].id + n, a[i + 1].x - a[i].x << 1});
        }
    for (int i = 1; i <= m; i ++)
        g[i].push_back({i + n, 1}),
        g[i + n].push_back({i, 1});
    g[s].push_back({s + n, 0}), g[s + n].push_back({s, 0}),
    g[t].push_back({t + n, 0}), g[t + n].push_back({t, 0});
    dijkstra(s);
    if (dis[t] > 9e12)
        puts("-1");
    else cout << dis[t];
    return 0;
}
