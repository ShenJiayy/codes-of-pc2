#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 500;
int dis[N + 5][N + 5], fan[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int p, f, c;
    cin >> p >> f >> c;
    for (int i = 1; i <= f; i ++)
    	cin >> fan[i];
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= c; i ++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	dis[u][v] = dis[v][u] = w;
	}
	for (int i = 1; i <= p; i ++)
		dis[i][i] = 0;
	for (int k = 1; k <= p; k ++)
		for (int i = 1; i <= p; i ++)
			for (int j = 1; j <= p; j ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	int ans, minn = 0x7f7f7f7f7f7f7f7f;
	for (int i = 1; i <= p; i ++) {
        int dist = 0;
        for (int j = 1; j <= f; j ++)
            dist += dis[i][fan[j]];
        if (minn > dist)
            minn = dist, ans = i;
    }
    cout << ans;
    return 0;
}