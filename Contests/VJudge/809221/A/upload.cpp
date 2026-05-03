#include <bits/stdc++.h>
using namespace std;
#define int long long
int fp(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ret = ret * a % p;
	return ret;
}
signed main() {
	const int mod = 1e9 + 7;
	int all = fp(9, 10000, mod), one = fp(8, 10000, mod), ctall = fp(7, 10000, mod);
	cout << (all - one * 2 + ctall + mod) % mod;
	return 0;
}
