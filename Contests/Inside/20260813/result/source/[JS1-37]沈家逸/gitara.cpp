#include <bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int> q[10];
const int P = 3e5;
bool vis[8][P + 5];
signed main() {
	freopen("gitara.in", "r", stdin);
	freopen("gitara.out", "w", stdout);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		int x, y;
		cin >> x >> y;
		if (!vis[x][y]) {
			q[x].push(y);
			vis[x][y] = 1;
			cnt ++;
		}
		while (!q[x].empty() && q[x].top() > y) {
			vis[x][q[x].top()] = 0;
			q[x].pop();
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}
