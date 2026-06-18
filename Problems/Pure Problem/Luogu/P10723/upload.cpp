#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define debug
const int N = 1e5;
int ans;
bool col[N + 5], vis[N + 5];
vector<int> g[N + 5];
void solve(int id, int ft) {
    if (col[id])
        vis[id] = 1;
    for (int nxt : g[id]) 
        if (nxt != ft) {
            solve(nxt, id);
            vis[id] |= vis[nxt];
        }
    if (col[id] == 0 && vis[id] == 1)
        ans ++;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> col[i];
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int idx = -1;
    for (int i = 1; i <= n; i ++)
        if (col[i])
            idx = i;
    solve(idx, 0);
    cout << ans;
    return 0;
}