#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 350, M = 40;
int a[N + 5], b[5], dp[M + 5][M + 5][M + 5][M + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("C:\\Users\\DELL\\Downloads\\P1541_2.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dp[0][0][0][0] = a[1];
    for (int i = 1; i <= m; i ++) {
        int x;
        cin >> x;
        b[x] ++;
    }
    for (int a1 = 0; a1 <= b[1]; a1 ++)
        for (int a2 = 0; a2 <= b[2]; a2 ++)
            for (int a3 = 0; a3 <= b[3]; a3 ++)
                for (int a4 = 0; a4 <= b[4]; a4 ++) {
                    int dis = 1 + a1 * 1 + a2 * 2 + a3 * 3 + a4 * 4;
                    if (a1)
                        dp[a1][a2][a3][a4] = max(dp[a1][a2][a3][a4], dp[a1 - 1][a2][a3][a4] + a[dis]);
                    if (a2)
                        dp[a1][a2][a3][a4] = max(dp[a1][a2][a3][a4], dp[a1][a2 - 1][a3][a4] + a[dis]);
                    if (a3)
                        dp[a1][a2][a3][a4] = max(dp[a1][a2][a3][a4], dp[a1][a2][a3 - 1][a4] + a[dis]);
                    if (a4)
                        dp[a1][a2][a3][a4] = max(dp[a1][a2][a3][a4], dp[a1][a2][a3][a4 - 1] + a[dis]);
                }
    cout << dp[b[1]][b[2]][b[3]][b[4]];
    return 0;
}