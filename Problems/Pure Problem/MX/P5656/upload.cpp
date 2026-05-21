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
    // Sample: 
	// int a, b;
    // cin >> a >> b;
    // int x;
    // tie(ignore, x, ignore) = exgcd(a, b);
    // x = (x % b + b) % b;
    // cout << x;
    int T;
    scanf("%lld", &T);
    while (T --) {
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        int gcd, x, y;
        tie(gcd, x, y) = exgcd(a, b);
        if (c % gcd) {
            puts("-1");
            continue;
        }
        x = x * c / gcd, y = y * c / gcd;
        int tx = b / gcd, ty = a / gcd;
        int k = ceil((1.0 - x) / tx);
        x += tx * k, y -= ty * k;
        if (y <= 0) {
            int y0 = y + ty * ceil((1.0 - y) / ty);
            printf("%lld %lld\n", x, y0);
        }
        else 
            printf("%lld %lld %lld %lld %lld\n", (y - 1) / ty + 1, x, (y - 1) % ty + 1, x + (y - 1) / ty * tx, y);
    }
    return 0;
}