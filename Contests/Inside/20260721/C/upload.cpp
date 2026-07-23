#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int dp[N + 5][N + 5], p[N + 5], b[N + 5];
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    for (int j = 0; j <= m; j ++)
        cin >> b[j];
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= q; j ++) 
            for (int k = 0; k <= j; k ++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + b[p[i] + k]);
    int ans = 0;
    for (int j = 0; j <= q; j ++)
        ans = max(ans, dp[n][j]);
    cout << ans;
    return 0;
}
/*
1 2 3 4
1 1 2 3
dp[i][j] 转移O(k)：
dp[i][j]表示 1~i, 用了j张的最大
dp[i][j] = 
*/