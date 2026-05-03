#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define judge
const int N = 100, M = 50000;
bitset<M + 1> dp[M + 5];
bool vis[N + 5][M + 5];
signed main() {
    #ifdef judge
        freopen("sladoled.in", "r", stdin);
        freopen("sladoled.out", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        dp[i] = 1;
    while (q --) {
        int a, b;
        cin >> a >> b;
        if (!vis[a][b]) {
            vis[a][b] = 1;
            int stp = b;
            while (stp <= M)
                dp[a] |= dp[a] << stp, stp <<= 1;
        }
        cout << dp[a].count() - 1 << endl;
    }
    return 0;
}