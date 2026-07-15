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

signed main() {
	int n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i ++)
        scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	
    return 0;
}