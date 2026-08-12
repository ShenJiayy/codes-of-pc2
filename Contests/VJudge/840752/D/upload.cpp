#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10;
const char col[4] = {'P', 'C', 'Z', 'N'};
int msk[16], f[16][N + 5];
#define pii pair<int, int>
vector<pii> e[16];
int find(int id, int f[]) {
	if (f[id] != id)
		f[id] = find(f[id], f);
	return f[id];
}
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j < m; j ++) {
			char c;
			cin >> c;
			for (int k = 0; k < 4; k ++)
				if (c == col[k])
					e[1 << k].push_back({(i - 1) * m + j, (i - 1) * m + j + 1});
		}
	for (int i = 1; i < n; i ++)
		for (int j = 1; j <= m; j ++) {
			char c;
			cin >> c;
			for (int k = 0; k < 4; k ++)
				if (c == col[k])
					e[1 << k].push_back({(i - 1) * m + j, i * m + j});
		}
	n *= m;
	for (int i = 1; i <= n; i ++)
		f[0][i] = i;
	for (int st = 1; st < 16; st ++) {
		int lowbit = st & -st, nlowbit = st - lowbit;
		msk[st] = msk[nlowbit] + 1;
		for (int i = 1; i <= n; i ++)
			f[st][i] = f[nlowbit][i];
		for (auto ed : e[lowbit])
			f[st][find(ed.first, f[st])] = find(ed.second, f[st]);
	}
	int T;
	cin >> T;
	while (T --) {
		int x, y, z, u;
		cin >> x >> y >> z >> u;
		int a = (x - 1) * m + y, b = (z - 1) * m + u, ans = 5;
		for (int st = 1; st < 16; st ++)
			if (find(a, f[st]) == find(b, f[st]))
				ans = min(ans, msk[st]);
		cout << ans << endl;
	}
	return 0;
}
