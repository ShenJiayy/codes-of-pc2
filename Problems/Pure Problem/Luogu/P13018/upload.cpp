#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 102, M = 502, K = N * M + 5;
int a[N + 5], b[N + 5], dp[K * 2 + 5];
signed main() {
	// dp[i]表示差i的答案
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i];
    memset(dp, -0x3f, sizeof dp);
    dp[K] = 0;
    for (int i = 1; i <= n; i ++) {
        int p = a[i] + b[i], q = a[i] - b[i];
        if (q <= 0)
            for (int j = -q; j < K * 2; j ++)
                dp[j + q] = max(dp[j + q], dp[j] + p);
        else
            for (int j = K * 2 - 1; j >= q; j --)
                dp[j + q] = max(dp[j + q], dp[j] + p);
    }
    cout << dp[K];
    return 0;
}
