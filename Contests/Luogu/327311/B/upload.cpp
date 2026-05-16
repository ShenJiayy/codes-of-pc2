#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
vector<int> g[N + 5], g2[N + 5];
int scc[N + 5], val[N + 5], dfn[N + 5], low[N + 5], tmstmp, curr, nval[N + 5];
stack<int> stk;
bool vis[N + 5];
void tarjan(int id) {
	dfn[id] = low[id] = ++ tmstmp;
	vis[id] = 1;
	stk.emplace(id);
	for (int nxt : g[id]) {
		if (!dfn[nxt]) {
			tarjan(nxt);
			low[id] = min(low[id], low[nxt]);
		}
		else if (vis[nxt])
			low[id] = min(low[id], low[nxt]);
	}
	if (dfn[id] == low[id]) {
		curr ++;
		while (!stk.empty()) {
			int top = stk.top();
			stk.pop();
			vis[top] = 0;
			scc[top] = curr;
			nval[curr] += val[top];
			if (top == id) break;
		}
	}
}
void dfs(int id) {

}
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> val[i];
	for (int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	tarjan(1);
	for (int i = 1; i <= n; i ++)
		
	return 0;
}