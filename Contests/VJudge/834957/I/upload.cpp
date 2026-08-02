#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
char s[N + 5];
typedef bitset<26> bs;
bs t[(N << 2) + 5];
void build(int id, int l, int r) {
    t[id] = 0;
    if (l == r) {
        t[id][s[l] - 'a'] = 1;
        return ;
    }
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    build(lft, l, mid), build(rgt, mid + 1, r);
    t[id] = t[lft] | t[rgt];
}
void update(int id, int l, int r, int p) {
    if (l == r) {
        t[id] = 0;
        t[id][s[p] - 'a'] = 1;
        return ;
    }
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    if (p <= mid)
        update(lft, l, mid, p);
    else
        update(rgt, mid + 1, r, p);
    t[id] = t[lft] | t[rgt];
}
bs query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return t[id];
    bs ans = 0;
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    if (ql <= mid)
        ans |= query(lft, l, mid, ql, qr);
    if (mid + 1 <= qr)
        ans |= query(rgt, mid + 1, r, ql, qr);
    return ans;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    build(1, 1, n);
    int T;
    cin >> T;
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int p;
            cin >> p;
            cin >> s[p];
            update(1, 1, n, p);
        }
        if (opt == 2) {
            int l, r;
            cin >> l >> r;
            bs res = query(1, 1, n, l, r);
            cout << res.count() << endl;
        }
    }
    return 0;
}
