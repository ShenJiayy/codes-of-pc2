#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 60;
int a[N + 5][N + 5], dp[N * 2 + 5][N + 5][N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    for (int i = 2; i <= n + m; i ++)
        for (int x1 = max(1ll, i - m); x1 <= n && x1 < i; x1 ++)
            for (int x2 = max(1ll, i - m); x2 <= n && x2 < i; x2 ++) 
                for (int s1 = 0; s1 < 2; s1 ++)
                    for (int s2 = 0; s2 < 2; s2 ++) {
                        int add = a[x1][i - x1];
                        if (x1 != x2 || i == 2 || i == n + m) {
                            add += a[x2][i - x2];
                            dp[i][x1][x2] = max(dp[i][x1][x2], dp[i - 1][x1 - s1][x2 - s2] + add);
                        }
                    }
    
    int ans = dp[n + m][n][n];
    cout << ans;
    return 0;
}