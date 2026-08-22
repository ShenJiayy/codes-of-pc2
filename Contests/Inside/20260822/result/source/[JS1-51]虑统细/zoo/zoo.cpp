#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
const int N = 1e6 + 5;
const int B = 70;
int n, m, c, k, a[N], p[B];
bool bit[B];

int qp (int x, int t) {
	int res = 1;
	while (t) {
		if (t % 2) res *= x;
		x = x * x;
		t >>= 1;
	}
	return res;
}

signed main () {
	
	freopen ("zoo.in", "r", stdin);
	freopen ("zoo.out", "w", stdout);
	
	scanf ("%lld%lld%lld%lld", &n, &m, &c, &k);
	for (int i = 1; i <= n; i ++) {
		scanf ("%lld", &a[i]);
		int _i = a[i], _b = 0;
		while (_i) {
			bit[_b] |= (_i % 2);
			_b ++;
			_i /= 2;
		}
	}
	for (int i = 1; i <= m; i ++) {
		int pp, qq;
		scanf ("%lld%lld", &pp, &qq);
		if (!bit[pp] && !p[pp]) {
			k --;
			p[pp] = 1;
		}
	}
	if (n == 0 && m == 0 && k == 64) 
		cout << "18446744073709551616";
	else cout << qp (2, k) - n;
	return 0;
}
