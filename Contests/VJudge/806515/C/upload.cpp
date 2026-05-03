#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int inp[N + 5];
vector<int> g0, l0, a;
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int n, m;
		cin >> n >> m;
		a.clear();
		a.resize(n + 2, 0);
		for (int i = 1; i <= n; i ++)
			cin >> inp[i];
		int mid = n >> 1;
		for (int i = 1; i <= n; i ++) {
			if (i <= mid)
				a[i] = inp[i];
			else if (i > n - mid) {
				int pdi = n - i + 1;
				a[pdi] = (a[pdi] - inp[i] + m) % m;
			}
		}
		g0.clear();
		l0.clear();
		int sum = 0;
		for (int i = mid + 1; i >= 1; i --) {
			a[i] -= a[i - 1];
			if (a[i] > 0) {
				g0.push_back(a[i]);
				sum += a[i];
			}
			else if (a[i] < 0)
				l0.push_back(a[i]);
		}
		sort(g0.rbegin(), g0.rend());
		sort(l0.begin(), l0.end());
		int len = min(g0.size(), l0.size());
		for (int i = 0; i < len; i ++)
			if (m + l0[i] < g0[i])
				sum += m + l0[i] - g0[i];
		cout << sum << endl;
	}	
	return 0;
}
