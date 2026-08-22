#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int T, n, a[N], p[N][2], q[N];
bool ok;
char ans[N], wd[N];

void init () {
	ok = 0;
	for (int i = 1; i <= n; i ++)
		p[i][0] = p[i][1] = 0;
	wd[1] = q[1] = 0;
}

void dfs (int l, int r, int xa, int xb, int t) {
	if (t == n + 1) {
		for (int i = 1; i <= n; i ++) {
			if (a[l] == q[n - i + 1]) {
				wd[n + i] = 'L';
				l ++;
			}
			else if (a[r] == q[n - i + 1]) {
				wd[n + i] = 'R';
				r --;
			}
			else return;
		}
		bool f = false;
		for (int i = 1; i <= 2 * n; i ++) {
			if (ans[i] > wd[i]) {
				f = 1;
				break;
			}
			if (ans[i] < wd[i]) break;
		}
		if (f) {
			for (int i = 1; i <= 2 * n; i ++)
				ans[i] = wd[i];
		}
		ok = 1;
		return;
	}
	if (a[l] != a[xa] && a[l] != a[xb] && a[r] != a[xa] && a[r] != a[xb])
		return;
	if (a[l] == a[xa] && xa >= l) {
		wd[t] = 'L';
		q[t] = a[l];
		dfs (l + 1, r, xa - 1, xb, t + 1);
		wd[t] = 0;
		q[t] = 0;
	}
	if (a[l] == a[xb] && xb <= r) {
		wd[t] = 'L';
		q[t] = a[l];
		dfs (l + 1, r, xa, xb + 1, t + 1);
		wd[t] = 0;
		q[t] = 0;
	}
	if (ok) return;
	if (a[r] == a[xa] && xa >= l) {
		wd[t] = 'R';
		q[t] = a[r];
		dfs (l, r - 1, xa - 1, xb, t + 1);
		wd[t] = 0;
		q[t] = 0;
	}
	if (a[r] == a[xb] && xb <= r) {
		wd[t] = 'R';
		q[t] = a[r];
		dfs (l, r - 1, xa, xb + 1, t + 1);
		wd[t] = 0;
		q[t] = 0;
	}
}

void solve () {
	scanf ("%d", &n);
	init ();
	for (int i = 1; i <= n * 2; i ++) {
		scanf ("%d", &a[i]);
		if (p[a[i]][0]) p[a[i]][1] = i;
		else p[a[i]][0] = i;
		ans[i] = 'Z';
	}
	wd[1] = 'L';
	q[1] = a[1];
	dfs (2, 2 * n, p[a[1]][1] - 1, p[a[1]][1] + 1, 2);
	if (!ok) {
		wd[1] = 'R';
		q[1] = a[2 * n];
		dfs (1, 2 * n - 1, p[a[2 * n]][0] - 1, p[a[2 * n]][0] + 1, 2);
	}
	if (!ok) printf ("-1\n");
	else {
		for (int i = 1; i <= 2 * n; i ++)
			printf ("%c", ans[i]);
		printf ("\n");
	}
}

int main () {
	
	freopen ("palin.in", "r", stdin);
	freopen ("palin.out", "w", stdout);

	scanf ("%d", &T);
	while (T --) {
		solve ();
	}
	return 0;
}

