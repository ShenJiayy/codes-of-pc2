#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fir first 
#define sec second 
const int N = 1e5, M = 25;
int n, ga[N + 5], gb[N + 5], pmp[N + 5], dp[M + 5][N + 5][2];
int da[M + 5][N + 5][2], db[M + 5][N + 5][2];
struct City {
    int h, id;
    int nxt, prv;
} a[N + 5];
bool cmp(City x, City y) {
    return x.h < y.h;
}
void del(int p) {
    if (a[p].nxt) a[a[p].nxt].prv = a[p].prv;
    if (a[p].prv) a[a[p].prv].nxt = a[p].nxt;
}
int WhatIsBetter(int x, int y, int p) {
    if (!x) return a[y].id;
    if (!y) return a[x].id;
    if (abs(a[x].h - a[p].h) <= abs(a[y].h - a[p].h))
        return a[x].id;
    return a[y].id;
}
pii calc(int s, int x) {
    int la = 0, lb = 0, k = 0;
    for (int i = log2(n); i >= 0; i --) {
        //如果当前城市存在，并且走完这些天还是超不过x
        if (dp[i][s][k] && da[i][s][k] + db[i][s][k] <= x) {
            x -= da[i][s][k] + db[i][s][k];
            la += da[i][s][k] , lb += db[i][s][k];
            if (!i) k ^= 1;
            s = dp[i][s][k];
        }
    }
    return {la, lb};
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("1/in.in", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].h, a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        a[i].prv = i - 1, a[i].nxt = i + 1, pmp[a[i].id] = i;
    a[1].prv = a[n].nxt = 0;
    for (int i = 1; i < n; i ++) {
        int p = pmp[i], nxt = a[p].nxt, prv = a[p].prv;
        if (prv && (abs(a[p].h - a[prv].h) <= abs(a[p].h - a[nxt].h) || !nxt))
            gb[i] = a[prv].id, ga[i] = WhatIsBetter(a[prv].prv, nxt, p);
        else
            gb[i] = a[nxt].id, ga[i] = WhatIsBetter(prv, a[nxt].nxt, p);
        del(p);
    }
    for (int j = 1; j <= n; j ++) {
        if (ga[j]) {
            dp[0][j][0] = ga[j];
            da[0][j][0] = abs(a[pmp[j]].h - a[pmp[ga[j]]].h);
            db[0][j][0] = 0;
        }
        if (gb[j]) {
            dp[0][j][1] = gb[j];
            db[0][j][1] = abs(a[pmp[j]].h - a[pmp[gb[j]]].h);
            da[0][j][1] = 0;
        }
    }
    for (int i = 1; (1 << i) <= n; i ++)
        for (int j = 1; j <= n; j ++)
            for (int k = 0; k < 2; k ++) {
                int l = (i == 1) ? k ^ 1 : k;
                if (dp[i - 1][j][k])
                    dp[i][j][k] = dp[i - 1][dp[i - 1][j][k]][l];
                if (dp[i][j][k]) {
                    da[i][j][k] = da[i - 1][j][k] + \
                        da[i - 1][dp[i - 1][j][k]][l];
                    db[i][j][k] = db[i - 1][j][k] + \
                        db[i - 1][dp[i - 1][j][k]][l];
                }
            }
    int s, x, ansa = 1, ansb = 0, ansp = 0;
    cin >> x;
    for (int i = 1; i <= n; i ++) {
        pii ans = calc(i, x);
        int la = ans.fir, lb = ans.sec;
        if (!lb) la = 1;
        // 由于比例的分数算除法会产生玄学的精度问题，所以我们把它换\
            成乘积的形式，除此以外，比值相等时选择高度较高的一个
        if (la * ansb < lb * ansa || la * ansb == lb * ansa && \
                a[pmp[i]].h > a[pmp[ansp]].h)
            ansa = la, ansb = lb, ansp = i;
    }
    cout << ansp << endl;
    int q;
    cin >> q;
    while (q --) {
        int s, x;
        cin >> s >> x;
        pii ans = calc(s, x);
        cout << ans.fir << " " << ans.sec << endl;
    }
    return 0;
}