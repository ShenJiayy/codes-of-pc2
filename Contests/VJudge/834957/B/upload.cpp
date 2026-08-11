#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, lgN = 20;
vector<int> g[N + 5];
namespace bcj {
	int f[N + 5];
	inline void init(int n) {
		for (int i = 1; i <= n; i ++)
			f[i] = i;
	}
	int find(int id) {
		if (f[id] != id)
			f[id] = find(f[id]);
		return f[id];
	}
	inline void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx != fy)
			f[fx] = fy; 
	}
}
namespace tps {
	int rd[N + 5];
	bool vis[N + 5];
	inline void init(int n) {
		memset(vis, 0, sizeof vis);
		memset(rd, 0, sizeof rd);
		for (int u = 1; u <= n; u ++)
			for (int v : g[u])
				rd[v] ++;
		queue<int> q;
		for (int i = 1; i <= n; i ++)
			if (rd[i] == 0)
				q.push(i);
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			vis[t] = 1;
			for (int nxt : g[t]) {
				rd[nxt] --;
				if (rd[nxt] == 0)
					q.push(nxt);
			}
		}
	}
}
namespace pre {
	int rt[N + 5], dep[N + 5], f[N + 5];
	void dfs(int id, int ft, int fr) {
		if (rt[id])
			return ;
		rt[id] = fr;
		f[id] = ft;
		if (f[id] == 0) f[id] = id;
		dep[id] = dep[ft] + 1;
		for (int nxt : g[id])
			if (tps::vis[nxt])
				dfs(nxt, id, fr);
	}
	inline void init(int n) {
		memset(rt, 0, sizeof rt);
		dep[0] = -1;
		for (int i = 1; i <= n; i ++)
			if (!tps::vis[i])
				dfs(i, 0, i);
		dep[0] = 0;
	}
}
namespace pos {
	int pos[N + 5], cl[N + 5], where[N + 5];
	int cc;
	inline void init(int n) {
		memset(pos, -1, sizeof pos);
		memset(where, -1, sizeof where);
		cc = 0;
		for (int i = 1; i <= n; i ++) 
			if (tps::vis[i] == 0 && pos[i] == -1) {
				int st = i, curr = i, idx = 1;
				pos[curr] = idx;
				where[curr] = ++ cc;
				curr = g[curr][0];
				cl[cc] = 1;
				while (1) {
					if (curr == st)
						break;
					idx ++;
					pos[curr] = idx;
					where[curr] = cc;
					cl[cc] ++;
					curr = g[curr][0];
				}
			}
	}
}
namespace lca {
	int dp[N + 5][lgN + 5];
	inline void init(int n) {
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i ++)
			dp[i][0] = pre::f[i];
		for (int j = 1; j <= lgN; j ++)
			for (int i = 1; i <= n; i ++)
				if (tps::vis[i])
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
	}
	inline int query(int x, int y) {
		while (pre::dep[x] > pre::dep[y])
			x = pre::f[x];
		while (pre::dep[y] > pre::dep[x])
			y = pre::f[y];
		for (int k = lgN; k >= 0; k --)
			if (dp[x][k] != dp[y][k])
				x = dp[x][k], y = dp[y][k];
		return dp[x][0];
	}
}
pair<int, int> solve(int n, int x, int y) {
	if (bcj::find(x) != bcj::find(y))
		return {-1, -1};
	if (pre::rt[x] == pre::rt[y]) {
		int lc = lca::query(x, y);
		using namespace pre;
		return {dep[x] - dep[lc], dep[y] - dep[lc]};
	}
	int rx = pre::rt[x], ry = pre::rt[y];
	int l = pos::cl[pos::where[rx]];
	int p1x = pre::dep[x] + (pos::pos[ry] - pos::pos[rx] + l) % l, p1y = pre::dep[y];
	int p2x = pre::dep[x], p2y = (pos::pos[rx] - pos::pos[ry] + l) % l + pre::dep[y];
	if (max(p1x, p1y) < max(p2x, p2y))
		return {p1x, p1y};
	if (max(p1x, p1y) > max(p2x, p2y))
		return {p2x, p2y};
	if (min(p1x, p1y) < min(p2x, p2y))
		return {p1x, p1y};
	if (min(p1x, p1y) > min(p2x, p2y))
		return {p2x, p2y};
	if (p1x >= p1y)
		return {p1x, p1y};
	if (p2x >= p2y)
		return {p2x, p2y};
	return {-1, -1};
}
int main() {
	int n, T;
	cin >> n >> T;
	bcj::init(n);
	for (int v = 1; v <= n; v ++) {
		int u;
		cin >> u;
		g[u].push_back(v);
		bcj::merge(v, u);
	}
	tps::init(n);
	pre::init(n);
	pos::init(n);
	lca::init(n);
	while (T --) {
		int x, y;
		cin >> x >> y;
		auto ret = solve(n, x, y);
		cout << ret.first << " " << ret.second << endl;
	}
	return 0;
}