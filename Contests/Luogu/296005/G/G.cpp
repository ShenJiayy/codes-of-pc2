#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DEBUG 1

const int N = 160000, M = 1000;
struct TS {
    int h, m;
};
int operator - (TS x, TS y) {
    return (x.h * 60 + x.m) - (y.h * 60 + y.m);
}
int n, m, v[N + 5], w[N + 5], s[N + 5], on, dp[M + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    TS t1, t2;
    scanf("%lld:%lld %lld:%lld %lld", &t1.h, &t1.m, &t2.h, &t2.m, &on);
    m = t2 - t1;
    for (int i = 1; i <= on; i ++) {
        int ss, ww, vv;
        cin >> ww >> vv >> ss;
        if (ss == 0)
            ss = 1000 / ww;
        int t = 1;
        while (t <= ss) {
            n ++;
            v[n] = vv * t;
            w[n] = ww * t;
            ss -= t;
            t *= 2;
        }
        if (ss) {
            n ++;
            v[n] = vv * ss;
            w[n] = ww * ss;
        }
    }
    #ifdef DEBUG
        freopen("csv.csv", "w", stdout);
        cout << "id,";
        for (int i = 1; i <= n; i ++)
            cout << i << ",";
        cout << endl;
        cout << "v,";
        for (int i = 1; i <= n; i ++)
            cout << v[i] << ",";
        cout << endl;
        cout << "w,";
        for (int i = 1; i <= n; i ++)
            cout << w[i] << ",";
        cout << endl;
        fclose(stdout);
    #endif
    // for (int i = 1; i <= n; i ++)
    //     for (int j = 0; j <= m; j ++) {
    //         dp[i][j] = dp[i - 1][j];
    //         if (j >= w[i])
    //             dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
    //     }
    for (int i = 1; i <= n; i ++)
        for (int j = m; j >= w[i]; j --) 
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]); 
    #ifdef DEBUG
        freopen("out.out", "w", stdout);
    #endif
    cout << dp[m];
    return 0;
}