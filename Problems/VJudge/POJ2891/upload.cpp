#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e7;
int a[N + 5], r[N + 5];
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
int excrt(int n, int a[], int b[]) { // x mod a[i] = b[i] 
    int x = a[1], y = b[1];
    for (int i = 2; i <= n; i ++) {
        int x1, x2;
        int gcd = exgcd(x, a[i], x1, x2);
        if ((b[i] - y) % gcd)
            return -1;
        x1 = x1 * (b[i] - y) / gcd;
        x1 %= (a[i] / gcd);
        x1 = (x1 + a[i] / gcd) % (a[i] / gcd);
        y = x * x1 + y;
        x = x * a[i] / gcd;
    }
    return (y % x + x) % x;
}
int solve(int n) {
    /*
题目：
exCRT模板
    */
    return excrt(n, a, r);
}
signed main() {
	int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i ++)
            cin >> a[i] >> r[i];
        cout << solve(n) << endl;
    }
    return 0;
}
