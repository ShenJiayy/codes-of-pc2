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
	sort(a + 1, a + n + 1);
	int sum = 0;
	while (n >= 4) {
		sum += min(a[1] + a[n - 1] + a[1] + a[n], a[1] + a[2] + a[n] + a[2]);
		n -= 2;
	}
	if (n == 2)
		sum += a[2];
	if (n == 3)
		sum += a[2] + a[1] + a[3];
	cout << sum;
	return 0;
}
