#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
ll n, a[N], ans;


int main () {
	
	freopen ("c.in", "r", stdin);
	freopen ("c.out", "w", stdout);
 
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n - 1; i ++) {
		ll sum = a[i] + a[i + 1];
		if (sum < 3) continue;
		ans += sum / 3;
		ll need = sum - (sum % 3);
		if (a[i] >= need) {
			a[i] -= need;
			continue;
		}
		need -= a[i];
		a[i] = 0;
		a[i + 1] -= need;
	}
	
	cout << ans;

	return 0;
} 
