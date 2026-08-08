#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
struct Node {
	int id, w;
};
vector<Node> g[N + 5];
int dp[N + 5][N + 5], siz[N + 5];
int n, m;
void dfs(int id, int ft) {
	siz[id] = 1;
	for (Node nxt : g[id])
		if (nxt.id != ft) {
			dfs(nxt.id, id);
			siz[id] += siz[nxt.id];
			for (int j = min(siz[id], m); j >= 0; j --) 
				for (int k = max(j - siz[id] + siz[nxt.id], 0ll); k <= min(siz[nxt.id], j); k ++)
					dp[id][j] = max(dp[id][j], dp[id][j - k] + dp[nxt.id][k] + nxt.w * k * (m - k) + nxt.w * (siz[nxt.id] - k) * (n - m - siz[nxt.id] + k));
		}
}
signed main() {
	cin >> n >> m;
	if (m > n - m) m = n - m;
	for (int i = 1; i < n; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(1, 0);
	cout << dp[1][m];
	return 0;
}
