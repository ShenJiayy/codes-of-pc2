#include <iostream>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 5e2 + 5;
int n, m, q, col[N][N];
bool vis[N][N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("mask.in", "r", stdin);
	freopen("mask.out", "w", stdout);
	cin >> n >> m >> q;
	while (q--) {
		int op, x, y, c;
		cin >> op >> x >> y;
		if (op == 1) {
			cin >> c;
			F(i, x, x + 1) F(j, y, y + 1) if (!vis[i][j]) col[i][j] = c;
		} else F(i, x, x + 1) F(j, y, y + 1) vis[i][j] = 1;
	}
	F(i, 1, n) {
		F(j, 1, m) cout << col[i][j] << ' ';
		cout << '\n';
	} 
	return 0;
}
