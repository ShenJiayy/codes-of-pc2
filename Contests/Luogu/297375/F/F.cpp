#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 50;
char c[N + 5];
int dp[N + 5][N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("2/in.in", "r", stdin);
    #endif
    string _;
    cin >> _;
    int n = _.size();
    for (int i = 1; i <= n; i ++)
        c[i] = _[i - 1], dp[i][i] = 1;
    for (int sz = 2; sz <= n; sz ++)
        for (int l = 1, r = sz + l - 1; r <= n; l ++, r ++) {
            if (c[l] == c[r])
                dp[l][r] = dp[l][r - 1];
            else {
                dp[l][r] = sz;
                for (int k = l; k < r; k ++)
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    cout << dp[1][n];
    return 0;
}