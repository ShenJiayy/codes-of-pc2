#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5, M = 20;
int root, st[N + 5][M + 5], dfn[N + 5], tmpstmp, a[N + 5], s[N + 5];
vector<int> g[N + 5];
int get(int x, int y) {
	if (dfn[x] < dfn[y]) return x;
	return y;
}
void dfs(int id, int ft) {
    s[id] = s[ft] + a[id];
	st[dfn[id] = ++ tmpstmp][0] = ft;
	for (int nxt : g[id])
		if (nxt != ft)
			dfs(nxt, id);
}
int query(int l, int r) {
	int sz = log2(r - l ++);
	return get(st[l][sz], st[r - (1 << sz) + 1][sz]);
}
int lca(int x, int y) {
	if (x == y) return x;
	int u = dfn[x], v = dfn[y];
	if (u > v) swap(u, v);
	int sz = log2(v - u);
    u ++;
    return get(st[u][sz], st[v - (1 << sz) + 1][sz]);
}
signed main() {
	// Write here.
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
	int n, q;
	cin >> n >> q;
    root = 1;
	for (int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
    for (int i = 1; i <= n; i ++)
        a[i] = g[i].size();
	dfs(root, 0);
	for (int i = 1; (1 << i) <= n; i ++)
        for (int j = 1; j <= n - (1 << i) + 1; j ++)
            st[j][i] = get(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
	while (q --) {
		int x, y;
		cin >> x >> y;
		cout << s[x] + s[y] - s[lca(x, y)] * 2 + a[lca(x, y)] << endl;
	}
	return 0;
} 