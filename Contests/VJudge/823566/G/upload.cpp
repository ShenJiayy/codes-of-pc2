#include <bits/stdc++.h>
using namespace std;
#define int long long
const int K = 100, N = 15;
double dp[K + 5][(1 << N) + 5];
int stat[(1 << N) + 5], p[N + 5];
signed main() {
	int k, n;
    cin >> k >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
        while (1) {
            int x;
            cin >> x;
            if (x == 0) break;
            stat[i] |= 1 << x - 1;
        }
    }
    for (int x = k; x >= 1; x --)
        for (int y = 0; y < (1 << n); y ++) {
            for (int z = 1; z <= n; z ++)
                if ((stat[z] & y) == stat[z])
                    dp[x][y] += max(dp[x + 1][y], dp[x + 1][y | (1 << z - 1)] + p[z]);
                else dp[x][y] += dp[x + 1][y];
            dp[x][y] /= n;
        }
    printf("%.6lf", dp[1][0]);
    return 0;
}
