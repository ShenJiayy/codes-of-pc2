#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, a[N], b[N], len, w[N];

int main () {
	
	freopen ("b.in", "r", stdin);
	freopen ("b.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	
	sort (a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++) {
		if (a[i] == a[i - 1]) {
			w[len] ++;
			continue;
		}
		b[++ len] = a[i];
		w[len] = 1;
	}
	
	int low = 0, t, Min = 2e9, ans; 
	
	for (int i = 2; i <= len; i ++) {
		low += w[i - 1];
		t = abs(n - low - low);
		if (t <= Min) {
			Min = t;
			ans = b[i];
		}
	}
	
	cout << ans;
	
	return 0;
} 
