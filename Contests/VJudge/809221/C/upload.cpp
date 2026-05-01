#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9, K = 6;
int p[K + 5];
bool check(int x) {
	int cnt = 0;
	for (int i = 0; i < (1 << x); i ++) {
		
	}
}
signed main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i ++)
		cin >> p[i];
	int l = 1, r = 9e18, ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid))
			ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}
