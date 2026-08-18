#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
struct Node {
    char opt;
    int val;
} a[N + 5];
int dpmax[N + 5][N + 5], dpmin[N + 5][N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].opt >> a[i].val, a[i + n] = a[i];
    n *= 2;
    memset(dpmax, -0x3f, sizeof dpmax);
    memset(dpmin, 0x3f, sizeof dpmin);
    for (int i = 1; i <= n; i ++)
        dpmax[i][i] = dpmin[i][i] = a[i].val;
    for (int len = 2; len <= n; len ++)
        for (int l = 1, r = len; r <= n; l ++, r ++)
            for (int k = l; k < r; k ++)
                if (a[k + 1].opt == 'x') {
                    dpmax[l][r] = max(dpmax[l][r], dpmax[l][k] * dpmax[k + 1][r]);
                    dpmax[l][r] = max(dpmax[l][r], dpmin[l][k] * dpmin[k + 1][r]);
                    dpmin[l][r] = min(dpmin[l][r], dpmax[l][k] * dpmin[k + 1][r]);
                    dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] * dpmax[k + 1][r]);
                }
                else {
                    dpmax[l][r] = max(dpmax[l][r], dpmax[l][k] + dpmax[k + 1][r]);
                    dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] + dpmin[k + 1][r]);
                }
    int ans = -9e18;
    n /= 2;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, dpmax[i][i + n - 1]);
    cout << ans << endl;
    for (int i = 1; i <= n; i ++)
        if (dpmax[i][i + n - 1] == ans)
            cout << i << " ";
    return 0;
}