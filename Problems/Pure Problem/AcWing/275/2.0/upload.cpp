#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50;
int a[N + 5][N + 5], dp[N * 2 + 5][N + 5][N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    for (int i = 2; i <= n + m; i ++)
        for (int x1 = max(1ll, i - m); x1 <= n && x1 < i; x1 ++)
            for (int x2 = max(1ll, i - m); x2 <= n && x2 < i; x2 ++)
                for (int dx = 0; dx < 2; dx ++)
                    for (int dy = 0; dy < 2; dy ++) {
                        int add = a[x1][i - x1];
                        if (x1 != x2 || i == 2 || i == n + m) {
                            add += a[x2][i - x2];
                            dp[i][x1][x2] = max(dp[i][x1][x2], dp[i - 1][x1 - dx][x2 - dy] + add);
                        }
                    }
    cout << dp[n + m][n][n];
    return 0;
}
