#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int c[N + 5][N + 5];
int lucas(int n, int k, int p) {
	if (k == 0) return 1;
	return (c[n % p + 1][k % p + 1] * lucas(n / p, k / p, p)) % p;
}
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int n, m, p;
		cin >> n >> m >> p;
		c[0][0] = 1;
		for (int i = 1; i <= p; i ++)
			for (int j = 1; j <= i; j ++)
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1], c[i][j] %= p;
		cout << lucas(n + m, m, p) << endl;
	}
	return 0;
}

