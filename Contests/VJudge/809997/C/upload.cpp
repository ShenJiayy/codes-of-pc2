#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, hsMax = N * 7;
vector<int> g[hsMax + 5];
int u[N + 5], v[N + 5];
bool ishol[hsMax + 5], vis[N + 5], ans;
inline int hs(int ct, int w) {
	return (ct - 1) * 7 + w;
}
inline pair<int, int> dehs(int val) {
	int ct = val / 7, w = val % 7;
	return {ct + 1, w};
}
void dfs(int id) {
	cerr << id << " ";
	if (vis[id]) {
		ans = 1;
		return ;
	}
	vis[id] = 1;
	for (int nxt : g[id])
		dfs(nxt);
}
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= hsMax; i ++)
			g[i].clear();
		memset(ishol, 0, sizeof ishol);
		memset(vis, 0, sizeof vis);
		ans = 0;
		for (int i = 1; i <= m; i ++) 
			cin >> u[i] >> v[i];
		int w;
		cin >> w;
		for (int i = 1; i <= w; i ++)
			for (int j = 1; j <= n; j ++) {
				char c;
				cin >> c;
				ishol[hs(j, i)] = (c == 'o');
			}
		for (int i = 1; i <= m; i ++) {
			int st = u[i], ed = v[i];
			for (int j = 1; j <= w; j ++) {
				int jnxt = (j == w)?1:(w + 1);
				if (ishol[hs(st, j)] && ishol[hs(ed, jnxt)])
					g[hs(st, j)].push_back(hs(ed, jnxt));
				if (ishol[hs(ed, j)] && ishol[hs(st, jnxt)])
					g[hs(ed, j)].push_back(hs(st, jnxt));
			}
		}
		for (int i = 1; i <= n; i ++) 
			for (int j = 1; j <= w; j ++) {
				int jnxt = (j == w)?1:(w + 1);
				if (ishol[hs(i, j)] && ishol[hs(i, jnxt)])
					g[hs(i, j)].push_back(hs(i, jnxt));
			}
		for (int i = 1; i <= n; i ++)
			if (!vis[i])
				dfs(i);
		cout << (ans?"Yes":"No") << endl;
		cerr << endl;
	}
	return 0;
}
