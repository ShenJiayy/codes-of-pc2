#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 18, M = 1 << 18;
double p[N + 5][N + 5], dp[M + 5];
inline int c1(int x) {
    int cnt = 0;
    for (; x; x >>= 1) cnt += x & 1;
    return cnt;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> p[i][j];
    int m = 1 << n;
    m --; dp[m] = 1;
    for (int stat = m - 1; stat; stat --) {
        int cs = c1(stat);
        for (int j = 1; j <= n; j ++) 
            if (!((1 << j - 1) & stat))
                for (int k = 1; k <= n; k ++)
                    if ((1 << k - 1) & stat)
                        dp[stat] += dp[stat | (1 << j - 1)] * p[k][j] / ((cs + 1) * cs * 1.0 / 2);
    }
    for (int i = 0; i < n; i ++)
        printf("%.6lf ", dp[1 << i]);
    return 0;
}
