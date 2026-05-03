#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, W = 10, hsMax = N * W;
vector<int> g[hsMax + 5];
int u[N + 5], v[N + 5], n, rd[hsMax + 5];
queue<int> q;
bool ishol[hsMax + 5];
inline int hs(int ct, int w) {
	return (w - 1) * n + ct;
}
void solve() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) 
		cin >> u[i] >> v[i];
	int w;
	cin >> w;
	for (int i = 1; i <= n * w; i ++)
		g[i].clear(), rd[i] = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= w; j ++) {
			char c;
			cin >> c;
			ishol[hs(i, j)] = (c == 'o');
		}
	for (int i = 1; i <= m; i ++) {
		int st = u[i], ed = v[i];
		for (int j = 1; j <= w; j ++) {
			int jnxt = (j == w?1:j + 1);
			if (ishol[hs(st, j)] && ishol[hs(ed, jnxt)])
				g[hs(st, j)].emplace_back(hs(ed, jnxt)), rd[hs(ed, jnxt)] ++;
			if (ishol[hs(ed, j)] && ishol[hs(st, jnxt)])
				g[hs(ed, j)].emplace_back(hs(st, jnxt)), rd[hs(st, jnxt)] ++;
		}
	}
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= w; j ++) {
			int jnxt = (j == w?1:j + 1);
			if (ishol[hs(i, j)] && ishol[hs(i, jnxt)])
				g[hs(i, j)].emplace_back(hs(i, jnxt)), rd[hs(i, jnxt)] ++;
		}
	for (int i = 1; i <= w * n; i ++)
		if (rd[i] == 0 && ishol[i])
			q.push(i);
	while (!q.empty()) {
		int tp = q.front();
		q.pop();
		for (int nxt : g[tp]) {
			rd[nxt] --;
			if (rd[nxt] == 0)
				q.push(nxt);
		}
	}
	for (int i = 1; i <= n * w; i ++)
		if (rd[i] && ishol[i]) {
			cout << "Yes\n";
			return ;
		}
	cout << "No\n";
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T --) solve();
	return 0;
}
