#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, M = 1e7;
int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main() {
    freopen("iksevi.in", "r", stdin);
    freopen("iksevi.out", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        int x, y;
        cin >> x >> y;
        int b = gcd(x + y, abs(x - y)), cnt = 0;
        for (int i = 1; i * i <= b; i ++) {
            if (b % i != 0) continue;
            int p = i, q = b / i;
            if ((x + y) % (2 * p) == p && abs(x - y) % (2 * p) == p)
                cnt ++;
            if ((x + y) % (2 * q) == q && abs(x - y) % (2 * q) == q)
                cnt ++;
            if (p == q && (x + y) % (2 * q) == q && abs(x - y) % (2 * q) == q)
                cnt --;
        }
        cout << cnt << endl;
    }
    return 0;
}
