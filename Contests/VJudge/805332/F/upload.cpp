#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000;
int c[N + 5][N + 5];
signed main() {
	const int mod = 1e9 + 7;
	c[0][0] = 1;
	for (int i = 1; i <= N + 3; i ++)
		for (int j = 1; j <= i; j ++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1], c[i][j] %= mod;
	int n, m;
    cin >> n >> m;
    cout << c[n + 1][m + 1];
	return 0;
}