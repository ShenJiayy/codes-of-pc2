#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
int dis[N + 5], cnt[N + 5];
bool vis[N + 5], dang[N + 5];
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
bool ctl[N + 5];
signed main() {
    int n, m, k, dist, p, q;
	cin >> n >> m >> k >> dist >> p >> q;
	for (int i = 1; i <= k; i ++) {
		int x;
		cin >> x;
		g[0].push_back({x, 0});
		ctl[x] = 1;
	}
	for (int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		if (ctl[u] && ctl[v]) continue;
		if (ctl[u])
			g[0].push_back({u, 0});
		else if (ctl[v])
			g[0].push_back({v, 0});
		g[u].push_back({v, 1}),
		g[v].push_back({u, 1});
	}
	spfa(0, n);
	for (int i = 1; i <= n; i ++)
		if (dis[i] <= dist)
			dang[i] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < g[i].size(); j ++) {
			int u = i, v = g[i][j].id, w = 0;
			if (ctl[u] || ctl[v])
				w = 9e15;
			else if (dang[v])
				w = q;
			else w = p;
			if (v == n)
				w = 0;
			g[i][j].w = w;
		}
	spfa(1, n);
	cout << dis[n];
    return 0;
}