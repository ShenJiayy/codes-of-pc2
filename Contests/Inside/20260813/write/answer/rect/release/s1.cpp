#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25e4;
vector<int> a[N + 5], s[N + 5];
signed main() {
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i ++)
		a[i].resize(m + 5), s[i].resize(m + 5, 0);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	int cnt = 0;
	for (int x = 1; x <= n; x ++)
		for (int y = 1; y <= m; y ++)
			for (int xx = x; xx <= n; xx ++)
				for (int yy = y; yy <= m; yy ++) 
					cnt += (s[xx][yy] - s[x - 1][yy] - s[xx][y - 1] + s[x - 1][y - 1]) == (yy - y + 1) * (xx - x + 1); 
	cout << cnt;
	return 0;
}

