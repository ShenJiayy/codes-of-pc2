#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100, P = 5e4;
int v[N + 5], c[N + 5], dp[N + 5][P + 5];
signed main() {
	int T;
    cin >> T;
    while (T --) {
        int n, p, q;
        cin >> n >> p >> q;
        for (int i = 1; i <= n; i ++)
            cin >> v[i] >> c[i];
        for (int i = 1; i <= n; i ++)
            for (int j = 0; j <= P; j ++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= c[i])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + v[i]);
            }
        bool valid = 0;
        for (int i = 0; i <= q; i ++)
            if (dp[n][i] >= p) {
                cout << i << endl;
                valid = 1;
                break;
            }
        if (!valid) puts("-1");
    }
    return 0;
}
