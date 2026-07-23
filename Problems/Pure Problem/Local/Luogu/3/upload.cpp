#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
struct Dear {
    int w, p;
} a[N + 5];
bool cmp(Dear x, Dear y) {
    return x.p + x.w < y.p + y.w;
}
int n, s1[N + 5], s2[N + 5];
bool check(int mid) {
    // 1~mid mid+1~n
    int guest = 0, driver = 0;
    for (int i = 1; i <= mid; i ++)
        guest += a[i].w;
    for (int i = mid + 1; i <= n; i ++)
        driver += a[i].p;
    if (guest <= driver) return 1;
    return 0;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].w >> a[i].p;
    sort(a + 1, a + n + 1, cmp);
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}
