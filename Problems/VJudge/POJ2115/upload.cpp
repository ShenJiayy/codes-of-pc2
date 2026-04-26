#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
// pair<int, pair<int, int>> exgcd(int a, int b) {
//     if (b == 0) return {a, {1, 0}};
//     auto res = exgcd(b, a % b);
//     int gcd = res.first;
//     int x = res.second.first, y = res.second.second;
//     return {gcd, {y, x - a / b * y}};
// }
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1; 
    int gcd = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return gcd;
}
int solve(int a, int b, int c, int k) {
    // It seems to solve a problem that
    // a + xc + y(2^k) = b
    // xc + y(2^k) = b-a
    // to get the x_min
    // looks like to use a `exgcd`
    int x1, y1;
    int gcd = exgcd(c, 1 << k, x1, y1);
    int cc = b - a;
    if (cc % gcd) return -1;
    x1 *= cc / gcd, y1 *= cc / gcd;
    // module's code is hidden.
    return x1;
}
signed main() {
	while (1) {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        if (a == 0 && b == 0 && c == 0 && k == 0)
            break;
        int ret = solve(a, b, c, k);
        if (ret == -1)
            cout << "FOREVER\n";
        else cout << ret << endl;
    }
    return 0;
}
