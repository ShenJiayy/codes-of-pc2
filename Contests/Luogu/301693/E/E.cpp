#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
dp[i][j]：i个数，j个<有多少种排列
插入大于号，有(j+1)个位置。
dp[i][j] = dp[i - 1][j] * (j + 1);
插入小于号，有(i-j)个位置。
dp[i][j] = dp[i - 1][j - 1] * (i - j);
初始化
dp[1][0]：1个数，0个<（啥都不放）=1种（对，就是啥都不放）
*/

const int N = 1000, MOD = 2015;
int dp[N + 5][N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    dp[1][0] = 1;
    for (int i = 2; i <= n; i ++)
        for (int j = 0; j < i; j ++) {
            dp[i][j] = dp[i - 1][j]*(j+1);
            if (j > 0) dp[i][j] += dp[i - 1][j - 1]*(i-j);
            dp[i][j] %= MOD;
        }
    cout << dp[n][k];
    return 0;
}