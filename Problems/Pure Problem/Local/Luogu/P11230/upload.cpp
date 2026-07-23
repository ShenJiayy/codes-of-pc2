#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
deque<int> S[N + 5];
int dp[N + 5][N + 5]; // dp[i][j]：1~i，第i轮结尾由j代言
inline bool solve() {
    int n, lim, T; // n, k, q
    cin >> n >> lim >> T;
    for (int i = 1; i <= n; i ++) {
        int len;
        cin >> len;
        S[i].resize(len + 5, 0);
        for (int j = 1; j <= len; j ++)
            cin >> S[i][j];
    }

    while (T --) {
        int r, c;
        cin >> r >> c;
        
    }
    return 1;
}
signed main() {
	int T;
    cin >> T;
    while (T --)
        cout << solve();
    return 0;
}