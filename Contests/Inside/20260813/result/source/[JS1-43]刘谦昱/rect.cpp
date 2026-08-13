#include <iostream>
#include <cstring>
#include <vector>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 25e4 + 5;
int n, m;
bool h[N], l[N];

vector <vector <int>> a;
vector <vector <int>> pre;

inline bool check1() {
	return n <= 30 && m <= 30;
}

inline bool check2() {
	return n == 1;
}

inline bool check3() {
	F(i, 1, n) F(j, 1, m)
		if (a[i][j] != 0 && a[i][j] != 1)
			return 0;
	return 1;
}

inline void solve1() {
	int ans = 0;
	F(i, 1, n) F(j, 1, m)
		pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
	F(xa, 1, n) F(ya, 1, m) F(xb, xa, n) F(yb, ya, m)
		if (pre[xb][yb] - pre[xa - 1][yb] - pre[xb][ya - 1] + pre[xa - 1][ya - 1] == (xb - xa + 1) * (yb - ya + 1)) ans++;
	cout << ans;
	return ;
}

inline void solve2() {
	solve1();
	return ;
}

inline void solve3() {
	F(i, 1, n) F(j, 1, m) if (a[i][j] == 1) h[i] = 1, l[j] = 1;
	int cnth = 0, cntl = 0, len;
	len = 0;
	F(i, 1, n) {
		if (h[i] == 1) len++;
		else cnth += len * (len + 1) / 2, len = 0;
	}
	len = 0;
	F(i, 1, m) {
		if (l[i] == 1) len++;
		else cntl += len * (len + 1) / 2, len = 0;
	}
	cout << cnth * cntl;
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout);
	cin >> n >> m;
	a.resize(n + 5);
	F(i, 1, n) a[i].resize(m + 5, 0);
	pre.resize(n + 5);
	F(i, 0, n) pre[i].resize(m + 5, 0);
	F(i, 1, n) F(j, 1, m) cin >> a[i][j];
	if (check1()) solve1();
	else if (check2()) solve2();
	else if (check3()) solve3();
	return 0;
}
