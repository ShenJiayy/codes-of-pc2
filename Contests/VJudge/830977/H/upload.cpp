#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4, M = 2e4;
struct Edge {
    int u, v, w, id, lev;
} e1[M + 5], e2p[M + 5], e2[M + 5];
inline bool cmp1(Edge x, Edge y) {
    return x.w < y.w;
}
inline bool cmp2(Edge x, Edge y) {
    return x.id < y.id;
}
int f[N * 2 + 20];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
inline pair<int, vector<Edge>> KrusKarl(int n, int m, Edge e[], int req) {
    int ans = 0, ecnt = 0;
    sort(e + 1, e + m + 1, cmp1);
    vector<Edge> ne;
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        if (ecnt >= req) break;
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        ans = max(ans, e[i].w);
        ecnt ++;
        ne.emplace_back(e[i]);
    }
    return {ans, ne};
}
signed main() {
	int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i < m; i ++) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        e1[i] = {u, v, c1, i};
        e2p[i] = {u, v, c2, i};
    }
    auto e1k = KrusKarl(n, m, e1, k);
    for (Edge pe : e1k.second)
        for (int i = 1; i < m; i ++)
            if (e2p[i].u == pe.u && e2p[i].v == pe.v)
                e2p[i] = {0, 0, 0, 0};
    int curr = 0;
    for (int i = 1; i < m; i ++)
        if (e2p[i].u && e2p[i].v)
            e2[++ curr] = e2p[i];
    auto e2k = KrusKarl(n, curr, e2, n - 1 - k);
    vector<Edge> v;
    cout << max(e1k.first, e2k.first) << endl;
    for (Edge pe : e1k.second)
        v.push_back({pe.u, pe.v, pe.w, pe.id, 1});
    for (Edge pe : e2k.second)
        v.push_back({pe.u, pe.v, pe.w, pe.id, 2});
    sort(v.begin(), v.end(), cmp2);
    for (Edge pe : v)
        cout << pe.id << " " << pe.lev << endl;
    return 0;
}
