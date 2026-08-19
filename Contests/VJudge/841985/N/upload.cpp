#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100000;
char c[N + 5];
bool g[128][128];
int dp[N + 5], fj[128];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    int m;
    cin >> m;
    for (int i = 'a'; i <= 'z'; i ++)
        for (int j = 'a'; j <= 'z'; j ++)
            g[i][j] = 1;
    for (int i = 1; i <= m; i ++) {
        char u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 0;
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i ++) {
        for (int j = 'a'; j <= 'z'; j ++)
            if (g[c[i]][j])
                dp[i] = min(dp[i], fj[j] + i - 1);
        fj[c[i]] = min(fj[c[i]], dp[i] - i);
    } 
    cout << dp[n];
    return 0;
}
