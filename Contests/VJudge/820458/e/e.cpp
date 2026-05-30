#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3500;
char a[N + 5][N + 5], mp[N + 5];
int gets(int n, int x, int y, int r) {
	memset(mp, 0, sizeof mp);
	int sum = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			int d = abs(i - x) + abs(j - y);
			if (d <= r) {
				sum ++;
				if (mp[d] && mp[d] != a[i][j])
					return 0;
				mp[d] = a[i][j];
			}
		}
	return sum;
}
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> a[i][j];
	int ans = 0;
	for (int r = 0; r <= (n - 1) / 2; r ++)
		for (int x = r + 1; x <= n - r; x ++)
			for (int y = r + 1; y <= n - r; y ++) 
				ans = max(ans, gets(n, x, y, r));
	cout << ans;
	return 0;
} 
