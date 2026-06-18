#include <bits/stdc++.h>
using namespace std;
#define int long long
const int lim = 1e6; // 大概差 2e-6 吧
const double gy = 0.5772156649015328;
// E[x] = 1 + (1/1 +1/2 + ... + 1/(n - 1))
signed main() {
	int n;
    cin >> n;
    if (n == 1) return puts("0.00000"), 0; // e[1] = 0
    double ans;
    if (n <= lim) {
        ans = 1;
        for (int i = 1; i < n; i ++)
            ans += 1.0 / i;
    }
    else 
        ans = 1 + log(n) + gy;
    printf("%.5lf", ans);
    return 0;
}
