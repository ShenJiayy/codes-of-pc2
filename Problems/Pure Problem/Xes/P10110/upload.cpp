#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
bool vis[N + 5];
vector<int> g[N + 5];
int a[N + 5], dis[N + 5];
void spfa(int x) {
    queue<int> q;
    q.push(x);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    dis[x] = 0, vis[x] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = 0;
        for (int nxt : g[t])
            if (dis[nxt] > dis[t] - a[t] + a[nxt] + 1) {
                dis[nxt] = dis[t] - a[t] + a[nxt] + 1;
                if (!vis[nxt])
                    q.push(nxt), vis[nxt] = 1;
            }
    }
}
signed main() {
	int n, m, x, y;
    cin >> n >> m >> x >> y;
    x ++, y ++;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i];
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        u ++, v ++;
        g[u].push_back(v);
    }
    spfa(x);
    if (dis[y] < 9e12)
        cout << dis[y];
    else puts("No solution");
    return 0;
}