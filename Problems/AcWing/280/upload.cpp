#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200, M = 20, K = 400;
int p[N + 5], d[N + 5], dp[M + 5][K * 2 + 5], from[N + 5][M + 5][K * 2 + 5];
vector<int> sol;
int sa = 0, sb = 0;
void get(int i, int j, int k) {
    if (j == 0) return ;
    int last = from[i][j][k];
    get(last - 1, j - 1, k - p[last] + d[last]);
    sol.emplace_back(last);
    sa += p[last], sb += d[last];
}
signed main() {
	for (int T = 1; ; T ++) {
        int n, m;
        cin >> n >> m;
        if (n == m && m == 0) return 0;
        for (int i = 1; i <= n; i ++)
            cin >> d[i] >> p[i];
        memset(dp, -0x3f, sizeof dp);
        dp[0][K] = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = m; j > 0; j --)
                for (int k = 0; k <= K * 2; k ++) {
                    from[i][j][k] = from[i - 1][j][k];
                    int c = k - p[i] + d[i];
                    if (c < 0 || c > K * 2) continue;
                    if (dp[j][k] < dp[j - 1][c] + p[i] + d[i])
                        dp[j][k] = dp[j - 1][c] + p[i] + d[i],
                        from[i][j][k] = i;
                }
        int res = 0;
        for (int k = 0; k <= K; k ++)
            if (dp[m][k + 400] >= 0 && dp[m][K + k] >= dp[m][K - k]) {
                res = K + k;
                break;
            }
            else if (dp[m][K - k] >= 0) {
                res = K - k;
                break;
            }
        sol.clear();
        sa = 0, sb = 0;
        get(n, m, res);
        printf("Jury #%lld\n", T);
        printf("Best jury has value %lld for prosecution and value %lld for defence:\n", sb, sa);
        for (int val : sol) printf(" %lld", val);
        printf("\n\n");
    }
    return 0;
}
