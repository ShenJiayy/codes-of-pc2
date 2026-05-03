#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5000;
int pm[N + 5], pt[N + 5];
#define Mem128
#ifndef Mem128
int dp[N + 5][N + 5];
#else
int dp[N + 5], last[N + 5];
#endif


signed main() {
    #ifndef ONLINE_JUDGE
        freopen("2.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> pm[i];
    int m;
    cin >> m;
    for (int j = 1; j <= m; j ++)
        cin >> pt[j];
    sort(pm + 1, pm + n + 1);
    sort(pt + 1, pt + m + 1);
    #ifndef Mem128
    dp[1][1] = abs(pm[1] - pt[1]);
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j <= min(i, m); j ++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            dp[i][j] += abs(pm[i] - pt[j]);
        }
    cout << dp[n][m];
    #else
    last[1] = abs(pm[1] - pt[1]);
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= min(i, m); j ++) {
            if (j == 1) {
                // dp[i][j] = dp[i - 1][j];
                dp[j] = last[j];
            }
            else if (j == i) {
                // dp[i][j] = dp[i - 1][j - 1];
                dp[j] = last[j - 1];
            }
            else {
                // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
                dp[j] = min(last[j], last[j - 1]);
            }
            dp[j] += abs(pm[i] - pt[j]);
        }
        memcpy(last, dp, sizeof dp);
    }
    cout << dp[m];
    #endif
    return 0;
}