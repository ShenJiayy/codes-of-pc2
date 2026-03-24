#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3, M = 1e4, MOD = 1e9 + 7;
int v[N + 5], ans, n, m;
int cnt[N + 5], dp[N + 5][M + 5];

bool check() {
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += cnt[i] * v[i];
    return sum == m;
}
void dfs(int id) {
    if (id > n) {
        ans += check();
        return ;
    }
    for (int i = 0; i <= m / v[id]; i ++) {
        cnt[id] = i;
        dfs(id + 1);
    }
}

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("1/1.in", "r", stdin);
	#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> v[i];
    // dp[0][0] = 1;
    // for (int i = 1; i <= n; i ++)
    //     for (int j = 0; j <= m; j ++) {
    //         dp[i][j] = dp[i - 1][j] % MOD;
    //         dp[i][j] %= MOD;
    //         //  + dp[i][j - v[i]] % MOD, 
    //         for (int k = 1; k <= j / v[i]; k ++)
    //             dp[i][j] += dp[i][j - v[i] * k] % MOD, dp[i][j] %= MOD;
    //     }
    // cout << dp[n][m];
    dfs(1);
    cout << ans;
	return 0;
}