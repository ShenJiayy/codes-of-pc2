#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
struct Query {
	char opt;
	int x, y;
} qs[N + 5];
int a[N + 5];

int t1[N + 5], t2[N + 5];
inline int lowbit(int x) { return x & -x; }
inline void update(int p, int d, int t[]) { for (; p <= N; p += lowbit(p)) t[p] += d; }
inline int query(int p, int t[]) { int ret = 0; for (; p; p -= lowbit(p)) ret += t[p]; return ret; }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, T;
	cin >> n >> T;
	for (int t = 1; t <= T; t ++)
		cin >> qs[t].opt >> qs[t].x >> qs[t].y;
	unordered_map<int, int> mp;
	set<int> tmp;
	for (int t = 1; t <= T; t ++)
		tmp.insert(qs[t].y);
	tmp.insert(0);
	int curr = 0;
	for (int val : tmp)
		curr ++, mp[val] = curr;
	update(mp[0], n, t2);
	for (int t = 1; t <= T; t ++) {
		if (qs[t].opt == 'U') {
			update(mp[ a[qs[t].x] ], -a[qs[t].x], t1);
			update(mp[ a[qs[t].x] ], -1, t2);
			a[qs[t].x] = qs[t].y;
			update(mp[ a[qs[t].x] ], a[qs[t].x], t1);
			update(mp[ a[qs[t].x] ], 1, t2);
		}
		else {
			int p = query(mp[qs[t].y], t1) + (n - query(mp[qs[t].y], t2)) * qs[t].y;
			if (p < qs[t].x * qs[t].y)
				cout << "NIE\n";
			else cout << "TAK\n";
		}
	}
	return 0;
} 