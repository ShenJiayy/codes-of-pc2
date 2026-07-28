#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int dp[N + 5];
signed main() {
	int n;
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0;
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j * j <= i; j ++)
            if (i % j == 0) 
                dp[i] = min(dp[i], min(dp[j] + i / j, dp[i / j] + j));
    cout << dp[n];
    return 0;
}
