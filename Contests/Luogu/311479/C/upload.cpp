#include <bits/stdc++.h>
using namespace std;
#define int long long
#define int32 signed
const int N = 1e5, MOD = 1e9 + 7;
int b[N + 5], n, s[N + 5], a[N + 5], a2[N + 5], dp[N + 5];
int lowbit(int x) {
    return x & -x;
}
int query(int x) {
    int sum = 0;
    for (; x; x -= lowbit(x)) sum += s[x], sum %= MOD;
    return sum;
}
void add(int p, int x) {
    x %= MOD;
    for (; p <= n; p += lowbit(p))
        s[p] += x, s[p] %= MOD;
}
int32 main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], a2[i] = a[i];
    sort(a2 + 1, a2 + n + 1);
    int m = unique(a2 + 1, a2 + n + 1) - (a2 + 1);
    for (int i = 1; i <= n; i++)
        b[i] = lower_bound(a2 + 1, a2 + 1 + m, a[i]) - a2;
    for (int i = 1; i <= n; i ++) {
        // dp[i]：以i结尾的上升子序列个数
        dp[b[i]] = 1;
        // for (int j = 1; j < b[i]; j ++)
            // dp[b[i]] += dp[j] % MOD, dp[b[i]] %= MOD;
        add(b[i], -(query(b[i]) - query(b[i] - 1)) + 1); // 修改
        add(b[i], query(b[i] - 1));
    }
    // int sum = 0;
    // for (int i = 1; i <= n; i ++)
        // if (dp[i])
            // sum += dp[i] - 1, sum %= MOD;
    // cout << (sum % MOD + MOD) % MOD;
    cout << query(n) - *max_element(b + 1, b + n + 1);
    return 0;
}