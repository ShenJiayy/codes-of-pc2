#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 16000;
vector<int> g[N + 5];
int a[N + 5], dp[N + 5][2];
void dfs(int id, int ft) {
    dp[id][0] = -9e18, dp[id][1] = a[id];
    for (int nxt : g[id]) if (nxt != ft) {
        dfs(nxt, id);
        if (max(a[nxt], dp[nxt][1]) > 0)
            dp[id][1] += max(a[nxt], dp[nxt][1]);
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
    dfs(1, 0);
    int maxn = -9e18;
    for (int i = 1; i <= n; i ++)
        maxn = max(maxn, max(dp[i][0], dp[i][1]));
    cout << maxn;
    return 0;
}
