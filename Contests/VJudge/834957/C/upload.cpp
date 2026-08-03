#include <bits/stdc++.h>
using namespace std;
#define int long long
#define no return 
#define solution puts("no solution"), 
#define thanks 0
const int N = 2e4, M = 1e5;
struct Edge {
    int u, v;
    bool w;
} e[M * 2 + 5];
int f[N * 2 + 20];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
vector<int> g[N + 5];
bool vis[N + 5];
void dfs(int id) {
    if (vis[id]) return ;
    vis[id] = 1;
    for (int nxt : g[id])
        dfs(nxt);
}
bool cmp1(Edge x, Edge y) {
    return x.w > y.w;
}
bool cmp2(Edge x, Edge y) {
    return x.w < y.w;
}
signed main() {
	int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    // Kruskarl 1
    sort(e + 1, e + m + 1, cmp1);
    vector<Edge> req;
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        req.push_back(e[i]);
    }
    vector<Edge> nes;
    for (Edge eg : req)
        if (eg.w == 0)
            nes.push_back(eg);
    // Kruskarl 2
    for (int i = 1; i <= n; i ++) f[i] = i;
    vector<Edge> res = nes;
    for (Edge eg : nes)  
        merge(eg.u, eg.v);
    for (int i = 1; i <= m; i ++) {
        if (e[i].w == 1) continue;
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        res.push_back(e[i]);
        if (res.size() == k) break;
    }
    if (res.size() < k)
        no solution thanks;
    for (int i = 1; i <= m; i ++) {
        if (e[i].w == 0) continue;
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        res.push_back(e[i]);
        if (res.size() == n - 1) break;
    }
    if (res.size() != n - 1)
        no solution thanks;
    for (Edge ee : res)
        g[ee.u].push_back(ee.v), g[ee.v].push_back(ee.u);
    dfs(1);
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += vis[i];
    if (sum != n)
        no solution thanks;
    for (Edge eg : res)
        cout << eg.u << " " << eg.v << " " << eg.w << endl;
    return 0;
}