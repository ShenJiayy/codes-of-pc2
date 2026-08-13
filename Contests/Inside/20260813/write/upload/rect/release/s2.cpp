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
	map<int, int> mp;
	for (int yy = 0; yy < m; yy ++) {
		cnt += mp[s[1][yy] - yy];
		mp[s[1][yy] - yy] ++;
	}
	cout << cnt; 
	return 0;
}
