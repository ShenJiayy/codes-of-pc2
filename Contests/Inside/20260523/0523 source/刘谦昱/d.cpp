#include <iostream>
#include <algorithm>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 5e5 + 5;
int n, q, sum;
int a[N], re[N];

inline bool cmp(int a, int b) {
	return a > b;
}

inline void solve() {
	int c, d, res = q;
	int use = 0, dif = 0;
	cin >> c >> d;
	if (c > d) {
		cout << sum << '\n';
		return ;
	}
	F(i, 1, n) {
		int mns = a[i] / d;
		if (res >= mns) {
			res -= mns, use += mns;
			dif += mns * d, re[i] = a[i] % d;
		} else {
			cout << sum + q * (c - d);
			return ;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	F(i, 1, n) {
		if (res == 0) {
			cout << sum - dif + use * c << '\n';
			return ;
		} else if (re[i] < c) {
			cout << sum - dif + use * c << '\n';
			return ;
		} else res--, use++, dif += re[i];
	}
	cout << sum - dif + use * c << '\n';
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("d.in", "r", stdin);
	freopen("d,out", "w", stdout);
	cin >> n >> q;
	F(i, 1, n) cin >> a[i], sum += a[i];
	F(i, 1, q) solve();
	return 0;
}
