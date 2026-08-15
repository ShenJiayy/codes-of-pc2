#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n, L, x[N], t[N], ans;

int vis[N], p[N];
void dfs (int d) {
	if (d == n) {
		int tim, sum, pos;
		tim = sum = 0; pos = 1;
		for (int i = 1; i <= n; i ++) {
			tim += min (abs (pos - x[p[i]]), L - abs (pos - x[p[i]]));
			if (tim <= t[p[i]])
				sum ++;
			pos = x[p[i]];
		}
		ans = max (ans, sum);
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (vis[i]) continue;
		p[d + 1] = i;
		vis[i] = 1;
		dfs (d + 1);
		vis[i] = 0;
	}
}

int main () {
	
	freopen ("stamps.in", "r", stdin);
	freopen ("stamps.out", "w", stdout);
	
	cin >> n >> L;
	
	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
		x[i] += 1;
		x[i] %= L;
	}
	
	for (int i = 1; i <= n; i ++) {
		cin >> t[i];
	}
	
	dfs (0);
	
	cout << ans;
	
	return 0;
	
}
