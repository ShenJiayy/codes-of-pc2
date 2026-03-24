#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define local
// #define debugDp
const int N = 1e3;
int box[128], dp[N + 5][N + 5];
signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif

    string s, t;
    cin >> s >> t;
    string p1, p2;
    for (char c : s)
        if (c != 'A')
            p1 += c;
    for (char c : t)
        if (c != 'A')
            p2 += c;
    if (p1 != p2) {
        cout << 0;
        return 0;
    }
    // 允许的操作：删一个A，加一个A
    
    // Old Code Below:
    // int cnt = 0;
    // memset(dp, 0x3f, sizeof dp);
    // dp[0][0] = 0;
    // int slen = s.size(), tlen = t.size();
    // for (int i = 1; i <= slen; i ++)
    //     dp[i][0] = i;
    // for (int j = 1; j <= tlen; j ++)
    //     dp[0][j] = j;
    // for (int i = 1; i <= slen; i ++) 
    //     for (int j = 1; j <= tlen; j ++) 
    //         if (s[i - 1] != 'A' || s[j - 1] != 'A')
    //             continue;
    //         else if (s[i - 1] == t[j - 1])
    //             dp[i][j] = dp[i - 1][j - 1];
    //         else {
    //             for (int k = 0; k <= i; k ++)
    //                 dp[i][j] = min(dp[i][j], dp[i - k][j] + 1);
    //             for (int k = 0; k <= j; k ++)
    //                 dp[i][j] = min(dp[i][j], dp[i][j - k] + 1);
    //         }
    // #ifdef debugDp
    //     freopen("csv.csv", "w", stderr);
    //     cerr << "dp[i][j],";
    //     for (int i = 0; i <= tlen; i ++)
    //         cerr << i << ",";
    //     cerr << endl;
    //     for (int i = 0; i <= slen; i ++) {
    //         cerr << i << ",";
    //         for (int j = 0; j <= tlen; j ++)
    //             cerr << dp[i][j] << ",";
    //         cerr << endl;
    //     }
    //     fclose(stderr);
    //     system("taskkill /f /im Shell.exe");
    //     system("start Shell \"E:\\Codes\\Contests\\AtCoder\\Beginner Contest 447\\C\"");
    // #endif
    // cout << dp[s.size()][t.size()];
    return 0;
}