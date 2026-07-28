#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 2e5;
vector<int> S[N + 5];
int dp[105][N + 5]; // dp[i][j]：1~i，第i轮结尾j
inline void solve() {
    memset(dp, -1, sizeof dp);
    int n, lim, T; // n, k, q
    cin >> n >> lim >> T;
    for (int i = 1; i <= n; i ++) {
        int len;
        cin >> len;
        S[i].clear();
        for (int j = 0; j < len; j ++) {
            int x;
            cin >> x;
            S[i].emplace_back(x);
        }
    }
    dp[0][1] = 0;
    for (int i = 1; i <= 100; i ++) 
        for (int j = 1; j <= n; j ++) {
            int cnt = 0;
            for (int k : S[j]) {
                if (cnt > 0) {
                    if (dp[i][k] == -1)
                        dp[i][k] = j;
                    else if (dp[i][k] != j)
                        dp[i][k] = 0;
                    cnt --;
                }
                if (dp[i - 1][k] != -1 && dp[i - 1][k] != j)
                    cnt = lim - 1; 
            }
        }
    while (T --) {
        int r, c;
        cin >> r >> c;
        cout << (dp[r][c] != -1) << endl;
    }
}
signed main() {
	int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}