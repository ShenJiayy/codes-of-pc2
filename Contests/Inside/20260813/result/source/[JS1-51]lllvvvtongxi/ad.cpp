#include <bits/stdc++.h>
using namespace std;

int n, a[500005], x;

int main () {
	
	freopen ("ad.in", "r", stdin);
	freopen ("ad.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> x;
		
	sort (a + 1, a + n + 1);
	
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		if (a[i] != a[i - 1]) ans ++;
	
	cout << ans;
	
	return 0;
	
}
