#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DP

const int N = 60, M = 3.2e4;
int n, m, v[N + 5], w[N + 5], ft[N + 5], dp[N + 5][M + 5];

#ifdef DP
int dp[N + 5][M + 5];
#endif
#ifdef DFS
bool use[N + 5];
int ans;
int getans() {
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += use[i] * w[i] * v[i];
    return ans;
}
void dfs(int id, int sum) {
    if (sum > m) return ;
    if (id > n) {
        ans = max(ans, getans());
        return ;
    }
    use[id] = 0;
    dfs(id + 1, sum);
    if (use[ft[id]] || !ft[id]) {
        use[id] = 1;
        dfs(id + 1, sum + w[id]);
    }
}
#endif

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> m >> n;
    for (int i = 1; i <= n; i ++)
        cin >> w[i] >> v[i] >> ft[i];
    #ifdef DFS
    dfs(1, 0);
    cout << ans;
    #endif
    #ifdef DP

    #endif
    return 0;
}