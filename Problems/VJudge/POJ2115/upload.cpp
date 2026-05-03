#include <iostream>
using namespace std;
#define int unsigned long long
// #define debug
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
    // Diffrent: c=0
    if (c == 0) 
        return (a == b)?0:-1;
    int x1, y1;
    int pw2k = 1ull << k;
    int gcd = exgcd(c, pw2k, x1, y1);
    int cc = b - a;
    if (cc % gcd) return -1;
    int mul = (cc / gcd);
    x1 *= mul, y1 *= mul;
    int lcm = c / gcd * pw2k;
    int x1d = lcm / c, y1u = lcm / pw2k;
    if (x1 > x1d) 
        y1u *= x1 / x1d, x1 %= x1d;
    #ifdef debug
    cerr << "Values: \n";
    cerr << "x1 = " << x1 << endl;
    cerr << "y1 = " << y1 << endl;
    cerr << "pw2k = " << pw2k << endl;
    cerr << "gcd = " << gcd << endl;
    cerr << "cc = " << cc << endl;
    cerr << "mul = " << mul << endl;
    cerr << "lcm = " << lcm << endl;
    cerr << "x1d = " << x1d << endl;
    cerr << "y1u = " << y1u << endl;
    #endif
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
