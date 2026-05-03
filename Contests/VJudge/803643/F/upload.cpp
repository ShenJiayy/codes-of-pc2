#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int T, n, m, p;
	cin >> T >> n >> m >> p;
	// answer: A(n - m + 1, m) mod p
	int ans = 1;
	for (int i = n - m + 1; i >= (n - m + 1) - m + 1; i --)
		ans = ans * i % p;
	cout << ans;
	return 0;
}
