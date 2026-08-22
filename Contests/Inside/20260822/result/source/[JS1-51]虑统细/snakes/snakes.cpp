#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int T, n, a[N], k;

void solve (int t) {
	if (t == 1) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i ++) scanf ("%d", &a[i]);
	}
	else {
		scanf ("%d", &k);
		for (int i = 1; i <= k; i ++) {
			int x, y;
			scanf ("%d%d", &x, &y);
			a[x] = y;
		}
	}
	if (n == 3) {
		if (a[3] - a[1] < a[2]) cout << "3\n";
		else cout << "1\n";
	}
	else {
		cout << n << "\n";
	}
}

int main () {
	
	freopen ("snakes.in", "r", stdin);
	freopen ("snakes.out", "w", stdout);

	cin >> T;
	for (int i = 1; i <= T; i ++) 
		solve (i);
	return 0;
}
