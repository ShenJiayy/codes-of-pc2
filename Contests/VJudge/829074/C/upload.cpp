#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500;
int f[N * N + 5], n, m;
struct Point {
	int col, id;
} a[N + 5][N + 5];
int find(int id) {
	if (f[id] != id)
		f[id] = find(f[id]);
	return f[id];
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy)
		f[fx] = fy;
}
void init(int n) {
	for (int i = 1; i <= n; i ++)
		f[i] = i;
}
int siz[N * N + 5], col[N * N + 5];
bool vis[N + 5][N + 5];
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
set<int> st;
void dfs(int x, int y) {
	if (!(1 <= x && x <= n && 1 <= y && y <= m)) return ;
	if (vis[x][y]) return ;
	vis[x][y] = 1;
	for (int k = 0; k < 4; k ++) {
		int tx = x + dx[k], ty = y + dy[k];
		if (a[tx][ty].col == a[x][y].col)
			dfs(tx, ty);
		else 
			st.insert(f[a[tx][ty].id]);
	}
}
signed main() {
	cin >> n >> m;
	init(n * m);
	for (int i = 1, curr = 0; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j].col;
			a[i][j].id = ++ curr;
			if (a[i][j].col == a[i - 1][j].col && i > 1)
				merge(a[i][j].id, a[i - 1][j].id);
			if (a[i][j].col == a[i][j - 1].col && j > 1)
				merge(a[i][j].id, a[i][j - 1].id);
		}
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			siz[find(a[i][j].id)] ++;
			col[find(a[i][j].id)] = a[i][j].col;
			ans = max(ans, siz[find(a[i][j].id)]);
		}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			if (vis[i][j]) continue;
			st.clear();
			map<int, int> mp;
			dfs(i, j);
			for (int val : st) 
				mp[col[val]] += siz[val];
			int maxn = 0;
			for (auto kv : mp)
				maxn = max(maxn, kv.second);
			ans = max(ans, siz[find(a[i][j].id)] + maxn);
		}
	cout << ans;
	return 0;
}