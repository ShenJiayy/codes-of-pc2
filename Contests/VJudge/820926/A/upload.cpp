#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6000;
double dp[N + 5][N + 5];
signed main() {
	// dp[i][j]: 1~i, val=j
    int n, a, b;
    cin >> n >> a >> b;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= b; j ++)
            for (int k = j - 6; k < j; k ++)
                dp[i][j] += dp[i - 1][k] / 6;
    double p = 0;
    for (int i = a; i <= b; i ++)
        p += dp[n][i];
    p *= 1000000; p = round(p); p /= 1000000;
    printf("%.6lf", p);
    return 0;
}
