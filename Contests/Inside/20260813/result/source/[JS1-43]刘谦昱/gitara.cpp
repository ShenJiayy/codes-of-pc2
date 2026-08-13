#include <iostream>
#include <queue>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 3e5 + 5;
int q, n, ans;
priority_queue <int> pq[10];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("gitara.in", "r", stdin);
	freopen("gitara.out", "w", stdout);
	cin >> q >> n;
	while (q--) {
		int i, j;
		cin >> i >> j;
		while (!pq[i].empty() && pq[i].top() > j) ans++, pq[i].pop();
		if (pq[i].empty() || pq[i].top() < j) ans++, pq[i].push(j);
	}
	cout << ans;
	return 0;
}
