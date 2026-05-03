#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, MOD = 1e4 + 7;
int a[N + 5], len, n, mul[N + 5], add[N + 5];
int belong[N + 5], lb[N + 5], rb[N + 5];
// mul 乘标记
// add 加标记
// block 查板
// a     原数组
void build() {
    len = sqrt(n);
    for (int i = 1; i <= (n - 1) / len + 1; i ++) {
        lb[i] = (i - 1) * len + 1;
        rb[i] = i * len;
        if (lb[i] < 1) lb[i] = 1;
        if (rb[i] > n) rb[i] = n;
        mul[i] = 1;
        add[i] = 0;
        for (int j = lb[i]; j <= rb[i]; j ++)
            belong[j] = i;
    }
}
inline void update(int x) {
    for (int i = lb[x]; i <= rb[x]; i ++)
        a[i] = (a[i] * mul[x] + add[x]) % MOD;
    mul[x] = 1, add[x] = 0;
}
inline void opt1(int l, int r, int c) {
    if (belong[l] == belong[r]) {
        update(belong[l]);
        for (int i = l; i <= r; i ++)
            a[i] += c, a[i] %= MOD;
        return ;
    }
    update(belong[l]);
    for (int i = l; i <= rb[belong[l]]; i ++)
        a[i] += c, a[i] %= MOD;
    update(belong[r]);
    for (int i = lb[belong[r]]; i <= r; i ++)
        a[i] += c, a[i] %= MOD;
    for (int i = belong[l] + 1; i < belong[r]; i ++)
        add[i] += c, add[i] %= MOD;
}
inline void opt2(int l, int r, int c) {
    if (belong[l] == belong[r]) {
        update(belong[l]);
        for (int i = l; i <= r; i ++)
            a[i] *= c, a[i] %= MOD;
        return ;
    }
    update(belong[l]);
    for (int i = l; i <= rb[belong[l]]; i ++)
        a[i] *= c, a[i] %= MOD;
    update(belong[r]);
    for (int i = lb[belong[r]]; i <= r; i ++)
        a[i] *= c, a[i] %= MOD;
    for (int i = belong[l] + 1; i < belong[r]; i ++)
        mul[i] *= c, mul[i] %= MOD, add[i] *= c, add[i] %= MOD;
}
inline int query(int x) {
    return (a[x] * mul[belong[x]] + add[belong[x]]) % MOD;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    build();
    for (int q = 1; q <= n; q ++) {
        int opt, l, r, c;
        cin >> opt >> l >> r >> c;
        if (opt == 0)
            opt1(l, r, c % MOD);
        else if (opt == 1)
            opt2(l, r, c % MOD);
        else
            cout << (query(r) % MOD + MOD) % MOD << endl;
    }
    return 0;
}