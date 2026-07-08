#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25e4;
int a[N + 5];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	int minn = *min_element(a + 1, a + n + 1),
		maxn = *max_element(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
		cout << max(a[i] - minn, maxn - a[i]) << "\n";
	return 0;
}
