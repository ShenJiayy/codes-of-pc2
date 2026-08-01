#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define debug
const int N = 2e5, mod = 998244353;
int a[N + 5], b[N + 5];
int sa[(N << 2) + 5], ta[(N << 2) + 5];
int sb[(N << 2) + 5], tb[(N << 2) + 5];
int ss[(N << 2) + 5];
inline void pda(int id, int l, int r) {
    if (!ta[id]) return ;
    int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
    ta[lft] += ta[id], ta[lft] %= mod;
    sa[lft] += ta[id] * (mid - l + 1), sa[lft] %= mod;
    ss[lft] += ta[id] * sb[lft], ss[lft] %= mod;
    ta[rgt] += ta[id], ta[rgt] %= mod;
    sa[rgt] += ta[id] * (r - mid), sa[rgt] %= mod;
    ss[rgt] += ta[id] * sb[rgt], ss[rgt] %= mod;
    ta[id] = 0;
}
inline void pdb(int id, int l, int r) {
    if (!tb[id]) return ;
    int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
    tb[lft] += tb[id], tb[lft] %= mod;
    sb[lft] += tb[id] * (mid - l + 1), sb[lft] %= mod;
    ss[lft] += tb[id] * sa[lft], ss[lft] %= mod;
    tb[rgt] += tb[id], tb[rgt] %= mod;
    sb[rgt] += tb[id] * (r - mid), sb[rgt] %= mod;
    ss[rgt] += tb[id] * sa[rgt], ss[rgt] %= mod;
    tb[id] = 0;
}
inline void pushdown(int id, int l, int r) {
    pda(id, l, r);
    pdb(id, l, r);
}
inline void pushup(int id) {
    sa[id] = sa[id * 2] + sa[id * 2 + 1], sa[id] %= mod;
    sb[id] = sb[id * 2] + sb[id * 2 + 1], sb[id] %= mod;
    ss[id] = ss[id * 2] + ss[id * 2 + 1], ss[id] %= mod;
}
void buildAll(int id, int l, int r) {
    if (l == r) {
        sa[id] = a[l], sa[id] %= mod;
        sb[id] = b[l], sb[id] %= mod;
        ss[id] = a[l] * b[l], ss[id] %= mod;
        return ;
    }
    pushdown(id, l, r);
    int mid = l + r >> 1;
    buildAll(id * 2, l, mid);
    buildAll(id * 2 + 1, mid + 1, r);
    pushup(id);
}
int opt3(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) 
        return ss[id];
    pushdown(id, l, r);
    int res = 0, mid = l + r >> 1;
    if (ql <= mid)
        res += opt3(id * 2, l, mid, ql, qr), res %= mod;
    if (mid + 1 <= qr)
        res += opt3(id * 2 + 1, mid + 1, r, ql, qr), res %= mod;
    return res;
}
void opt1(int id, int l, int r, int ql, int qr, int qd) {
    if (ql <= l && r <= qr) {
        sa[id] += qd * (r - l + 1), sa[id] %= mod;
        ta[id] += qd, ta[id] %= mod;
        ss[id] += qd * sb[id], ss[id] %= mod;
        return ;
    }
    pushdown(id, l, r);
    int mid = l + r >> 1;
    if (ql <= mid)
        opt1(id * 2, l, mid, ql, qr, qd);
    if (mid + 1 <= qr)
        opt1(id * 2 + 1, mid + 1, r, ql, qr, qd);
    pushup(id);
}
void opt2(int id, int l, int r, int ql, int qr, int qd) {
    if (ql <= l && r <= qr) {
        sb[id] += qd * (r - l + 1), sb[id] %= mod;
        tb[id] += qd, tb[id] %= mod;
        ss[id] += qd * sa[id], ss[id] %= mod;
        return ;
    }
    pushdown(id, l, r);
    int mid = l + r >> 1;
    if (ql <= mid)
        opt2(id * 2, l, mid, ql, qr, qd);
    if (mid + 1 <= qr)
        opt2(id * 2 + 1, mid + 1, r, ql, qr, qd);
    pushup(id);
}
#ifndef debug
signed main() {
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    buildAll(1, 1, n);
    while (T --) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1) {
            int d;
            cin >> d;
            opt1(1, 1, n, l, r, d);
        }
        if (opt == 2) {
            int d;
            cin >> d;
            opt2(1, 1, n, l, r, d);
        }
        if (opt == 3) 
            cout << opt3(1, 1, n, l, r) << endl;
    }
    return 0;
}
#else
signed main() {
    a[1] = 1, a[2] = 3, a[3] = 5, a[4] = 6, a[5] = 8;
    b[1] = 3, b[2] = 1, b[3] = 2, b[4] = 1, b[5] = 2;
    buildAll(1, 1, 5);
    opt1(1, 1, 5, 2, 5, 3);
    opt1(1, 1, 5, 1, 3, 1);
    opt2(1, 1, 5, 5, 5, 2);
    cout << ss[8] << " " << ss[9] << " " << ss[5] << " " << ss[6] << " " << ss[7];
    return 0;
}
#endif