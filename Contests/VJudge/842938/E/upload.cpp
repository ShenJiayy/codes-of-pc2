#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int dp[N + 5][N + 5], a[N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int stat = 0; stat < (1 << n); stat ++)
        if (__builtin_popcount(stat) == n - m) {
            memset(dp, 0, sizeof dp);
            for (int i = 1; i <= n; i ++)
                if (stat << i - 1 & 1)
                    for (int j = 1)
        }
    return 0;
}
