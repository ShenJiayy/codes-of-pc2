#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, lgN = 20;
vector<int> g[N + 5];
namespace tps {
	int rd[N + 5];
	bool vis[N + 5];
	void solve(int n) {
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
namespace lca {
	int dfn[N + 5], st[N + 5][lgN + 5], _, dep[N + 5];
    int get(int x, int y) {
        if (dfn[x] < dfn[y]) return x;
        return y;
    }
    void dfs(int id, int ft) {
		if (tps::vis[id] == 0)
			return ;
        st[dfn[id] = ++ _][0] = ft;
        dep[id] = dep[ft] + 1;
        for (int nxt : g[id])
            if (nxt != ft)
                dfs(nxt, id);
    }
    int query(int l, int r) {
        int sz = log2(r - l);
		l ++;
        return get(st[l][sz], st[r - (1 << sz) + 1][sz]);
    }
    int solve(int x, int y) {
        if (x == y) return x;
        int u = dfn[x], v = dfn[y];
        if (u > v) swap(u, v);
        int sz = log2(v - u);
        u ++;
        return get(st[u][sz], st[v - (1 << sz) + 1][sz]);
    }
    void init(int n) {
		for (int i = 1; i <= n; i ++)
			dfs(i, 0);
        for (int i = 1; (1 << i) <= n; i ++)
            for (int j = 1; j <= n - (1 << i) + 1; j ++)
                st[j][i] = get(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
    } 
}
namespace bcj {
	int f[N + 5];
	void init(int n) {
		for (int i = 1; i <= n; i ++)
			f[i] = i;
	}
	int find(int id) {
		if (f[id] != id)
			f[id] = find(f[id]);
		return f[id];
	}
	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx != fy)
			f[fx] = fy; 
	}
}
namespace bel {
	int ans[N + 5];
	void dfs(int id, int rt) {
		if (ans[id])
			return ;
		ans[id] = rt;
		for (int nxt : g[id])
			if (tps::vis[nxt])
				dfs(nxt, rt);
	}
	void solve(int n) {
		memset(ans, 0, sizeof ans);
		for (int i = 1; i <= n; i ++)
			if (!ans[i])
				dfs(i, i);
	}
}
pair<int, int> solve(int n, int x, int y) {
	if (bcj::find(x) != bcj::find(y))
		return {-1, -1};
	if (bel::ans[x] == bel::ans[y]) {
		int lc = lca::solve(x, y);
		string ans;
		using namespace lca;
		return {dep[x] - dep[lc], dep[y] - dep[lc]};
	}
	return {1048576, 1048576};
}
int main() {
	int n, T;
	cin >> n >> T;
	bcj::init(n);
	for (int u = 1; u <= n; u ++) {
		int v;
		cin >> v;
		g[u].push_back(v);
		bcj::merge(v, u);
	}
	tps::solve(n);
	lca::init(n);
	bel::solve(n);
	while (T --) {
		int x, y;
		cin >> x >> y;
		auto ret = solve(n, x, y);
		cout << ret.first << " " << ret.second << endl;
	}
	return 0;
}