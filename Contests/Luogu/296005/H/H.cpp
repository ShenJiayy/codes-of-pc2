#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 40, LS = 1600;
int l[N + 5];
double dp[N + 5][LS / 2 + 5][LS / 2 + 5];

double flm(int a, int b, int s) {
    return sqrt(
        s / 2 *
        (s / 2 - a) *
        (s / 2 - b) *
        (s / 2 - (s - a - b)) * 1.0
    );
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("C:\\Users\\DELL\\Downloads\\P1284_2.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> l[i];
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += l[i];
    
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dp[max(i, j)][l[i]][l[j]] = dp[max(i, j)][l[j]][l[i]] = flm(l[i], l[j], sum);
    for (int i = 2; i <= n; i ++)
        for (int a = 1; a <= sum / 2; a ++)
            for (int b = 1; b <= sum / 2; b ++) {
                /*
dp[i][a][b]表示1~i中三边为(a, b, sum - a - b)时面积最大值
dp[i][a][b] = max(
    dp[i - 1][a][b],
    max(
        dp[i][a - l[i]][b],
        max(
            dp[i][a][b - l[i]],
            dp[i][a][b]
        )
    )
);
                */
                dp[i][a][b] = max(
                    dp[i - 1][a][b],
                    max(
                        dp[i][a - l[i]][b],
                        max(
                            dp[i][a][b - l[i]],
                            dp[i][a][b]
                        )
                    )
                );
            }
    double maxn = -1;
    for (int a = 1; a <= sum / 2; a ++)
        for (int b = 1; b <= sum / 2; b ++)
            maxn = max(maxn, dp[n][a][b]);
    if (maxn == 0)
        cout << -1;
    else
        cout << (int)(maxn * 100);
    return 0;
}