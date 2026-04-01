#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sorry puts("-1"), exit(0)
const int N = 500, mod = 1e9 + 7;
int f[N + 5][N + 5], g[N + 5][N + 5], n, k, pre[N + 5], ss[N + 5];
char s[N + 5];
bool check(int l, int r) {
    return 
        (s[l] == '(' || s[l] == '?') &
        (s[r] == ')' || s[r] == '?')
    ;
}
int searchLast(int p = 1) {
    int ed = p;
    while ((s[ed] == '*' || s[ed] == '?') && ed <= n)
        ed ++;
    return min(ed, p + k);
}
signed main(signed argc, char** argv) {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    if (check(1, n) == 0) sorry;
    for (int i = 1; i <= n; i ++) pre[i] = searchLast(i);
    for (int l = 1, r = 2; r <= n; l ++, r ++)
        f[l][l] = g[l][l] = 0, f[l][r] = g[l][r] = check(l, r);
    for (int len = 2; len <= n; len ++)
        for (int l = 1, r = l + len - 1; r <= n; l ++, r ++) {
            if (!check(l, r)) continue;
            int lst = f[l + 1][r - 1] + pre[l + 1] > r - 1;
            for (int i = l + 1; i < r - 1; i ++) {
                if (pre[l + 1] > i) // SA
                    lst += f[l + 1][r - 1], lst %= mod; 
                if (pre[l + 1] > r + 1) // AS
                    lst += f[l + 1][i], lst %= mod;
            }
            g[l][r] = lst;
            for (int i = l; i < r; i ++)
                s[i] = s[i - 1] + f[i][r], s[i] %= mod;
            for (int i = l + 1; i < r - 1; i ++) {
                lst += g[l][r] * f[i + 1][r] % mod, lst %= mod;
                int maxj = min(pre[i + 1], r - 1);
                lst += g[l][i] * (ss[maxj] - ss[i + 1]) % mod, lst %= mod;
            }
            f[l][r] = lst;
        }
    if (argc >= 3) {
        freopen(argv[1], "w", stderr);
        cerr << ",";
        for (int i = 1; i <= n; i ++)
            cerr << i << ",";
        cerr << endl;
        for (int i = 1; i <= n; i ++) {
            cerr << i << ",";
            for (int j = 1; j <= n; j ++)
                cerr << f[i][j] << ",";
            cerr << endl;
        }
        fclose(stderr);
        freopen(argv[2], "w", stderr);
        cerr << ",";
        for (int i = 1; i <= n; i ++)
            cerr << i << ",";
        cerr << endl;
        for (int i = 1; i <= n; i ++) {
            cerr << i << ",";
            for (int j = 1; j <= n; j ++)
                cerr << g[i][j] << ",";
            cerr << endl;
        }
        fclose(stderr);
    }
    cout << f[1][n];
    return 0;
}

/*
考虑区间 DP，使用 f[l][r] 表示区间 [l, r] 构成合法序列的方案数，g[l][r] 表示区间 [l, r] 构成合法序列且两端括号配对的方案数。函数 check 则用于检查两端括号能否合法，预处理 p[i] 表示由 i 开始连续 * 的最大范围。
对于拼接规则，需要枚举划分的位置，时间复杂度为 O(n^4)。
需要注意的是划分的位置要使第一部分两端括号配对，例如：
()()() 只能划分为 () + ()()，若划分为 ()() + () 则产生重复
()()***() 只能划分为 () + ()***()，若划分为 ()() + *** + () 则产生重复。
*/