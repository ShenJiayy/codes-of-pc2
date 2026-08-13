#include <iostream>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 2e5 + 5;
int n, a[N];

inline bool check1() {
	return n == 1;
}
inline void solve1() {
	cout << a[1] / 3;
	return ;
}

inline bool check2() {
	return n == 2;
}
inline void solve2() {
	cout << (a[1] + a[2]) / 3;
	return ;
}

inline bool check3() {
	F(i, 1, n) if (a[i] % 3) return 0;
	return 1;
}
inline void solve3() {
	int sum = 0;
	F(i, 1, n) sum += a[i];
	cout << sum / 3;
	return ;
}

inline bool check4() {
	F(i, 1, n) if (a[i] != 2) return 0;
	return 1;
}
inline void solve4() {
	int ans = n / 3 * 2, res = n % 3;
	if (res == 2) ans++;
	cout << ans;
	return ;
}

inline bool check5() {
	F(i, 1, n) if (a[i] > 3) return 0;
	return 1;
}
inline void solve5();

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> n;
	F(i, 1, n) cin >> a[i];
	if (check1()) solve1();
	else if (check2()) solve2();
	else if (check3()) solve3();
	else if (check4()) solve4();
	//else if (check5()) solve5();
	return 0;
}
