#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2000;
int a[N + 5], f[N + 5][N + 5], b[N + 5], n;

int solve() {
    memcpy(b, a, sizeof a);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i ++) {
        int minn = 1e9;
        for (int j = 1; j <= n; j ++) {
            // f[i, j] = min{0 <= k <= j}(f[i - 1, k] + |a[i] - j|)
            minn = min(minn, f[i - 1][j]);
            f[i][j] = minn + abs(a[i] - b[j]);
        }
    }
    return *min_element(f[n] + 1, f[n] + n + 1);
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int ans1 = solve();
    reverse(a + 1, a + n + 1);
    int ans2 = solve();
    cout << min(ans1, ans2);
    return 0;
}