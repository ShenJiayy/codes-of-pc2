#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25e4;
vector<int> a[N + 5], s[N + 5];
const int M = 5e6, dx = 2.5e6;
int mp[M + 5];
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		a[i].resize(m + 5);
	for (int i = 0; i <= n; i ++)
		s[i].resize(m + 5, 0);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
			a[i][j] --;
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	// Change data feilds.
	if (n > m) {
		swap(n, m);
		for (int i = 1; i <= n; i ++)
			a[i].resize(m + 5, 0);
		for (int i = 1; i <= m; i ++)
			for (int j = 1; j <= n; j ++)
				swap(a[j][i], a[i][j]);
		for (int i = n + 1; i <= m; i ++)
			a[i].clear();
	}
	int cnt = 0;
	for (int x = 1; x <= n; x ++)
		for (int xx = x; xx <= n; xx ++) {
			for (int yy = 0; yy <= m; yy ++) {
				cnt += mp[s[xx][yy] - s[x - 1][yy] + dx];
				mp[s[xx][yy] - s[x - 1][yy] + dx] ++;
			}
			for (int yy = 0; yy <= m; yy ++) 
				mp[s[xx][yy] - s[x - 1][yy] + dx] = 0;
		}
	cout << cnt; 
	return 0;
}

