#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug
int fp(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ret = ret * a % p;
	return ret;
}
const int N = 1e7, mod = 998244353;
int fct[N + 5], inv[N + 5], d[N + 5], s[N + 5];
void init(int n) {
	fct[0] = 1;
	for (int i = 1; i <= n + 1; i ++)
		fct[i] = fct[i - 1] * i % mod;
	inv[n + 1] = fp(fct[n + 1], mod - 2, mod);
	for (int i = n; i >= 0; i --) 
		inv[i] = inv[i + 1] * (i + 1) % mod;
}
int getcc(int n, int m) {
    if (m < 0 || m > n) return 0;
	return fct[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
	int n;
	cin >> n;
	init(n);
	int l1 = 0, l2 = 0, r1 = n, r2 = n;
	for (int i = 1; i <= n; i ++) {
		int l, r;
		cin >> l >> r;
		d[l] ++, d[r + 1] --;
		int a = n - r, b = n - l;
		if (l > a)
			l = a, r = b;
		l1 = max(l1, l), r1 = min(r1, r);
		l2 = max(l2, n - r), r2 = min(r2, n - l);
	}
	for (int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + d[i];
	int ans = 0;
	for (int a = 1; a < n; a ++) 
		if (l1 <= a && a <= r1 || l2 <= a && a <= r2)
			ans += getcc(s[a] + s[n - a] - n, s[a] - a), ans %= mod;
	cout << ans;
	return 0;
}