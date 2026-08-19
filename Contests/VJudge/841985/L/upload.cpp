#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200;
struct Node {
    int t1, t2;
} a[N + 5];
bool cmp(Node x, Node y) {
    return x.t2 > y.t2;
}
int s[N + 5], dp[N + 5][N * N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].t1 >> a[i].t2;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i].t1;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= s[i]; j ++) {
            dp[i][j] = min(dp[i][j], max(dp[i - 1][j], s[i] - j + a[i].t2));
            if (j >= a[i].t1)
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j - a[i].t1], j + a[i].t2));
        }
    int ans = 9e18;
    for (int i = 0; i <= s[n]; i ++)
        ans = min(ans, dp[n][i]);
    cout << ans;
    return 0;
}
/*
将第i个人放在2号窗口：
f[i][j] = min(f[i][j], max(f[i-1][j], sum[i]-j+s[i].b));   
这里也是一样的 
(sum[i]-j 就是k)

将第i个人放在1号窗口：
if(j>=s[i].a) f[i][j] = min(f[i][j], max(f[i-1][j-s[i].a], j+s[i].b));

f[i-1][j-s[i].a]是i号人打饭+吃饭的时间不足i-1号人吃饭的时间， 所以没有影响
j+s[i].b就是造成了影响
*/