#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 60, M = 32000;
int v[N + 5], w[N + 5], dp[M + 5];
vector<int> g[N + 5];
bool vis[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> v[i] >> w[i];
        int p;
        cin >> p;
        if (p == 0)
            vis[i] = 1;
        else 
            g[p].push_back(i);
    }
    for (int i = 1; i <= m; i ++)
        if (vis[i])
            for (int j = n; j >= 0; j --) {
                if (j >= v[i])
                    dp[j] = max(dp[j], dp[j - v[i]] + v[i] * w[i]);
                if (g[i].size() >= 1) {
                    int x = g[i][0];
                    if (j >= v[i] + v[x])
                        dp[j] = max(dp[j], dp[j - v[i] - v[x]] + v[i] * w[i] + v[x] * w[x]);
                }
                if (g[i].size() >= 2) {
                    int x = g[i][0], y = g[i][1];
                    if (j >= v[i] + v[x] + v[y])
                        dp[j] = max(dp[j], dp[j - v[i] - v[x] - v[y]] + v[i] * w[i] + v[x] * w[x] + v[y] * w[y]);
                }
            }
    cout << dp[n];
    return 0;
}
