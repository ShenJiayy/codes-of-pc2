#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
vector<int> g[N + 5];
int dep[N + 5];
void dfs(int id, int ft) {
	dep[id] = dep[ft] + 1;
	for (int nxt : g[id])
		if (nxt != ft)
			dfs(nxt, id);
}
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, n);
	int maxn = *max_element(dep + 1, dep + n + 1);
	if (maxn >= m)
		cout << m;
	else {
		int ans = maxn + (m - (maxn - 1)) / 2;
		cout << min(ans, n);
	}
	return 0;
}
