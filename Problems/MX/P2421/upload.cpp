#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 15;
int c[N + 5], p[N + 5], l[N + 5], n;
tuple<int, int, int> exgcd(int a, int b) {
    if (b == 0) 
        return make_tuple(a, 1, 0);
    int gcd, x1, y1;
    tie(gcd, x1, y1) = exgcd(b, a % b);
    int x = y1, y = x1 - a / b * y1;
    return make_tuple(gcd, x, y);
}
/*
Sample of exgcd:
    int a, b;
    cin >> a >> b;
    int x;
    tie(ignore, x, ignore) = exgcd(a, b);
    x = (x % b + b) % b;
    cout << x;
*/
bool check(int m) {
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++) {
            int u = p[i] - p[j], v = m, w = c[j] - c[i];
            int gcd, x0, y0;
            tie(gcd, x0, y0) = exgcd(u, v);
            if (w % gcd) continue;
            u /= gcd, v /= gcd, w /= gcd;
            v = abs(v);
            x0 = (x0 * w % v + v) % v;
            if (x0 <= l[i] && x0 <= l[j]) return 0;
        }
    return 1;
}
signed main() {
	int m = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld%lld%lld", c+i, p+i, l+i), m = max(m, c[i]);
    for (; m <= 1e6; m ++)
        if (check(m)) {
            printf("%lld", m);
            return 0;
        }
    return 0;
}