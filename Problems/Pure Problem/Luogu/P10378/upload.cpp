#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> g[N + 5];
bool vis[N + 5];
void dfs(int id, int &A, int &B, bool col) {
    if (vis[id]) return ;
    vis[id] = 1;
    if (col) A ++;
    else B ++;
    for (int nxt : g[id])
        dfs(nxt, A, B, !col);
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int minn = 0, maxn = 0;
    for (int i = 1; i <= n; i ++)
        if (!vis[i]) {
            int A = 0, B = 0;
            dfs(i, A, B, 0);
            minn += min(A, B), maxn += max(A, B);
        }
    cout << minn << " " << maxn;
    return 0;
}