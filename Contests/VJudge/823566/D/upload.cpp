#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
double p[N + 5], x[N + 5], x2[N + 5], ans[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    for (int i = 1; i <= n; i ++) {
        x[i] = (x[i - 1] + 1) * p[i];
        x2[i] = (x2[i - 1] + 2 * x[i - 1] + 1) * p[i];
        ans[i] = ans[i - 1] + (3 * x2[i - 1] + 3 * x[i - 1] + 1) * p[i];
    }
    ans[n] *= 10, ans[n] = round(ans[n]), ans[n] /= 10;
    printf("%.1lf", ans[n]);
    return 0;
}
