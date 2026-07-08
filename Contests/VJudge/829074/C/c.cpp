#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500;
int a[N + 5][N + 5], n, m, bel[N + 5][N + 5], cid;
const int dx[] = {0, 0, 1, -1},
		  dy[] = {1, -1, 0, 0};
bool vis[N + 5][N + 5];
void dfs1(int i, int j) {
	if (!(1 <= i && i <= n && 1 <= j && j <= m)) return ;
	if (bel[i][j]) return ;
	bel[i][j] = cid;
	for (int k = 0; k < 4; k ++)
		dfs1(i + dx[k], j + dy[k]);
}
int dfs2(int i, int j, int c) {
	if (!(1 <= i && i <= n && 1 <= j && j <= m)) return 0;
	if (vis[i][j] || a[i][j] != c) return 0;
	vis[i][j] = 1;
	int sum = 1;
	for (int k = 0; k < 4; k ++)
		sum += dfs2(i + dx[k], j + dy[k], c);
	return sum;
}
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> a[i][j];
	int maxn = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) 
			if (!bel[i][j]) {
				cid ++, dfs1(i, j);
			}
	cout << maxn;
	return 0;
}

