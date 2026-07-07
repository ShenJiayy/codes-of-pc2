#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
vector<int> g[N + 5];
int dp[N + 5], siz[N + 5], n, dep[N + 5];
void dfs1(int id, int ft) {
    siz[id] = 1;
    dep[id] = dep[ft] + 1;
    for (int nxt : g[id])
        if (nxt != ft) {
            dfs1(nxt, id);
            siz[id] += siz[nxt];
        }
}
void dfs2(int id, int ft) {
    for (int nxt : g[id])
        if (nxt != ft) {
            dp[nxt] = dp[id] + n - 2 * siz[nxt];
            dfs2(nxt, id);
        }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i ++)
        dp[1] += dep[i];
    dfs2(1, 0);
    int maxn = 0, maxid = 0;
    for (int i = 1; i <= n; i ++)
        if (dp[i] > maxn)
            maxid = i, maxn = dp[i];
    cout << maxid;
    return 0;
}
