#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 5e5 + 5;
int n, x[N], e[N];
unordered_map <int, bool> fl; 

struct node {
	int x, e;
	bool vis;
	bool operator < (const node &other) const {
		return e > other.e;
	}
} a[N];

inline bool check1() {
	F(i, 1, n - 1) if (e[i] != e[i + 1]) return 0;
	return 1;
}

inline void solve1() {
	F(i, 1, n) fl[x[i]] = 1;
	cout << fl.size();
	return ;
}

inline void solve2() {
	int ans = 0;
	F(i, 1, n) a[i].x = x[i], a[i].e = e[i], a[i].vis = 0;
	sort(a + 1, a + n + 1);
	F(i, 1, n) {
		if (a[i].vis) continue ;
		ans++, a[i].vis = 1;
		F(j, 1, n) {
			if (a[j].vis) continue ;
			if (abs(a[i].x - a[j].x) <= a[i].e - a[j].e) a[j].vis = 1;
		}
	}
	cout << ans;
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("ad.in", "r", stdin);
	freopen("ad.out", "w", stdout);
	cin >> n;
	F(i, 1, n) cin >> x[i] >> e[i];
	if (check1()) solve1();
	else solve2();
	return 0;
}
