#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100, M = 100, MOD = 1e6 + 7;
int s[N + 5], n, m, ans, dp[N + 5][M + 5];
// n种花，每种花s[i]个，选m盆花

void dfs(int id, int sum) {
    if (sum > m) return ;
    if (id > n) {
        if (sum == m) ans ++;
        return ;
    }
    for (int i = 0; i <= s[id]; i ++)
        dfs(id + 1, sum + i);
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("2/2.in", "r", stdin);
    #endif
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    // dfs(1, 0);
    // dp[i][j] = k表示从1~i，容量恰为j盆花的方案数为k种
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++) 
            for (int k = 0; k <= s[i] && k <= j; k ++)
                dp[i][j] += dp[i - 1][j - k] % MOD, dp[i][j] %= MOD;
    cout << dp[n][m];
    return 0;
}