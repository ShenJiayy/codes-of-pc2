#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int n, m, a[N + 5], b[N + 5];
inline int calc(int S, int eta) {
    return (S + eta - 1) / eta;
}
bool check(int x) {
    int used = 0;
    for (int i = 1; i <= n; i ++) {
        // 对于学科 i
        if (b[i] > a[i]) {
            used += calc(x, b[i]);
            continue;
        }
        // 我去上课
        if (m * a[i] >= x) {
            used += calc(x, a[i]);
            continue;
        }
        used += m;
        used += calc(x - m * a[i], b[i]);
        if (used > n * m) return 0;
    }
    return used <= n * m;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) 
        cin >> b[i];
    int l = 0, r = 1e18 + 10, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
