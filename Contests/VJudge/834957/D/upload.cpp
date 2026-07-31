#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int f[N + 5];
bool df[N + 5];
struct Edge {
    int u, v, w;
} e[N + 5];
bool cmp(Edge x, Edge y) {
    return x.w > y.w;
}
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
signed main() {
	int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= k; i ++) {
        int x;
        cin >> x;
        df[x] = 1;
    }
    int ans = 0;
    for (int i = 1; i < n; i ++) 
        cin >> e[i].u >> e[i].v >> e[i].w, ans += e[i].w;
    sort(e + 1, e + n, cmp);
    for (int i = 1; i < n; i ++) {
        int fu = find(e[i].u), fv = find(e[i].v);
        if (df[fu] && df[fv]) continue;
        f[fu] = fv;
        ans -= e[i].w;
        if (df[fv]) df[fu] = 1;
        if (df[fu]) df[fv] = 1;
    }
    cout << ans;
    return 0;
}
