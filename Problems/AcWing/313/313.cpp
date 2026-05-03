#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100;
int a[N + 5][N + 5], dp[N + 5][N + 5];

void print(int n, int m) {
    if (n == 0 || m == 0) return ;
    while (dp[n][m] == dp[n][m - 1]) m --;
    print(n - 1, m - 1);
    cout << m << " ";
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    /*
解二：
f[i][j]表示前i朵花,放在 前j个花瓶的最大值
状态转移方程：
i==j 时
每个花瓶只能放一个花
f[i][j]=f[i-1][j-1]+w[i][j]
i!=j时
要么第i朵花放在第j个花瓶里，要么放在前i-1个花瓶里
f[i][j]=max(f[i][j-1],f[i-1][j-1]+w[i][j])
    */
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= m; j ++)
            if (i == j)
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + a[i][j]);
    cout << dp[n][m] << endl;
    print(n, m);
    return 0;
}