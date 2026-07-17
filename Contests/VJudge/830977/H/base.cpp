#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4, M = 1e6;
struct Edge {
    int u, v, w;
} e[M + 5];
inline bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
int f[N * 2 + 20];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
inline pair<int, vector<Edge>> KrusKarl(int n, int m, Edge e[]) {
    int ans = 0;
    sort(e + 1, e + m + 1, cmp);
    vector<Edge> ne;
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        ans += e[i].w;
        ne.emplace_back(e[i]);
    }
    return {ans, ne};
}
signed main() {

    return 0;
}