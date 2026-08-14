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
signed main() {
    int w, m1, n, m2, s;
    cin >> w >> m1 >> n >> m2 >> s;
    for (int i = 1; i <= m1; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, -w});
    }
    for (int i = 1; i <= m2; i ++) {
        int u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({v, d - w});
    }
    if (spfa(s, n)) 
        return puts("-1"), 0;
    int maxn = 0;
    for (int i = 1; i <= n; i ++)
        maxn = max(maxn, -dis[i]);
    cout << maxn + w;
    return 0;
}

