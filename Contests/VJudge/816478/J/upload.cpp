#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, pair<int, int>> exgcd(int a, int b) {
    if (b == 0) return {a, {1, 0}};
    auto res = exgcd(b, a % b);
    int gcd = res.first;
    int x = res.second.first, y = res.second.second;
    return {gcd, {y, x - a / b * y}};
}
signed main() {
	int p, q, n, m, l;
    cin >> p >> q >> n >> m >> l;
    int b = n - m, a = q - p;
    if (b < 0) b = -b, a = -a;
    auto ret = exgcd(b, l);
    int g = ret.first, k = ret.second.first;
    if (a % g) {
        puts("Impossible");
        return 0;
    }
    int res = k * a / g;
    int mod = l / g;
    res = (res % mod + mod) % mod;
    cout << res;
    return 0;
}