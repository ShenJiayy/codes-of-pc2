#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Edge {
    int u, v, w;
};
bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
vector<Edge> e;
const int N = 2e5;
int f[N + 5];
void init(int id) {
    for (int i = 1; i <= id; i ++)
        f[i] = i;
}
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
int KrusKarl(int n) {
    
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w > 0)
            e.push_back({u, v, w});
    }

    return 0;
}
