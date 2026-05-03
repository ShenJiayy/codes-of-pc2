#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int N = 3000, INF = 9e18;
int a[N + 5], n, m;
struct Node {
    int a, b;
    Node() {
        a = b = INF;
    }
} dp[N + 5][N + 5];
// Node中，a是最短天数，b是last最小值

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    int tot = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[++ tot];
        if (a[tot] > 119) tot --;
    }
    if (tot < m) {
        cout << "You can't do it.";
        return 0;
    }
    for (int i = 0; i <= tot; i ++)
        dp[i][0].a = 0;
    for (int i = 1; i <= tot; i ++)
        for (int j = 1; j <= min(i, m); j ++) {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1].b + a[i] > 119) {
                if (dp[i - 1][j - 1].a + 1 < dp[i][j].a)
                    dp[i][j].a = dp[i - 1][j - 1].a + 1, dp[i][j].b = a[i];
                else if (dp[i - 1][j - 1].a + 1 == dp[i][j].a)
                    dp[i][j].b = min(dp[i][j].b, a[i]);
            }
            else {
                if (dp[i - 1][j - 1].a < dp[i][j].a)
                    dp[i][j].a = dp[i - 1][j - 1].a, dp[i][j].b = dp[i - 1][j - 1].b + a[i];
                else if (dp[i - 1][j - 1].a == dp[i][j].a) 
                    dp[i][j].b = min(dp[i][j].b, a[i] + dp[i - 1][j - 1].b);
            }
        }
    cout << dp[tot][m].a;
    return 0;
}