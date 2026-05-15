#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300;
int c[N + 5], f[N + 5], dp[N + 5][N + 5], m;
vector<int> g[N + 5];
void dfs(int id) {
    dp[id][0] = 0;
    for (int nxt : g[id]) {
        dfs(nxt);
        for (int i = m; i >= 0; i --)
            for (int j = 0; j <= i; j ++)
                dp[id][i] = max(dp[id][i], dp[id][i - j] + dp[nxt][j]);
    }
    if (id)
        for (int i = m; i >= 0; i --)
            dp[id][i] = dp[id][i - 1] + c[id];
}
signed main() {
	int n;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
        cin >> f[i] >> c[i];
    for (int i = 1; i <= n; i ++)
        g[f[i]].push_back(i);
    memset(dp, -0x3f, sizeof dp);
    dfs(0);
    int ans = -9e18;
    for (int i = 0; i <= m; i ++)
        ans = max(ans, dp[0][i]);
    cout << ans;
    return 0;
}