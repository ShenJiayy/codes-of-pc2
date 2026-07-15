#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5000, M = 2e5;
struct Edge {
    int u, v, w;
} e[M * 2 + 5];
inline bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
int f[N * 2 + 20];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
int KrusKarl(int n, int m) {
    int ans = 0;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        ans += e[i].w;
    }
    return ans;
}

vector<int> g[N + 5];
bool vis[N + 5];
void dfs(int id) {
    if (vis[id]) return ;
    vis[id] = 1;
    for (int nxt : g[id])
        dfs(nxt);
}

signed main() {
	int n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i ++)
        scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
    for (int i = 1; i <= m; i ++)
        g[e[i].u].push_back(e[i].v),
        g[e[i].v].push_back(e[i].u);
    dfs(1);
    for (int i = 1; i <= n; i ++)
        if (!vis[i])
            return puts("orz"), 0;
    cout << KrusKarl(n, m);
    return 0;
}