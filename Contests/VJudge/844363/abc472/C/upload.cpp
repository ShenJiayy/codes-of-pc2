#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int s[N + 5], a[N + 5];
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int r = 1; r <= n; r ++) {
		int l = max(r - m + 1, 1ll);
		s[r] = s[r - 1] + a[r];
		if (s[r] - s[l - 1] <= k)
			puts("Yes");
		else puts("No"), s[r] -= a[r];
	}
	return 0;
}
