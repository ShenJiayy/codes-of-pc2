#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 11;
int dp[N + 5][(1 << N) + 5];
bool valid[(1 << N) + 5];
void init(int n) {
    for (int i = 0; i < (1 << n); i ++) {
        bool cnt = 0, odd = 0;
        for (int j = 0; j < n; j ++)
            if (i >> j & 1)
                odd |= cnt, cnt = 0;
            else
                cnt ^= 1;
        valid[i] = !(odd | cnt); 
    }
}
int solve(int n, int m) {
    init(m);
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < 1 << m; j ++)
            for (int k = 0; k < 1 << m; k ++)
                if ((j & k) == 0 && valid[j | k])
                    dp[i][j] += dp[i - 1][k];
    return dp[n][0];
}
signed main() {
	int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        cout << solve(n, m) << endl;
    }
    return 0;
}
