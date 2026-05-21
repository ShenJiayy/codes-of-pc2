#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 200, M = 1000;
int c[N + 5][N + 5], p[M + 5], dp[M + 5][N + 5][N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> c[i][j];
    for (int i = 1; i <= m; i ++)
        cin >> p[i];
    p[0] = 3;
    memset(dp, 0x3f, sizeof dp);
    dp[0][1][2] = 0;
    for (int i = 0; i < m; i ++)
        for (int x = 1; x <= n; x ++)
            for (int y = 1; y <= n; y ++) {
                int z = p[i], u = p[i + 1];
                if (x == y || x == z || y == z) continue;
                dp[i + 1][x][y] = min(dp[i + 1][x][y], dp[i][x][y] + c[z][u]);
                dp[i + 1][z][y] = min(dp[i + 1][z][y], dp[i][x][y] + c[x][u]);
                dp[i + 1][x][z] = min(dp[i + 1][x][z], dp[i][x][y] + c[y][u]);
            }
    int ans = 0x3f3f3f3f;
    for (int x = 1; x <= n; x ++)
        for (int y = 1; y <= n; y ++) {
            int z = p[m];
            if (x == y || x == z || y == z) continue;
            ans = min(ans, dp[m][x][y]);
        }
    cout << ans;
    return 0;
}
