#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], ans[N + 5];
vector<int> g[N + 5];
void dfs(int id, int ft) {
    if (ans[id]) return ;
    ans[id] = 1;
    for (int nxt : g[id])
        if (a[nxt] < a[id]) {
            dfs(nxt, id);
            ans[id] += ans[nxt];
        }
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int maxn = 0;
    for (int st = 1; st <= n; st ++) {
        dfs(st, 0);
        maxn = max(maxn, ans[st]);
    }
    cout << maxn;
    return 0;
}
