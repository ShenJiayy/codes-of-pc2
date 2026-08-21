#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int a[N + 5], s[N + 5];
struct frac {
    int p, q;
    void operator = (frac x) {
        p = x.p, q = x.q;
    }
};
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
frac tomini(frac x) {
    int g = gcd(x.p, x.q);
    return {x.p / g, x.q / g};
}
frac tomaxium(frac x, int q) {
    q /= gcd(x.q, q);
    return {x.p * q, x.q * q};
}
bool operator < (frac x, frac y) {
    return x.p * y.q < y.p * x.q;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    if (n > 1e4) {
        frac ans = {s[n], n};
        ans = tomini(ans);
        cout << ans.p << " " << ans.q;
        return 0;
    }
    frac ans = {9000000000000, 1};
    for (int l = 1; l <= n; l ++)
        for (int r = l; r <= n; r ++) {
            frac now = {s[r] - s[l - 1], r - l + 1};
            if (now.p == 0)
                continue;
            if (now < ans)
                ans = now;
        }
    ans = tomini(ans);
    cout << ans.p << " " << ans.q;
    return 0;
}