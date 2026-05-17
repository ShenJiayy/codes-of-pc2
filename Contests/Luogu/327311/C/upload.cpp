#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4;
vector<int> g[N + 5];
int dfn[N + 5], low[N + 5], tmstmp;
bool res[N + 5];
void tarjan(int id, bool ir = 0) {
	dfn[id] = low[id] = ++ tmstmp;
	int chcnt = 0;
	for (int nxt : g[id]) {
		if (!dfn[nxt]) {
			tarjan(nxt);
			low[id] = min(low[id], low[nxt]);
			if (low[nxt] >= dfn[id] && !ir)
				res[id] = 1;
			if (ir) chcnt ++;
		}
		else 
			low[id] = min(low[id], dfn[nxt]);
	}
	if (chcnt >= 2 && ir)
		res[id] = 1;
}
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++)
		if (!dfn[i])
			tarjan(i, 1);
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		cnt += res[i];
	cout << cnt << endl;
	for (int i = 1; i <= n; i ++)
		if (res[i])
			cout << i << " ";
	return 0;
}