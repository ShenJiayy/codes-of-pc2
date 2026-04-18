#include <bits/stdc++.h>
using namespace std;
#define int long long
const int lgN = 63, mod = 1e9 + 7;
int t[lgN + 5];
int binl0cnt(int x) {
    int cnt = 0;
    for (; !(x & 1); x >>= 1) cnt ++;
    return cnt;
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int a;
        cin >> a;
        t[binl0cnt(a)] ++;
    }
    int ans = 0, s = 0;
    for (int i = lgN; i >= 1; i --) {
        if (t[i] >= 2)
            ans += (fp(2, t[i] - 1, mod) - 1) * fp(2, s, mod), ans %= mod;
        s += t[i];
    }
    ans += (fp(2, t[0], mod) - 1) * fp(2, s, mod), ans %= mod;
    ans += mod, ans %= mod;
    cout << ans;
    return 0;
}