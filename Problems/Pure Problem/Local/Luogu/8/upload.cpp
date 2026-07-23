#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
vector<int> g[N + 5];
int a[N + 5], dist[N + 5];
void bfs() {
    queue<int> q;
    q.push(1);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int nxt : g[t])
            if (dist[nxt] > dist[t] + 1)
                dist[nxt] = dist[t] + 1, q.push(nxt);
    }
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        u ++, v ++;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    bfs();
    int ans = 0;
    for (int i = 2; i <= n; i ++)
        ans = max(ans, (2 * dist[i] - 1) / a[i] * a[i] + 2 * dist[i] + 1);
    cout << ans;
    return 0;
}
