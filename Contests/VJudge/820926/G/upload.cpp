#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
double p[N + 5][N + 5];
void init(int n) {
    p[1][1] = 1;
    for (int i = 2; i <= n + 3; i ++)
        for (int j = 1; j <= i + 1; j ++) {
            p[i][j] = p[i - 1][j] + p[i - 1][j - 1], p[i][j] /= 2;
        }
}
double getp(int a, int b) {
    return p[a + 1][b + 1];
}
signed main() {
	int n, d, x, y;
    cin >> n >> d >> x >> y;
    if (x % d || y % d) return puts("0"), 0;
    x /= d, y /= d;
    double P = 0;
    init(n);
    for (int m = 0; m <= n; m ++) {
        if ((m - x & 1) || (n - m - y & 1)) continue;
        int l = (m - x) / 2, u = (n - m - y) / 2;
        if (l < 0 || u < 0) continue;
        P += getp(n, m) * getp(m, l) * getp(n - m, u);
    }
    printf("%.10lf", P);
    return 0;
}
