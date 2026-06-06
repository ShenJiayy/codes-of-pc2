#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3000;
double p[N + 5], dp[N + 5][N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dp[i + 1][j] += dp[i][j] * (1 - p[i]),
            dp[i + 1][j + 1] += dp[i][j] * p[i];
    double sum = 0;
    for (int i = n / 2 + 1; i <= n; i ++)
        sum += dp[n][i];
    cout << sum;
    return 0;
}