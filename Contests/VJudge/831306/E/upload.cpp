#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> g[N + 5];
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int l, r;
		cin >> l >> r;
		g[l].push_back(r);
	}
	priority_queue<int, deque<int>, greater<int>> q;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int val : g[i])
			q.push(val);
		while (!q.empty()) {
			int t = q.top();
			q.pop();
			if (t < i)
				continue;
			ans ++;
			break;
		}
		cout << ans << endl;
	}
	return 0;
}
