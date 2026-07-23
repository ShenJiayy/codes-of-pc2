#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2500;
int rate[N + 5], dis[N + 5], n, m, k;
bool vis[N + 5][N + 5];
vector<int> g[N + 5];
vector<pair<int, int>> f[N + 5];
void bfs(int rt) {
    queue<int> q;
    q.push(rt);
    memset(dis, 0x3f, sizeof dis);

    dis[rt] = 0;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        if (t != rt) {
            vis[rt][t] = 1;
            if (rt != 1 && vis[1][t]) {
                f[rt].push_back({rate[t], t});
                sort(f[rt].begin(), f[rt].end(), greater<pair<int, int>>());
                if (f[rt].size() > 3) 
                    f[rt].pop_back();
            }
        }
        if (dis[t] == k + 1) 
            continue;
        
        for (int nxt : g[t])
            if (dis[nxt] > dis[t] + 1) {
                dis[nxt] = dis[t] + 1;
                q.push(nxt);
            }
    }
}
signed main() {
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i ++)
        cin >> rate[i];
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++)
        bfs(i);
    int ans = 0;
    for (int b = 2; b <= n; b ++)
        for (int c = 2; c <= n; c ++)
            for (auto [_, a] : f[b])
                for (auto[__, d] : f[c])
                    if (a != b && a != c && a != d && b != c && b != d && c != d && vis[b][c])
                        ans = max(ans, rate[a] + rate[b] + rate[c] + rate[d]);
    cout << ans;
    return 0;
}
