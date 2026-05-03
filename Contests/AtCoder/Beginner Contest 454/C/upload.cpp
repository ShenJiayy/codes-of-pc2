#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
vector<int> g[N + 5];
bool vis[N + 5];
void dfs(int id) {
    if (vis[id]) return ;
    vis[id] = 1;
    for (int nxt : g[id])
        dfs(nxt);
}
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    dfs(1);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        cnt += vis[i];
    cout << cnt;
    return 0;
}