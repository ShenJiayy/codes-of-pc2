#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, pair<int, int>> exgcd(int a, int b) {
    if (b == 0) return {a, {1, 0}};
    auto res = exgcd(b, a % b);
    int gcd = res.first;
    __int128 x = res.second.first, y = res.second.second;
    return {gcd, {y, x - a / b * y}};
}
const int N = 1e5;
int a[N + 5], b[N + 5], p[N + 5], t[N + 5];
int exexcrt(int n, int mx) {
    __int128 ans = 0, lcm = 1, aa, bb, cc;
    for (int i = 1; i <= n; i ++) {
        aa = __int128(b[i]) * lcm % p[i];
        bb = p[i];
        cc = (a[i] - b[i] * ans % p[i] + p[i]) % p[i];
        auto ret = exgcd(aa, bb);
        __int128 gcd = ret.first;
        __int128 x = ret.second.first;
        __int128 y = ret.second.second;
        x = (x % bb + bb) % bb;
        if (cc % gcd) return -1;
        __int128 tmp = cc / gcd * x % (bb / gcd) * lcm;
        lcm *= bb / gcd;
        tmp %= lcm;
        ans += tmp;
        ans %= lcm;
    }
    if (ans < mx) ans += ((mx - ans - 1) / lcm + 1) * lcm;
    return ans;
}
signed main() {
	int T;
    cin >> T;
    while (T --) {
        multiset<int> st;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        for (int i = 1; i <= n; i ++)
            cin >> p[i];
        for (int i = 1; i <= n; i ++)
            cin >> t[i];
        for (int i = 1; i <= m; i ++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        int mx = 0;
        for (int i = 1; i <= n; i ++) {
            auto top = st.upper_bound(a[i]);
            if (top != st.begin()) top --;
            b[i] = *top;
            st.erase(top);
            st.insert(t[i]);
            mx = max(mx, (a[i] - 1) / b[i] + 1);
        }
        cout << exexcrt(n, mx) << endl;
    }
    return 0;
}