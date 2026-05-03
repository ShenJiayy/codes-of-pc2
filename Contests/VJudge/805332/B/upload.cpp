#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e4 + 7, N = 1000;
int fp(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ret = ret * a % p;
	return ret;
}
int c[N + 5][N + 5];
signed main() {
	int a, b, k, n, m;
	cin >> a >> b >> k >> n >> m;
	// a^n * b^m * C(k, n)
	c[0][0] = 1;
	for (int i = 1; i <= N + 3; i ++)
		for (int j = 1; j <= i; j ++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1], c[i][j] %= mod;
	// for (int i = 1; i <= N + 3; i ++) {
	// 	for (int j = 1; j <= i; j ++)
	// 		cout << c[i][j] << " ";
	// 	cout << endl;
	// }
	cout << fp(a, n, mod) * fp(b, m, mod) % mod * c[k + 1][n + 1] % mod; 
	return 0;
}