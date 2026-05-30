#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4000;
int g[N + 5][N + 5], f[N + 5][N + 5];
bool vis[N + 5];
signed main() {
	int n, m, _;
	cin >> n >> m >> _;
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> _ >> w;
		f[u][v] = min(f[u][v], w);
	}
	for (int i = 1; i <= n; i ++) f[i][i] = 0;
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	if (f[1][n] == 0x3f3f3f3f3f3f3f3f)
		cout << -1;
	else cout << f[1][n];
	return 0;
}