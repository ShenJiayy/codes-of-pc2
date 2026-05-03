#include <bits/stdc++.h>
using namespace std;
#define int long long
void rep(char c, int n) {
	while (n --) cout << c;
}
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int n, a, b;
		cin >> n >> a >> b;
		if (n % 2 == 1 || (a + b) % 2 == 0) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		int m = 0;
		while (m + 2 < a) {
			rep('R', n - 1);
			cout << 'D';
			rep('L', n - 1);
			cout << 'D';
			m += 2;
		}
		int k = 0;
		while (k + 2 < b) {
			cout << "DRUR";
			k += 2;
		}
		if (k + 1 == b)
			cout << "RD";
		else
			cout << "DR";
		k += 2;
		while (k < n) {
			cout << "RURD";
			k += 2;
		}
		m += 2;
		while (m < n) {
			cout << 'D';
			rep('L', n - 1);
			cout << 'D';
			rep('R', n - 1);
			m += 2;
		}
		cout << endl;
	}
	return 0;
}
