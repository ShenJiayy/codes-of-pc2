#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4;
int p, c, maxm;
int a[N + 5];
namespace func {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int phi(int x) {
        int ret = x;
        for (int i = 2; i * i <= x; i ++)
            if (x % i == 0) {
                ret = ret / i * (i - 1);
                while (x % i == 0)
                    x /= i;
            }
        if (x > 1)
            ret = ret / x * (x - 1);
        return ret;
    }
}
const int lgN = 26, pP = 1e4;
int phi[lgN + 5], gcd[lgN + 5];
int s1[pP + 5][lgN + 5], s2[pP + 5][lgN + 5];
bool b1[pP + 5][lgN + 5], b2[pP + 5][lgN + 5];
int ts[N + 5][lgN + 5][lgN + 5];
bool tb[N + 5][lgN + 5][lgN + 5];
void init(int n) {
    // Array `phi` init.
    // Lne 34-39
    int bp = p;
    phi[0] = bp;
    while (bp > 1) {
        bp = func::phi(bp);
        phi[++ maxm] = bp;
    }

    // Array `gcd` init.
    // Lne 43-44
    for (int i = 0; i <= maxm; i ++)
        gcd[i] = func::gcd(c, phi[i]);
    
    // Array `s2`, `b2` init.
    // Lne 48-57
    for (int j = 0; j <= maxm; j ++) {
        s2[0][j] = 1;
        b2[0][j] = 0; // NL.2
        for (int i = 1; i <= 10000; i ++) {
            s2[i][j] = s2[i - 1][j] * c;
            b2[i][j] |= b2[i - 1][j]; // ER.1
            if (s2[i][j] >= phi[j]) // ER.6
                s2[i][j] %= phi[j],
                b2[i][j] = 1;
        }
    }
    
    // Array `s1`, `b1` init.
    // Lne 61-71
    for (int j = 0; j <= maxm; j ++) {
        s1[0][j] = 1;
        for (int i = 1; i <= 10000; i ++) {
            s1[i][j] = s1[i - 1][j]; // ER.4
            s1[i][j] *= s2[10000][j];
            b1[i][j] |= b1[i - 1][j]; // ER.2
            b1[i][j] |= b2[10000][j]; // NL.1
            if (s1[i][j] >= phi[j]) // ER.7
                s1[i][j] %= phi[j],
                b1[i][j] = 1; // ER.3
        }

    }
    
    // Array `ts`, `tb` init.
    // Lne 76-99
    for (int i = 1; i <= n; i ++) {
        // Note: This is the initalize when j=0.
        for (int k = 0; k <= maxm; k ++) {
            ts[i][0][k] = a[i] % phi[k];
            if (a[i] >= phi[k]) 
                tb[i][0][k] = 1;
            else tb[i][0][k] = 0;
        }
        for (int j = 1; j <= maxm; j ++) // ER.5
            for (int k = 0; k < maxm; k ++) {
                ts[i][j][k] = s1[ts[i][j - 1][k + 1] / 10000][k] * s2[ts[i][j - 1][k + 1] % 10000][k];
                tb[i][j][k] = b1[ts[i][j - 1][k + 1] / 10000][k] | b2[ts[i][j - 1][k + 1] % 10000][k];
                if (ts[i][j][k] >= phi[k])
                    ts[i][j][k] %= phi[k],
                    tb[i][j][k] = 1;
                if (gcd[k] != 1 && tb[i][j - 1][k + 1]) {
                    ts[i][j][k] = ts[i][j][k] * s1[phi[k + 1] / 10000][k] % phi[k] * s2[phi[k + 1] % 10000][k];
                    if (ts[i][j][k] >= phi[k])
                        ts[i][j][k] %= phi[k],
                        tb[i][j][k] = 1;
                    tb[i][j][k] |= b1[phi[k + 1] / 10000][k] | b2[phi[k + 1] % 10000][k];
                }
            }
    }
}
struct SegTree {
    int size;
    vector<int> a, s, tg;
    void build(int id, int l, int r) {
        if (l == r) {
            s[id] = a[l];
            return ;
        }
        int mid = l + r >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
    void init() {
        size = 0;
        a.clear(), s.clear(), tg.clear();
    }
    void init(int n, int _a[]) {
        size = n;
        a.resize(size + 5, 0);
        s.resize(size * 4 + 5, 0);
        tg.resize(size * 4 + 5, 0);
        for (int i = 1; i <= n; i ++)
            a[i] = _a[i];
        build(1, 1, n);
    }
    SegTree() { init(); }
    SegTree(int n, int _a[]) { init(n, _a); }
    void resize(int _size) {
        size = _size;
        a.resize(size + 5, 0);
        s.resize(size * 4 + 5, 0);
        tg.resize(size * 4 + 5, 0);
    }
    void update(int pt) {
        s[pt] = (s[pt * 2] + s[pt * 2 + 1]) % p;
        tg[pt] = min(tg[pt * 2], tg[pt * 2 + 1]);
    }
    void updateBlock(int ql, int qr, int pt, int l, int r) {
        if (tg[pt] >= maxm) return ; // ER.8
        if (l == r) {
            tg[pt] ++;
            s[pt] = ts[l][tg[pt]][0] % p;
            return ;
        }
        int mid = l + r >> 1;
        if (ql <= mid)
            updateBlock(ql, qr, pt * 2, l, mid);
        if (qr > mid)
            updateBlock(ql, qr, pt * 2 + 1, mid + 1, r);
        update(pt);
    }
    int queryBlock(int ql, int qr, int pt, int l, int r) {
        if (ql <= l && qr >= r)
            return s[pt];
        int res = 0, mid = l + r >> 1;
        if (ql <= mid)
            res += queryBlock(ql, qr, pt * 2, l, mid) % p, res %= p; // ER.9
        if (qr > mid)
            res += queryBlock(ql, qr, pt * 2 + 1, mid + 1, r) % p, res %= p; // ER.10
        return res;
    }
};
signed main() {
    int n, T;
    cin >> n >> T >> p >> c;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    init(n);
    SegTree t(n, a);
    while (T --) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 0)
            t.updateBlock(l, r, 1, 1, n);
        else
            cout << t.queryBlock(l, r, 1, 1, n) << endl;
    }
    return 0;
}