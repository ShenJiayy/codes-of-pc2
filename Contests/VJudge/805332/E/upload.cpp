#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define debug
int fp(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ret = ret * a % p;
	return ret;
}
const int N = 1e6;
int mul[N + 5], inv[N + 5];
int getc(int n, int m, int p) {
	if (n < m) return 0;
	return mul[n] * fp(m, p - 2, p) % p * fp(n - m, p - 2, p) % p;
}
int lucas(int n, int m, int p) {
	if (m == 0) return 1;
	return getc(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
int a[N + 5];
void init(int n, int mod) {
	for (int i = 1; i <= n; i ++)
		mul[i] = mul[i - 1] * i % mod;
}
signed main() {
	int n;
	cin >> n;
	const int mod = 1e4 + 7;
	int res = 0;
	// a[i] * lucas(n - 1, i - 1, 1e4 + 7)
	init(n, mod);
	for (int i = 1, curr = 0; i * 2 <= n; i ++)
		a[i] = ++ curr, a[n - i + 1] = ++ curr;
	if (n % 2)
		a[n / 2 + 1] = n;
	for (int i = 1; i <= n; i ++) 
		res += a[i] * lucas(n - 1, i - 1, mod) % mod, res %= mod;
	cout << res;
	#ifdef debug
	for (int i = 1; i <= n; i ++) {
		cerr << a[i] << "*" << lucas(n - 1, i - 1, mod);
		if (i != n) cerr << "+";
		else cerr << "=";
	}
	#endif
	return 0;
}