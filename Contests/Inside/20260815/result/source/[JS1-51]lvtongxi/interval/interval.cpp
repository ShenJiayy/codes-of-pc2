#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m, ans = 2000000000;

struct Line {
	int l, r, len;
} a[N];

bool cmp (Line a, Line b) {
	if (a.l == b.l) return a.r <= b.r;
	return a.l < b.l;
}

int p[N], cnt, Mx, Mi = 10000000;

int main () {
	
	freopen ("interval.in", "r", stdin);
	freopen ("interval.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].l >> a[i].r;
		a[i].len = a[i].l - a[i].r + 1;
		Mx = max (Mx, a[i].r);
		Mi = min (Mi, a[i].l);
	}
		
	for (int i = Mi; i <= Mx; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (a[j].l <= i && a[j].r >= i) {
				p[++ cnt] = a[j].len;
			}
		}
		if (cnt < m) continue;
		sort (p + 1, p + cnt + 1);
		for (int j = 1; j <= cnt; j ++) {
			if (j + m - 1 > cnt) break;
			ans = min (ans, p[j + m - 1] - p[j]);
		}
		cnt = 0;
	}
	
	cout << ans;
	
	return 0;
	
}
