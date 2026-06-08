#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200, ofs = 203;
double p[N + 5], dp[N + 5][N + 5][N + ofs + 5];
int a[N + 5];
signed main() {
	int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        cin >> p[i], p[i] /= 100;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dp[0][0][min(n, k) + ofs] = 1;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= i; j ++)
            for (int c = -n + ofs; c <= n + ofs; c ++) {
                if (a[i + 1] == -1) dp[i + 1][j + 1][c - 1] += dp[i][j][c] * p[i + 1];
                else dp[i + 1][j + 1][min(n + ofs, c + a[i + 1])] += dp[i][j][c] * p[i + 1];
                dp[i + 1][j][c] += dp[i][j][c] * (1 - p[i + 1]);
            }
    double ans = 0;
    for (int j = m; j <= n; j ++)
        for (int c = 0 + ofs; c <= n + ofs; c ++)
            ans += dp[n][j][c];
    printf("%.10lf", ans);
    return 0;
}
