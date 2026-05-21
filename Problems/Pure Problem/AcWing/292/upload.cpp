#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define debug
#ifdef debug
#define debugdp
#define debugvalid
#define debugvalidS
#define debugcnt1
#define debugmmp
#define debugS
#endif
const int N = 100, M = 10, K = 60;
int mmp[N + 5], cnt1[(1 << M) + 5], dp[N + 5][K + 5][K + 5];
bool validS[(1 << M) + 5], valid[N + 5][(1 << M) + 5];
vector<int> S;
void init(int n, int m) {
    for (int i = 0; i < (1 << m); i ++)
        cnt1[i] = cnt1[i >> 1] + (i & 1);
    for (int i = 0; i < (1 << m); i ++) {
        validS[i] = !((i & (i << 1)) || (i & (i << 2)));
        if (validS[i]) S.push_back(i);
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < (1 << m); j ++)
            valid[i][j] = !(mmp[i] & j);
    for (int j = 0; j < (1 << m); j ++) 
        valid[0][j] = 1;
}
int solve(int n, int m) {
    int ans = 0;
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for (int j = 0; j < S.size(); j ++)
        if (valid[1][S[j]]) {
            dp[1][j][0] = cnt1[S[j]];
            ans = max(ans, dp[1][j][0]);
        }
    for (int i = 2; i <= n; i ++)
        for (int j = 0; j < S.size(); j ++) if (valid[i][S[j]])
            for (int k = 0; k < S.size(); k ++) if (valid[i - 1][S[k]] && (S[j] & S[k]) == 0) {
                int res = 0;
                for (int l = 0; l < S.size(); l ++) if (dp[i - 1][k][l] != -1 && (S[l] & S[j]) == 0 && valid[i - 2][S[l]])
                    res = max(res, dp[i - 1][k][l]);
                dp[i][j][k] = max(dp[i][j][k], res + cnt1[S[j]]);
                if (i == n) ans = max(ans, dp[i][j][k]);
            }
    return ans;
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
        for (int j = 0; j < m; j ++) {
            char c;
            cin >> c;
            if (c == 'H') mmp[i] |= (1 << (m - 1 - j));
        }
    init(n, m);
    cout << solve(n, m);
    #ifdef debug
    system("del /f /q /s debug 1>nul 2>nul");
    system("mkdir debug & cd debug & mkdir dp & cd dp");
    ofstream ouf;
    #endif
    #ifdef debugdp
    for (int i = 0; i <= n; i ++) {
        string fn = "debug/dp/";
        fn = fn + to_string(i) + ".csv";
        ouf.open(fn.data());
        ouf << ",";
        for (int j = 0; j < S.size(); j ++)
            ouf << j << ",";
        ouf << endl;
        for (int j = 0; j < S.size(); j ++) {
            ouf << j << ",";
            for (int k = 0; k < S.size(); k ++)
                ouf << dp[i][S[j]][S[k]] << ",";
            ouf << endl;
        }
        ouf.close();
    }
    #endif
    #ifdef debugvalid
    ouf.open("debug/valid.csv");
    ouf << ",";
    for (int j = 0; j < (1 << m); j ++)
        ouf << j << ",";
    ouf << endl;
    for (int j = 1; j <= n; j ++) {
        ouf << j << ",";
        for (int k = 0; k < (1 << m); k ++)
            ouf << valid[j][k] << ",";
        ouf << endl;
    }
    ouf.close();
    #endif
    #ifdef debugvalidS
    ouf.open("debug/validS.csv");
    for (int j = 0; j < (1 << m); j ++)
        ouf << j << ",";
    ouf << endl;
    for (int j = 0; j < (1 << m); j ++) 
        ouf << validS[j] << ",";
    ouf.close();
    #endif
    #ifdef debugcnt1
    ouf.open("debug/cnt1.csv");
    for (int j = 0; j < S.size(); j ++)
        ouf << j << ",";
    ouf << endl;
    for (int j : S) 
        ouf << cnt1[j] << ",";
    ouf.close();
    #endif
    #ifdef debugmmp
    ouf.open("debug/mmp.csv");
    for (int j = 1; j <= n; j ++)
        ouf << j << ",";
    ouf << endl;
    for (int j = 1; j <= n; j ++) 
        ouf << mmp[j] << ",";
    ouf.close();
    #endif
    #ifdef debugS
    ouf.open("debug/S.csv");
    for (int v : S) 
        ouf << v << ",";
    ouf.close();
    #endif
    return 0;
}