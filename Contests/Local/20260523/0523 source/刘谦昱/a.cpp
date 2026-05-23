#include <iostream>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 5e5 + 5;
int n, cnt1, cnt2;
char a[N];

inline bool check(int i) {
	return a[i] == 'J' && a[i + 1] == 'O' && a[i + 2] == 'I';
}
inline void change(int i) {
	a[i] = 'O', a[i + 1] = 'I', a[i + 2] = 'J';
	return ;
}

inline bool check1() {
	return n <= 100;
}
inline void solve1() {
	bool fl = 0;
	F(i, 1, n - 2) if (check(i)) fl = 1, change(i);
	if (fl) solve1();
	return ;
}

inline bool check2() {
	if (n % 3) return 0;
	F(i, 1, n / 3) if (!check(i * 3 - 2)) return 0;
	return 1;
}
inline void solve2() {
	F(i, 1, n / 3) cout << "OI";
	F(i, 1, n / 3) cout << 'J';
	return ;
}

inline bool check3() {
	F(i, 1, n) {
		if (a[i] == 'J') cnt1++;
		else break;
	}
	for (int i = cnt1 + 1; i <= n - 1; i += 2) {
		if (a[i] == 'J' || a[i + 1] == 'J') return 0;
		if (a[i] == 'O' && a[i + 1] == 'I') cnt2++;
	}
	return 1;
}
inline void solve3() {
	F(i, 1, cnt2) cout << "OI";
	F(i, 1, cnt1) cout << 'J';
	F(i, cnt1 + 2 * cnt2 + 1, n) cout << a[i];
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> n;
	F(i, 1, n) cin >> a[i];
	if (check1()) {
		solve1();
		F(i, 1, n) cout << a[i];
	} else if (check2()) solve2();
	else if (check3()) solve3();
	else {
		solve1();
		F(i, 1, n) cout << a[i];
	}
	return 0;
}
