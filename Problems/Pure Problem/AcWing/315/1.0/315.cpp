#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 80;
char a[N + 5], b[N + 5];
int dp[N + 5][N + 5], fi[N + 5][128], fj[N + 5][128];
vector<string> ans;

void getAns(int i, int j, int rst, string curr) {
    if (!rst) {
        ans.push_back(curr);
        return ;
    }
    if (!i || !j) return ;
    for (char k = 'a'; k <= 'z'; k ++) {
        int pli = fi[i][k], plj = fj[j][k];
        if (dp[pli][plj] == rst)
            getAns(pli - 1, plj - 1, rst - 1, k + curr);
    }
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    // 开始玄学
    #define sz size
    string o,oo;int o0o=0;cin>>o>>oo;
    for (char ooo:o)a[++ o0o] = ooo;
    o0o = 0;
    for (char ooo:oo)b[++ o0o] = ooo;
    int n=o.sz(),m=oo.sz();
    // 结束玄学
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            if (a[i] == b[j]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    for (int i = 1; i <= n; i ++)
        for (char j = 'a'; j <= 'z'; j ++)
            if (a[i] == j)
                fi[i][j] = i;
            else
                fi[i][j] = fi[i - 1][j];
    for (int i = 1; i <= m; i ++)
        for (char j = 'a'; j <= 'z'; j ++)
            if (b[i] == j)
                fj[i][j] = i;
            else
                fj[i][j] = fj[i - 1][j];
    getAns(n, m, dp[n][m], "");
    sort(ans.begin(), ans.end());
    for (string th : ans)
        cout << th << endl;
    return 0;
}