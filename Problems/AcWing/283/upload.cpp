#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int a[N + 5], dpmax[N + 5][N + 5], dpmin[N + 5][N + 5];
char opt[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> opt[i] >> a[i];
    for (int i = 1; i <= n; i ++)
        opt[i + n] = opt[i], a[i + n] = a[i];
    memset(dpmax, 0x80, sizeof dpmax);
    memset(dpmin, 0x3f, sizeof dpmin);
    for (int i = 1; i <= 2 * n; i ++)
        dpmax[i][i] = dpmin[i][i] = a[i];
    for (int len = 1; len <= n; len ++)
        for (int l = 1, r = len + 1; r <= 2 * n; l ++, r ++) 
            for (int k = l; k < r; k ++) 
                if (opt[k + 1] == 't') {
                    dpmax[l][r] = max(dpmax[l][r], dpmax[l][k] + dpmax[k + 1][r]);
                    dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] + dpmin[k + 1][r]);
                }
                else {
                    dpmax[l][r] = max(dpmax[l][r], dpmax[l][k] * dpmax[k + 1][r]);
                    dpmax[l][r] = max(dpmax[l][r], dpmin[l][k] * dpmin[k + 1][r]);
                    dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] * dpmin[k + 1][r]);
                    dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] * dpmax[k + 1][r]);
                    dpmin[l][r] = min(dpmin[l][r], dpmax[l][k] * dpmin[k + 1][r]);
                }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, dpmax[i][n + i - 1]);
    cout << ans << endl;
    for (int i = 1; i <= n; i ++)
        if (dpmax[i][n + i - 1] == ans)
            cout << i << " ";
    return 0;
}