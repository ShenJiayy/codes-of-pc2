#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sec second
#define fir first
#define pii pair<int, int>

const int N = 30, M = 5000;
int dp[N + 5][M + 5], s[N + 5], ans[N + 5];
pii a[N + 5];

bool cmp(pii x, pii y) {
    return x > y;
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fir, a[i].sec = i;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i].fir;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            if (j >= i) dp[i][j] = dp[i][j - i];
            for (int k = 1; k <= i && k <= j; k ++)
                dp[i][j] = min(dp[i][j], dp[i - k][j - k] + (i - k) * (s[i] - s[i - k]));
        }
    cout << dp[n][m] << endl;
    int bi = n, bj = m, badd = 0;
    while (bi && bj) {
        if (bj >= bi && dp[bi][bj] == dp[bi][bj - bi])
            bj -= bi, badd ++;
        else {
            for (int k = 1; k <= bi && k <= bj; k ++)
                if (dp[bi - k][bj - k] + (bi - k) * (s[bi] - s[bi - k]) == dp[bi][bj]) {
                    for (int foo = bi; foo > bi - k; foo --)
                        ans[a[foo].sec] = badd + 1;
                    bi -= k, bj -= k;
                    break;
                }
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << " ";
    return 0;
}