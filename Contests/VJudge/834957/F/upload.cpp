#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e5 + 7, N = 30;
struct Node {
    int mod, val;
    bool validate;
} t[(M << 2) + 5];
string inp[M + 5];
int n;
void merge(int id) {
    int lft = id << 1, rgt = id << 1 | 1;
    t[id].mod = t[lft].mod | t[rgt].mod;
    t[id].val = t[lft].val | t[rgt].val;
    if (!t[lft].validate || !t[rgt].validate || (t[lft].mod & t[rgt].mod) & (t[lft].val ^ t[rgt].val))
        t[id].validate = 0;
    else 
        t[id].validate = 1;
}
void build(int id, int l, int r) {
    if (l == r) {
        for (int i = 0; i < n; i ++)
            t[id].mod |= (inp[l][i] == '?') << i,
            t[id].val |= (inp[l][i] == '1') << i;
        t[id].validate = 1;
        return ;
    }
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    build(lft, l, mid);
    build(rgt, mid + 1, r);
    merge(id);
}
void update(int id, int l, int r, int p) {
    if (l == r) {
        for (int i = 0; i < n; i ++)
            t[id].mod |= (inp[l][i] != '?') << i,
            t[id].val |= (inp[l][i] == '1') << i;
        t[id].validate = 1;
        return ;
    }
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    if (p <= mid)
        update(lft, l, mid, p);
    else
        update(rgt, mid + 1, r, p);
    merge(id);
}
Node operator +(Node x, Node y) {
    Node ans;
    ans.mod = x.mod | y.mod;
    ans.val = x.val | y.val;
    if (!x.validate || !y.validate || (x.mod & y.mod) & (x.val ^ y.val))
        ans.validate = 0;
    else 
        ans.validate = 1;
    return ans;
}
Node query(int id, int l, int r, int ql, int qr) {
    if (l == r) 
        return t[id];
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    if (ql <= mid && mid < qr)
        return query(lft, l, mid, ql, qr) + query(rgt, mid + 1, r, ql, qr);
    if (ql <= mid)
        return query(lft, l, mid, ql, qr);
    if (mid < qr)
        return query(rgt, mid + 1, r, ql, qr);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int m, T;
    cin >> n >> m >> T;
    for (int i = 1; i <= m; i ++) 
        cin >> inp[i];
    build(1, 1, m);
    int ans = 0;
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 0) {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, m, l, r);
            if (!res.validate) {
				ans ^= 0;
				continue;
			}
			int k = 1;
			for (int i = 1; i <= n; i ++) {
				if (!(res.mod & 1))
                    k <<= 1;
				res.mod >>= 1;
			}
			ans ^= k;
        }
        else {
            int p;
            cin >> p;
            cin >> inp[p];
            update(1, 1, m, p);
        }
    }
    cout << ans;
    return 0;
}