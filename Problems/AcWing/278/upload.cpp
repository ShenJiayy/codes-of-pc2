#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define debug
const int N = 100, M = 1e4;
int a[N + 5], dp[N + 5][M + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
                dp[i][j] += dp[i - 1][j - a[i]];
        }
    #ifdef debug
    freopen("dp.csv", "w", stderr);
    cerr << ",";
    for (int i = 1; i <= m; i ++)
        cerr << i << ",";
    cerr << endl;
    for (int i = 1; i <= n; i ++) {
        cerr << i << ",";
        for (int j = 1; j <= m; j ++)
            cerr << dp[i][j] << ",";
        cerr << endl;
    }
    fclose(stderr);
    system("start dp.csv");
    #endif
    cout << dp[n][m];
    return 0;
}
