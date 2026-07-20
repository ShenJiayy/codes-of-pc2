#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int t1[N + 5], t2[N + 5];
inline int lowbit(int x) {
	return x & -x;
}
inline void update(int p, int d, int t[]) {
	if (p < 1) return ;
	for (; p <= N; p += lowbit(p))
		t[p] += d;
}
inline int query(int p, int t[]) {
	if (p < 1) return 0;
	int ans = 0;
	for (; p; p -= lowbit(p))
		ans += t[p];
	return ans;
}
signed main() {
	int n, T;
	cin >> n >> T;
	while (T --) {
		int opt, l, r;
		cin >> opt >> l >> r;
		if (opt == 1)
			update(l, 1, t1), update(r, 1, t2);
		else
			cout << query(r, t1) - query(l - 1, t2) << endl;
	}
	return 0;
}
