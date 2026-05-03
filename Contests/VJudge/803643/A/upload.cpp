#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 100003;
int qpow(int a, int b, int p) {
	int t = 1;
	while (b) {
		if (b & 1) 
			t = t * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return t;
}
signed main() {
    int n, m;
	cin >> m >> n;
	cout << (qpow(m, n, mod) - m % mod * qpow(m - 1, n - 1, mod) % mod + mod) % mod;
    return 0;
}