#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int t[(N << 2) + 5], tag[(N << 2) + 5];
void pushdown(int id) {
    int lft = id << 1, rgt = id << 1 | 1;
    tag[lft] += tag[id];
    t[lft] += tag[id];
    tag[rgt] += tag[id];
    t[rgt] += tag[id];
    tag[id] = 0;
}
void updateOne(int id, int l, int r, int p, int d) {
    if (l == r) {
        t[l] += d;
        return ;
    }
    pushdown(id);
    int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
    if (p <= mid)
        updateOne(lft, l, mid, p, d);
    else
        updateOne(rgt, mid + 1, r, p, d);
    t[id] = max(t[lft], t[rgt]);
}
int queryBlock(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) 
        return t[id];
    pushdown(id);
    int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1, ans = 0;
    if (ql <= mid)
        ans = max(ans, queryBlock(lft, l, mid, ql, qr));
    if (mid + 1 <= qr)
        ans = max(ans, queryBlock(rgt, mid + 1, r, ql, qr));
    return ans;
}
void updateBlock(int id, int l, int r, int ql, int qr, int qd) {
    if (ql <= l && r <= qr) {
        tag[id] += qd; // pushup
        t[id] += qd;
        return ;
    }
    pushdown(id);
    int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
    if (ql <= mid)
        updateBlock(lft, l, mid, ql, qr, qd);
    if (mid + 1 <= qr)
        updateBlock(rgt, mid + 1, r, ql, qr, qd);
    t[id] = max(t[lft], t[rgt]);
}
signed main() {
    int n, m, T;
    cin >> n >> m >> T;
    while (T --) {
        int l, r, d;
        cin >> l >> r >> d;
        r --;
        if (queryBlock(1, 1, n - 1, l, r) + d > m) 
            cout << "N\n";
        else {
            cout << "T\n";
            updateBlock(1, 1, n - 1, l, r, d);
        }
    }
    return 0;
}