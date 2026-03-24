#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 2e5, N = 4e5;
struct Edge {
    int x, y;
    bool dmg;
    Edge () {
        dmg = 0;
    }
} e[M + 5];
int f[N + 5], closen[N + 5], ans[N + 5];
bool damaged[N + 5], vis[N + 5];
void init(int n) {
    for (int i = 0; i < n; i ++)
        f[i] = i;
}
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx != fty)
        f[ftx] = fty;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) 
        cin >> e[i].x >> e[i].y;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i ++)
        cin >> closen[i];
    for (int i = 1; i <= k; i ++)
        damaged[closen[i]] = 1;
    for (int i = 1; i <= m; i ++)
        if (!damaged[e[i].x] && !damaged[e[i].y])
            merge(e[i].x, e[i].y);
    for (int i = 1; i <= n; i ++)
        vis[find(i)] = 1;
    for (int i = 1; i <= n; i ++)
        ans[]
    return 0;
}