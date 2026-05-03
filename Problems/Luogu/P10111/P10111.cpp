#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1000, INF = 9e18;
int a[N + 5], dp[N + 5][N + 5][3], b[N + 5], c[N + 5];

int score(int i, int x) {
    int y = c[i];
    if (x == y) return a[i];
    if (x == 1 && y == 0 || x == 2 && y == 1 || x == 0 && y == 2)
        return a[i] * 2; 
    return 0;
}
int next(int x) {
    return (x + 1) % 3;
}
int prev(int x) {
    return next(next(x));
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    /*
动规5部曲
1. dp[i][j][k]:
    第i轮，j次换牌，当前为k
2. dp初值：0
3. 转移方程：
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < i; j ++)
            for (int k = 0; k < 3; k ++) {
                int sc = score(i, k), d = -INF;
                if (j < i - 1 || i == 1)
                    d = max(d, dp[i - 1][j][k]);
                if (j)
                    d = max(
                        d, 
                        max(
                            dp[i - 1][j - 1][next(k)],
                            dp[i - 1][j - 1][prev(k)]
                        ) - b[j];
                    );
                dp[i][j][k] = sc + d;
            }
    */
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < i; j ++)
            for (int k = 0; k < 3; k ++) {
                int sc = score(i, k), d = -INF;
                if (j < i - 1 || i == 1)
                    d = max(d, dp[i - 1][j][k]);
                if (j)
                    d = max(
                        d, 
                        max(
                            dp[i - 1][j - 1][next(k)],
                            dp[i - 1][j - 1][prev(k)]
                        ) - b[j]
                    );
                dp[i][j][k] = sc + d;
            }
    int ans = -INF;
    for (int j = 0; j < n; j ++)
        for (int k = 0; k < 3; k ++)
            ans = max(ans, dp[n][j][k]);
    cout << ans;
    return 0;
}