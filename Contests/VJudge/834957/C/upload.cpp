#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4, M = 1e5;
struct Edge {
    int u, v;
    bool w;
} e[M * 2 + 5];
bool cmp1(Edge x, Edge y) {
    return x.w < y.w;
}
int f[N * 2 + 20];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
vector<Edge> KrusKarl1(int n, int m) {
    vector<Edge> ans;
    sort(e + 1, e + m + 1, cmp1);
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        ans.push_back(e[i]);
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
	int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
        cin >> e[i].u >> e[i].v >> e[i].w, e[i].w ^= 1;
    auto ret = KrusKarl1(n, m);
    int cnt1 = 0;
    for (Edge eg : ret)
        if (eg.w == 1)
            cnt1 ++;
    if (cnt1 > k)
        return puts("no solution"), 0;
    for (Edge eg : ret)
        g[eg.u].push_back(eg.v),
        g[eg.v].push_back(eg.u);
    dfs(1);
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += vis[i];
    if (sum != n)
        return puts("no solution"), 0;
    for (Edge eg : ret)
        cout << eg.u << " " << eg.v << " " << eg.w << endl;
    return 0;
}