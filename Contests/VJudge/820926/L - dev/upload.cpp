#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
double a[N + 5], b[N + 5], xpre[N + 5], ypost[N + 5], sa[N + 5], sb[N + 5], x[N + 5], y[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i], sb[i] = sb[i - 1] + b[i];
    for (int k = 1; k < n; k ++) {
        // x + y = sa[k] - sb[k] + 1 = p
        // x - y = sqrt(p * p - 4 * sa[k])
        double p = sa[k] - sb[k] + 1;
        double q = sqrt(p * p - 4 * sa[k]);
        xpre[k] = (p + q) / 2;
        ypost[k + 1] = (p - q) / 2;
    }                                                         
    
    return 0;
}
