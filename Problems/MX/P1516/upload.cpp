#include <bits/stdc++.h>
using namespace std;
#define int long long
tuple<int, int, int> exgcd(int a, int b) {
    if (b == 0) 
        return make_tuple(a, 1, 0);
    int gcd, x1, y1;
    tie(gcd, x1, y1) = exgcd(b, a % b);
    int x = y1, y = x1 - a / b * y1;
    return make_tuple(gcd, x, y);
}
signed main() {
	int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    int gcd, k, b = n - m, a = x - y;
    if (b < 0) b = -b, a = -a;
    tie(gcd, k, ignore) = exgcd(b, l);
    if (a % gcd)
        cout << "Impossible";
    else {
        int res = k * a / gcd;
        int mod = l / gcd;
        res = (res % mod + mod) % mod;
        cout << res;
    }
    return 0;
}