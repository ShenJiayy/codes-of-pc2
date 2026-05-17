#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
vector<int> g[N + 5], g2[N + 5];
int scc[N + 5], val[N + 5], dfn[N + 5], low[N + 5], tmstmp, curr, nval[N + 5], rd[N + 5];
stack<int> stk;
bool vis[N + 5];
void tarjan(int id) {
	dfn[id] = low[id] = ++ tmstmp;
	vis[id] = 1;
	stk.push(id);
	for (int nxt : g[id]) {
		if (!dfn[nxt]) {
			tarjan(nxt);
			low[id] = min(low[id], low[nxt]);
		}
		else if (vis[nxt])
			low[id] = min(low[id], dfn[nxt]);
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
int ans, dp[N + 5];
void topsort() {
	queue<int> q;
	for (int i = 1; i <= curr; i ++)
		if (rd[i] == 0)
			q.push(i), dp[i] = nval[i];
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int nxt : g2[t]) {
			dp[nxt] = max(dp[nxt], dp[t] + nval[nxt]);
			rd[nxt] --;
			if (rd[nxt] == 0)
				q.push(nxt);
		}
	} 
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
	}
	for (int i = 1; i <= n; i ++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i ++)
		for (int nxt : g[i])
			if (scc[i] != scc[nxt])
				g2[scc[i]].push_back(scc[nxt]), rd[scc[nxt]] ++;
	topsort();
	cout << *max_element(dp + 1, dp + curr + 1);
	return 0;
}