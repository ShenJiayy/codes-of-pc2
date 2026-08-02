#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5];
int t[(N << 2) + 5];
void build(int id, int l, int r) {
    if (l == r) {
        t[id] = a[l];
        return ;
    }
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    build(lft, l, mid), build(rgt, mid + 1, r);
    t[id] = t[lft] ^ t[rgt];
}
void update(int id, int l, int r, int p, int d) {
    if (l == r) {
        t[id] ^= d;
        return ;
    }
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    if (p <= mid)
        update(lft, l, mid, p, d);
    else
        update(rgt, mid + 1, r, p, d);
    t[id] = t[lft] ^ t[rgt];
}
int query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return t[id];
    int ans = 0;
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    if (ql <= mid)
        ans ^= query(lft, l, mid, ql, qr);
    if (mid + 1 <= qr)
        ans ^= query(rgt, mid + 1, r, ql, qr);
    return ans;
}
signed main() {
	int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    build(1, 1, n);
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int p, d;
            cin >> p >> d;
            update(1, 1, n, p, d);
        }
        if (opt == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}