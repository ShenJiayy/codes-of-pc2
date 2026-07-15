#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20000, M = 100000;
struct Edge {
    int u, v, w;
} e[M + 5];
inline bool cmp(Edge x, Edge y) {
    return x.w > y.w;
}
int f[N * 2 + 5];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx == fty) return ;
    f[ftx] = fty;
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= 2 * n; i ++)
        f[i] = i;
    for (int i = 1; i <= m; i ++) {
        if (find(e[i].u) == find(e[i].v)) {
            cout << e[i].w;
            return 0;
        }
        merge(e[i].u, e[i].v + n);
        merge(e[i].u + n, e[i].v);
    }
    cout << 0;
    return 0;
}