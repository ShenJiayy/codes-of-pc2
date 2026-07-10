#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int n, s[N + 5], a[N + 5], b[N + 5], mmp[N + 5], c[N + 5];
int lowbit(int x) {
    return x & -x;
}
int get(int p) {
    int sum = 0;
    for (; p; p -= lowbit(p)) sum = max(sum, s[p]);
    return sum;
}
void update(int p, int x) {
    for (; p <= n; p += lowbit(p)) s[p] = max(s[p], x);
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    // 以a[i]为基准，得到b[i]的值映射，然后树状数组搞那个
    for (int i = 1; i <= n; i ++)
        mmp[a[i]] = i;
    for (int i = 1; i <= n; i ++)
        c[i] = mmp[b[i]];
    // a'是有序的，1~n
    // 现在就求c数组的最长上升子序列
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int q = get(c[i] - 1);
        update(c[i], q + 1);
        ans = max(ans, q + 1);
    }
    cout << ans;
    return 0;
}