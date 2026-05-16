#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int l, r;
		cin >> l >> r;
		// l %= 9, r %= 9, r += 9;
        r -= (r - l + 1) / 9 * 9;
		int res = 0;
		for (int i = l; i <= r; i ++)
			res += i % 9, res %= 9;
		cout << res << endl;
	}
    return 0;
}