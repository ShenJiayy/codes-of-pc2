#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 9;
const int K = N * N, STATUSMAX = (1 << N) - 1;
int dp[N + 5][K + 5][STATUSMAX + 5];
int cnt[STATUSMAX + 5];
bool lne[STATUSMAX + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    const int StatusMax = (1 << n) - 1; 
    for (int i = 0; i <= StatusMax; i ++) {
        int tmp = i;
        while (tmp) {
            cnt[i] += (tmp & 1);
            tmp >>= 1;
        }
        if ((((i >> 1) | (i << 1)) & i) == 0)
            lne[i] = 1;
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int st1 = 0; st1 <= StatusMax; st1 ++) {
            if (!lne[st1]) continue;
            for (int st2 = 0; st2 <= StatusMax; st2 ++) {
                // 上一级
                if (!lne[st2]) continue;
                if (((st2 | (st2 >> 1) | (st2 << 1)) & st1) == 0)
                    for (int j = 0; j <= k; j ++)
                        if (j - cnt[st1] >= 0)
                            dp[i][j][st1] += dp[i - 1][j - cnt[st1]][st2];
            }
        }
    int ans = 0;
    for (int i = 0; i <= StatusMax; i ++)
        ans += dp[n][k][i];
    cout << ans;
    return 0;
}