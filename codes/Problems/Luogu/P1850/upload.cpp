#include <bits/stdc++.h>
using namespace std;
#define int long long
#define break
const int N = 6000, T = 6000;
int f[N + 5][N + 5], cls[T + 5], cl2[T + 5];
double ps[N + 5], dp[T + 5][T + 5][2];
signed main() {
	int t, m, n, e;
    cin >> t >> m >> n >> e;
    for (int i = 1; i <= t; i ++)
        cin >> cls[i];
    for (int i = 1; i <= t; i ++)
        cin >> cl2[i];
    for (int i = 1; i <= t; i ++)
        cin >> ps[i];
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i ++)
        f[i][i] = 0;
    for (int i = 1; i <= e; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        f[x][y] = f[y][x] = min(f[x][y], z);
    }
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if (f[i][k] + f[k][j] < f[i][j])
                    f[i][j] = f[j][i] = f[i][k] + f[k][j];
    /*
    我们定义dp[i][j][0/1]来表示当前为第i个阶段，连同这一次已经用了j次换教室的机会，当前这次换(1)不换(0)的最小期望路程总和。
    
    */
    for (int i = 1; i <= t; i ++)
        for (int j = 0; j <= m; j ++)
            dp[i][j][0] = dp[i][j][1] = 9e18;
    dp[1][0][0] = dp[1][1][1] = 0;
    
    for (int i = 2; i <= t; i ++) {
        double noc = f[cls[i - 1]][cls[i]];
        for (int j = 0; j <= min(m, i); j ++) {
            /*
            dp[i][j][0] = min(
                    dp[i-1][j][0] +
                    add1
                ,
                    dp[i-1][j][1] +
                    f[d[i-1]][c[i]] * p[i-1] +
                    add1 * (1-p[i-1])
            );
            */
            dp[i][j][0] = min(
                    dp[i - 1][j][0] + 
                    noc
                ,
                    dp[i - 1][j][1] +
                    f[cl2[i - 1]][cls[i]] * ps[i - 1] +
                    noc * (1 - ps[i - 1])
            );
            /*
            if(j!=0) {
                dp[i][j][1] = min(
                        dp[i-1][j-1][0] + 
                        f[c[i-1]][d[i]] * p[i] + 
                        add1*(1-p[i])
                    ,
                        dp[i-1][j-1][1] +
                        add1*(1-p[i-1]) * (1-p[i]) + 
                        f[c[i-1]][d[i]] * (1-p[i-1]) * p[i] +
                        f[d[i-1]][c[i]] * (1-p[i]) * p[i-1] +
                        f[d[i-1]][d[i]] * p[i-1] * p[i]
                );
            }
            */
            if (j) 
                dp[i][j][1] = min(
                        dp[i - 1][j - 1][0] +
                        f[cls[i - 1]][cl2[i]] * ps[i] +
                        noc * (1 - ps[i])
                    ,
                        dp[i - 1][j - 1][1] +
                        f[cls[i - 1]][cls[i]] * (1 - ps[i - 1]) * (1 - ps[i]) +
                        f[cls[i - 1]][cl2[i]] * (1 - ps[i - 1]) * ps[i] +
                        f[cl2[i - 1]][cls[i]] * (1 - ps[i]) * ps[i - 1] +
                        f[cl2[i - 1]][cl2[i]] * ps[i - 1] * ps[i]
                );
            
        }
    }
    double ans = 9e18;
    for (int i = 0; i <= m; i ++)
        ans = min(ans, min(dp[t][i][0], dp[t][i][1]));
    printf("%.2lf", ans);
    return 0;
}
