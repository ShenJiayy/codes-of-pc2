#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
vector<bool> a[N + 5], vis[N + 5];
int sc[N + 5], sl[N + 5];
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
struct Stat {
	int x, y, dis;
};
bool operator > (Stat x, Stat y) {
	return x.dis > y.dis;
}
vector<int> dis[N + 5];
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		a[i].resize(m + 1, 0),
		vis[i].resize(m + 1, 0),
		dis[i].resize(m + 1, 9e18);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			char c;
			cin >> c;
			if (c == '.')
				a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			sl[i] += a[i][j], sc[j] += a[i][j];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (sl[i] + sc[j] == 0)
				vis[i][j] = 1;
	priority_queue<Stat, vector<Stat>, greater<Stat>> q;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (vis[i][j])
				q.push({i, j, 0});
	while (!q.empty()) {
		auto [x, y, td] = q.top(); q.pop();
		if (td > k)
			continue;
		if (!(1 <= x && x <= n && 1 <= y && y <= m))
			continue;
		dis[x][y] = min(dis[x][y], td);
		for (int i = 0; i < 4; i ++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!(1 <= nx && nx <= n && 1 <= ny && ny <= m))
				continue;
			if (a[nx][ny]) continue;
			Stat ns = {nx, ny, td + 1};
			if (dis[nx][ny] > td + 1)
				dis[nx][ny] = td + 1,
				q.push(ns);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (dis[i][j] <= k)
				cnt ++;
	cout << cnt;
	return 0;
}
