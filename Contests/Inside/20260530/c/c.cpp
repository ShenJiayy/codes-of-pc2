#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, M = 10;
struct Thing {
	int val, idx;
} a[N + 5];
int s[N + 5][M + 5], mp[N + 5], idx[N + 5];
void task1(int T) {
	while (T --) {
		int d, l, r, ans = 0;
		cin >> d >> l >> r;
		for (int i = l; i <= r; i ++)
			if (a[i].idx == d)
				ans += a[i].val / 2;
			else 
				ans += a[i].val;
		cout << ans << endl;
	}
}
void task2(int n, int T) {
	for (int i = 1; i <= n; i ++)
		s[i][0] = s[i - 1][0] + a[i].val;
	while (T --) {
		int d, l, r, ans = 0;
		cin >> d >> l >> r;
		cout << s[r][0] / 2 - s[l - 1][0] / 2 << endl;
	}
}
void task3(int n, int m, int T) {
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			s[i][j] = s[i - 1][j] + a[i].val * (a[i].idx == j);
	for (int i = 1; i <= n; i ++)
		s[i][0] = s[i - 1][0] + a[i].val;
	while (T --) {
		int d, l, r, ans = 0;
		cin >> d >> l >> r;
		cout << (s[r][0] - s[l - 1][0]) - (s[r][d] - s[l - 1][d]) / 2 << endl;
	}
}
void task4(int n, int m, int T) {
	for (int i = 1; i <= n; i ++)
		mp[a[i].idx] = a[i].val, idx[a[i].idx] = i;
	for (int i = 1; i <= n; i ++)
		s[i][0] = s[i - 1][0] + a[i].val;
	while (T --) {
		int d, l, r;
		cin >> d >> l >> r;
		cout << s[r][0] - s[l - 1][0] - (l <= idx[d] && idx[d] <= r) * mp[d] / 2 << endl;
	}
}
signed main() {
	int n, m, T;
	cin >> n >> m >> T;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].val >> a[i].idx, mp[a[i].idx] ++;
	if (m == 1)
		task2(n, T);
	else if (m <= 10)
		task3(n, m, T);
	else if (*max_element(mp + 1, mp + N + 1) < 2)
		task4(n, m, T);
	else if (*max_element(mp + 1, mp + N + 1) < 2)
		task4(n, m, T);
	else task1(T);
	return 0;
} 
