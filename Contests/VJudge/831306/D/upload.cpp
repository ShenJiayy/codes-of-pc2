#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i ++) 
		if (a[i] >= a[i - 1])
			ans += a[i] - a[i - 1];
	cout << ans;
	return 0;
}
