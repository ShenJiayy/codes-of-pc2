#include <iostream>
#include <unordered_map>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 2e5 + 5;
int n, l = 1, a[N];
unordered_map <int, int> pos;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	cin >> n;
	F(i, 1, n) cin >> a[i], pos[a[i]] = i;
	while (1) {
		int r = pos[a[l]];
		F(i, l, r) cout << a[l] << '\n';
		if (r == n) return 0;
		l = r + 1;
	}
}
