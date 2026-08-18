#include <bits/stdc++.h>
using namespace std;
#define int long long
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
);*/
const int N = 40, M = 1600;
int l[N + 5];
bool dp[M / 2 + 5][M / 2 + 5];
double calc(double a, double b, double s) {
    return sqrt(
        s / 2 * 
        (s / 2 - a) *
        (s / 2 - b) * 
        (s / 2 - s + a + b)
    );
}
bool check(int x, int y, int z) {
    return x + y > z && y + z > x && z + x > y;
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> l[i];
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += l[i];
    dp[0][0] = 1;
    for (int k = 1; k <= n; k ++)
        for (int i = sum / 2; i >= 0; i --)
            for (int j = sum / 2; j >= 0; j --) {
                if (i >= l[k] && dp[i - l[k]][j])
                    dp[i][j] = 1;
                if (j >= l[k] && dp[i][j - l[k]])
                    dp[i][j] = 1;
            }
    double ans = -0.01;
    for (int a = 1; a <= sum / 2; a ++)
        for (int b = 1; b <= sum / 2; b ++) {
            if (!dp[a][b]) continue;
            if (check(a, b, sum - a - b))
                ans = max(ans, calc(a, b, sum));
        }
    cout << (int)(ans * 100);
    return 0;
}