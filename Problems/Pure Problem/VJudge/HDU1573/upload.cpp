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
int excrt(int n, int a[], int b[]) { // x mod a[i] = b[i] 
    int x = a[1], y = b[1];
    for (int i = 2; i <= n; i ++) {
        auto res = exgcd(x, a[i]);
        int gcd = res.first;
        if ((b[i] - y) % gcd)
            return -1;
        int x1 = res.second.first, x2 = res.second.second;
        x1 = x1 * (b[i] - y) / gcd;
        x1 %= (a[i] / gcd);
        x1 = (x1 + a[i] / gcd) % (a[i] / gcd);
        y = x * x1 + y;
        x = x * a[i] / gcd;
    }
    return (y % x + x) % x;
}
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int arraylcm(int n, int a[]) {
    int lcm = a[1];
    for (int i = 2; i <= n; i ++) lcm = lcm / gcd(lcm, a[i]) * a[i];
    return lcm;
}
int solve(int n, int m, int a[], int b[]) {
    // Firstly, get a `x_0`
    int x0 = excrt(m, a, b);
    if (x0 == -1) return 0;
    // Then get it smaller.
    int lcm = arraylcm(m, a);
    x0 %= lcm;
    if (x0 == 0) x0 += lcm;
    // Count the number.
    if (x0 > n) return 0;
    // int cnt = n / lcm + (n % lcm > x0);
    int cnt = (n - x0) / lcm + 1;
    return cnt;
}
const int M = 10;
int a[M + 5], b[M + 5];
signed main() {
	int T;
    cin >> T;
    while (T --) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i ++)
            cin >> a[i];
        for (int i = 1; i <= m; i ++)
            cin >> b[i];
        cout << solve(n, m, a, b) << endl;
    }
    return 0;
}