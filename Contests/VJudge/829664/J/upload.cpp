#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50;
int dp[N + 5][N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    // 请出可爱的斯大林数
    
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            dp[i][j] = dp[i - 1][j - 1] + j * dp[i - 1][j];
    
    return 0;
}
