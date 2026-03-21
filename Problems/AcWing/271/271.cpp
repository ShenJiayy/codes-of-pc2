#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30;
int dp[N + 5][N + 5][N + 5][N + 5][N + 5];
pair<int, vector<int>> input() {
    int k;
    scanf("%lld", &k);
    if (k == 0) exit(0);
    vector<int> v(k + 1, 0);
    for (int i = 1; i <= k; i ++)
        scanf("%lld", &v[i]);
    return {k, v};
}
int solve(pair<int, vector<int>> inp) {
    int k = inp.first;
    vector<int> sss = inp.second;
    int n = 0;
    for (int v : sss)
        n += v;
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0][0] = 1;
    vector<int> s(6, 0);
    for (int i = 1; i <= 5; i ++)
        if (k >= i)
            s[i] = sss[i];
    for (int a = 0; a <= s[1]; a ++)
        for (int b = 0; b <= s[2]; b ++)
            for (int c = 0; c <= s[3]; c ++)
                for (int d = 0; d <= s[4]; d ++)
                    for (int e = 0; e <= s[5]; e ++) {
                        if (a < s[1])
                            dp[a + 1][b][c][d][e] += dp[a][b][c][d][e];
                        if (b < s[2] && b < a)
                            dp[a][b + 1][c][d][e] += dp[a][b][c][d][e];
                        if (c < s[3] && c < b)
                            dp[a][b][c + 1][d][e] += dp[a][b][c][d][e];
                        if (d < s[4] && d < c)
                            dp[a][b][c][d + 1][e] += dp[a][b][c][d][e];
                        if (e < s[5] && e < d)
                            dp[a][b][c][d][e + 1] += dp[a][b][c][d][e];
                    }
    return dp[s[1]][s[2]][s[3]][s[4]][s[5]]; 
}
void output(int ans) {
    printf("%lld\n", ans);
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    while (1)
        output(solve(input()));
    return 0;
}