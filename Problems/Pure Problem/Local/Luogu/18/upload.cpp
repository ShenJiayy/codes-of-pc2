#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4;
int l[N + 5], r[N + 5], dp[N + 5][2];
inline int f(int a, int b, int c) {
    return abs(a - b) + abs(b - c);
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> l[i] >> r[i];
    l[0] = r[0] = 1, l[n + 1] = r[n + 1] = n;
    n ++;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i ++)  {
        dp[i][0] = min(
            dp[i - 1][0] + f(l[i - 1], r[i], l[i]),
            dp[i - 1][1] + f(r[i - 1], r[i], l[i])
        ) + 1;
        dp[i][1] = min(
            dp[i - 1][0] + f(l[i - 1], l[i], r[i]),
            dp[i - 1][1] + f(r[i - 1], l[i], r[i])
        ) + 1;
    }
    cout << dp[n][1] - 2;
    return 0;
}