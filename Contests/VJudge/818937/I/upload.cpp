#include <bits/stdc++.h>
using namespace std;
#define int long long
int bsgs(int a, int b, int p) {
    a %= p, b %= p;
    if (b == 1) return 0;
    int s = sqrt(p) + 1;
    unordered_map<int, int> mp;
    for (int i = 1, ax = a * b % p; i <= s; i ++, ax = ax * a % p)
        mp[ax % p] = i;
    int t = 1;
    for (int i = 1; i <= s; i ++)
        t *= a, t %= p;
    for (int i = 1, bx = t; i <= s; i ++, bx = bx * t % p)
        if (mp[bx])
            return i * s - mp[bx];
    return -1;
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
int gcd(int a, int b) { return __gcd(a, b); }
int inv(int a, int p) { return fp(a, p - 2, p); }
int solve(int p, int a, int b, int x, int t) {
    if (x == t)
        return 1;
    if (a == 0) 
        return (b == t)?2:-1;
    if (a == 1) {
        t -= x, t %= p, t += p, t %= p;
        if (t % gcd(b, p))
            return -1;
        int tmp = t * inv(b, p) + 1;
        return (tmp % p)?(tmp % p):p;
    }
    int ans = bsgs(
        a, 
        ((t - b * inv(1 - a, p)) % p + p) % p * 
        inv(
            ((x - b * inv(1 - a, p)) % p + p) % p, 
            p
        ), 
        p
    );
    if (ans == -1) return -1;
    return ans + 1;
}
signed main() {
	int T;
    cin >> T;
    while (T --) {
        int p, a, b, x, t;
        cin >> p >> a >> b >> x >> t;
        cout << solve(p, a, b, x, t) << endl;
    }
    return 0;
}