#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000, mod = 998244353;
int dp[N + 5][2][N + 5];
vector<int> g[N + 5];
int dfs(int id, int ft) {
	int tot = 1;
	dp[id][0][0] = dp[id][1][1] = 1;
	for (int nxt : g[id]) if (nxt != ft) {
		int nxc = dfs(nxt, id);
		for (int i = tot; i >= 0; i --)
			for (int j = nxc; j >= 1; j --) 
				dp[id][0][i + j] += dp[id][0][i] * (dp[nxt][0][j] + dp[nxt][1][j]) % mod, 
				dp[id][0][i + j] %= mod;
		for (int i = tot; i >= 1; i --)
			for (int j = nxc; j >= 1; j --) 
				dp[id][1][i + j] += dp[id][1][i] * dp[nxt][0][j] % mod, 
				dp[id][1][i + j] %= mod,
				dp[id][1][i + j - 1] += dp[id][1][i] * dp[nxt][1][j] % mod, 
				dp[id][1][i + j - 1] %= mod;
		tot += nxc;
	}
	return tot;
}
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i ++)
		cout << (dp[1][0][i] + dp[1][1][i]) % mod << endl;
	return 0;
} 
