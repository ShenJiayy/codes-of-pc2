#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 11380;
int dp[15][15][15][15];
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int l1, l2, l3, d;
    cin >> l1 >> l2 >> l3 >> d;
    // dp[i][j][k][l]：l1=i, l2=j, l3=k, d=l时，所获得的pwd
    for (int i = 0; i <= d; i ++)
        dp[0][0][0][i] = 1;
    for (int i = 0; i <= l1; i ++) // ()
        for (int j = 0; j <= l2; j ++) // []
            for (int k = 0; k <= l3; k ++) // {}
                for (int l = 1; l <= d; l ++) {
                    if (i)
                        dp[i][j][k][l] += dp[i - 1][j][k][l - 1], dp[i][j][k][l] %= MOD;
                    if (!i && j)
                        dp[i][j][k][l] += dp[i][j - 1][k][l - 1], dp[i][j][k][l] %= MOD;
                    if (!i && !j && k)
                        dp[i][j][k][l] += dp[i][j][k - 1][l - 1], dp[i][j][k][l] %= MOD;
                    for (int a = 1; a <= i; a ++)
                        for (int b = 0; b <= j; b ++)
                            for (int c = 0; c <= j; c ++) {
                                int tmp = dp[i - a][j - b][k - c][l];
                                if (a == i && b == j && c == k)
                                    tmp --;
                                tmp %= MOD;
                                dp[i][j][k][l] += dp[i - 1][j][k][l - 1] * tmp;
                                dp[i][j][k][l] %= MOD;
                            }
                    for (int b = 1; b <= j; b ++)
                        for (int c = 0; c <= j; c ++) {
                            int tmp = dp[0][j - b][k - c][l];
                            if (i == 0 && b == j && c == k)
                                tmp --;
                            tmp %= MOD;
                            dp[i][j][k][l] += dp[0][j][k][l - 1] * tmp;
                            dp[i][j][k][l] %= MOD;
                        }
                    for (int c = 1; c <= j; c ++) {
                        int tmp = dp[0][0][k - c][l];
                        if (i == 0 && 0 == j && c == k)
                            tmp --;
                        tmp %= MOD;
                        dp[i][j][k][l] += dp[0][j][k][l - 1] * tmp;
                        dp[i][j][k][l] %= MOD;
                    }
                }
    if (d == 0)
        cout << dp[l1][l2][l3][d];
    else
        cout << (dp[l1][l2][l3][d] - dp[l1][l2][l3][d - 1] + MOD) % MOD;
    return 0;
}