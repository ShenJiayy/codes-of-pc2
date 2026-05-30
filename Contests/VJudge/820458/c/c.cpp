#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
struct Thing {
	int val, idx;
};
vector<Thing> g[N + 5];
int s[N + 5], n, m;
inline int find1(int n, int vl, vector<Thing> &arr) {
	int l = 1, r = n, ans = n + 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (arr[mid].idx >= vl)
			ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
inline int find2(int n, int vl, vector<Thing> &arr) {
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (arr[mid].idx <= vl)
			ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
inline int solve(int d, int l, int r) {
	if (g[d].size() <= 1) return 0;
	int lft = find1(g[d].size() - 1, l, g[d]), rgt = find2(g[d].size() - 1, r, g[d]);
	if (lft > rgt)
		return 0;
	return (g[d][rgt].val - g[d][lft - 1].val) / 2;
} 
signed main() {
	int T;
	cin >> n >> m >> T;
	for (int i = 1; i <= m; i ++)
		g[i].push_back({0, 0});
	for (int i = 1; i <= n; i ++) {
		int v, c;
		cin >> v >> c;
		g[c].push_back({v, i});
		s[i] = s[i - 1] + v;
	}
	for (int i = 1; i <= m; i ++)
		for (int j = 2; j < g[i].size(); j ++)
			g[i][j].val += g[i][j - 1].val;
	while (T --) {
		int d, l, r;
		cin >> d >> l >> r;
		int ans = s[r] - s[l - 1];
		cout << ans - solve(d, l, r) << endl;
	}
	return 0;
} 