#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
int a[N + 5], b[N + 5], dp[N + 5][N + 5];
int solve(int n) {
    memcpy(b, a, sizeof a);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i ++) {
        int minn = 2e9;
        for (int j = 1; j <= n; j ++) {
            minn = min(minn, dp[i - 1][j]);
            dp[i][j] = minn + abs(a[i] - b[j]);
        }
    }
    return *min_element(dp[n] + 1, dp[n] + n + 1);
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int ans1 = solve(n);
    reverse(a + 1, a + n + 1);
    int ans2 = solve(n);
    cout << min(ans1, ans2);
    return 0;
}
