#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
vector<int> g[N + 5], g2[N + 5], g3[N + 5];
bool vis[N + 5], able[N + 5];
int dis[N + 5];
void dfs(int id) {
    if (vis[id]) return ;
    vis[id] = 1;
    for (int nxt : g2[id]) 
        dfs(nxt);
}
int bfs(int s, int t) {
    memset(dis, -1, sizeof dis);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int nxt : g3[t])
            if (dis[nxt] == -1)
                dis[nxt] = dis[t] + 1, q.push(nxt);
    }
    return dis[t];
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g2[b].push_back(a);
    }
    int s, t;
    cin >> s >> t;
    dfs(t);
    // for (int i = 1; i <= n; i ++)
    //     cout << vis[i] << " ";
    for (int i = 1; i <= n; i ++) {
        able[i] = 1;
        for (int nxt : g[i])
            able[i] = min(able[i], vis[nxt]);
    }
    // for (int i=1; i<=n; able[++i]=1) 
	// 	for (int j:g[i])
	// 		able[i]=min(able[i], vis[j]);
    for (int i = 1; i <= n; i ++)
        for (int nxt : g[i])
            if (able[i] && able[nxt])
                g3[i].push_back(nxt);
    cout << bfs(s, t);
    return 0;
}
