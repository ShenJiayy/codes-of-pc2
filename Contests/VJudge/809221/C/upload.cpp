#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9, K = 6;
int p[K + 5], n, k;
inline int cnt1(int x) {
	int cnt = 0;
	for (; x; x >>= 1) cnt += x & 1;
	return cnt;
}
int check(int x) {
	int cnt = 0;
	for (int i = 1, ppp = 1; i <= k; i ++, ppp *= -1) 
		for (int s = 0; s < (1 << k); s ++) 
			if (cnt1(s) == i) {
				int lcm = 1;
				for (int bit = 0; (1 << bit) <= s; bit ++)
					if (s >> bit & 1)
						lcm = lcm / __gcd(lcm, p[bit]) * p[bit];
				if (lcm <= x)
					cnt += x / lcm * ppp;
			}
	return cnt;
}
signed main() {
	cin >> n >> k;
	for (int i = 0; i < k; i ++)
		cin >> p[i];
	int l = 1, r = 9e18, ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid) >= n)
			ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}
// lcm(a, b) = a / gcd(a, b) * b;
