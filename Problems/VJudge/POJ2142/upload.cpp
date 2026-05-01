#include <bits/stdc++.h>
using namespace std;
#define int long long
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
void work(int a, int b, int d, int& x, int& y) {
    int gcd = exgcd(a, b, x, y);
    x *= d / gcd, y *= d / gcd;
    int mul = b / gcd;
    x = (x % mul + mul) % mul;
    y = abs((a * x - d) / b);
}
void solve(int a, int b, int d) {
    int x1, y1, x2, y2;
    work(a, b, d, x1, y1);
    work(b, a, d, y2, x2);
    if (x1 + y1 < x2 + y2) cout << x1 << " " << y1 << endl;
    else cout << x2 << " " << y2 << endl;
}
signed main() {
	while (1) {
        int a, b, d;
        cin >> a >> b >> d;
        if (a == 0 && b == 0 && d == 0) return 0;
        solve(a, b, d);
    }
    return 0;
}
