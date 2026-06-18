#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
vector<int> g[N + 5];
int dep[N + 5];
void bfs(int id) {
    memset(dep, 0x3f, sizeof dep);
    queue<int> q;
    q.push(id);
    dep[id] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int nxt : g[t])
            if (dep[nxt] > dep[t] + 1)
                dep[nxt] = dep[t] + 1, q.push(nxt);
    }
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int minn = 9e18, minid;
    for (int i = 1; i <= n; i ++) {
        bfs(i);
        int maxn = 0;
        for (int j = 1; j <= n; j ++)
            maxn = max(maxn, dep[j]);
        if (minn > maxn)
            minn = maxn, minid = i;
    }
    cout << minid;
    return 0;
}
