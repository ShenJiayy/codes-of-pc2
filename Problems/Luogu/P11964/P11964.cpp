#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 500, K = 20;
vector<int> v[N + 5];
bool vis[N + 5][K + 5];
// vis[i][j]: 第i个点是否在第j步访问过 

void solve(int id, int stp, int k) {
	if (vis[id][stp] || stp > k)
		return ;
	vis[id][stp] = 1;
	for (int next : v[id])
		solve(next, stp + 1, k);
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
    	int a, b;
    	cin >> a >> b;
    	v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		solve(i, 0, k);
		for (int j = 1; j <= k; j ++) {
			int cnt = 0;
			for (int id = 1; id <= n; id ++)
				cnt += vis[id][j];
			cout << cnt << " ";
		}
		cout << endl;
	}
    return 0;
}
