#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
	int id, w, st;
};
bool operator > (Node x, Node y) {
	return x.w > y.w;
}
const int N = 200;
vector<Node> g[N + 5];
int dis[N + 5][8192];
bool vis[N + 5][8192];
int msk[N + 5];
void dijkstra(int s) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    q.push({s, 0, msk[s]});
    dis[s][msk[s]] = 0;
    while (!q.empty()) {
        Node t = q.top();
        q.pop();
        if (vis[t.id][t.st]) continue;
        vis[t.id][t.st] = 1;
        for (Node nxt : g[t.id])
			if ((t.st | nxt.st) == t.st)
				if (dis[nxt.id][t.st | msk[nxt.id]] > dis[t.id][t.st] + nxt.w) {
					dis[nxt.id][t.st | msk[nxt.id]] = dis[t.id][t.st] + nxt.w;
					q.push({nxt.id, dis[nxt.id][t.st | msk[nxt.id]], t.st | msk[nxt.id]});
				}
    }
}
signed main() {
	int n, m, p, k;
	cin >> n >> m >> p >> k;
	while (k --) {
		int u, c;
		cin >> u >> c;
		while (c --) {
			int x;
			cin >> x;
			msk[u] |= 1 << x - 1;
		}
	}
	while (m --) {
		int u, v, w, c;
		cin >> u >> v >> w >> c;
		int r = 0;
		while (c --) {
			int x;
			cin >> x;
			r |= 1 << x - 1;
		}
		g[u].push_back({v, w, r});
		g[v].push_back({u, w, r});
	}
	dijkstra(1);
	int minn = 9e12;
	for (int i = 0; i < 8192; i ++)
		minn = min(minn, dis[n][i]);
	if (minn == 9e12)
		return puts("-1"), 0;
	cout << minn;
	return 0;
}