#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int s[(N << 2) + 5];
int tag[(N << 2) + 5];
inline void pushdown(int id, int l, int r) {
    if (!tag[id]) return ;
    int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
    tag[lft] ^= tag[id];
    s[lft] = (mid - l + 1) - s[lft];
    tag[rgt] ^= tag[id];
    s[rgt] = (r - mid) - s[rgt];
    tag[id] = 0;
}
void buildAll(int id, int l, int r) {
    if (l == r) {
        s[id] = 0;
		return ;
	}
    pushdown(id, l, r);
	int mid = l + r >> 1;
	buildAll(id * 2, l, mid);
	buildAll(id * 2 + 1, mid + 1, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}
void updateOne(int id, int l, int r, int p) {
    if (l == r) {
        s[id] ^= 1;
        return ;
    }
    pushdown(id, l, r);
    int mid = l + r >> 1;
    if (p <= mid)
        updateOne(id * 2, l, mid, p);
    else
        updateOne(id * 2 + 1, mid + 1, r, p);
    s[id] = s[id * 2] + s[id * 2 + 1];
}
int queryBlock(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return s[id];
    pushdown(id, l, r);
    int res = 0, mid = l + r >> 1;
    if (ql <= mid)
        res += queryBlock(id * 2, l, mid, ql, qr);
    if (mid + 1 <= qr)
        res += queryBlock(id * 2 + 1, mid + 1, r, ql, qr);
    return res;
}
void updateBlock(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        tag[id] ^= 1;
        s[id] = r - l + 1 - s[id];
		return ;
	}
    pushdown(id, l, r);
    int mid = l + r >> 1;
    if (ql <= mid)
        updateBlock(id * 2, l, mid, ql, qr);
    if (mid + 1 <= qr)
        updateBlock(id * 2 + 1, mid + 1, r, ql, qr);
    s[id] = s[id * 2] + s[id * 2 + 1];
}
signed main() {
    int n, T;
    cin >> n >> T;
    buildAll(1, 1, n);
    while (T --) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 0) 
            updateBlock(1, 1, n, l, r);
        else
            cout << queryBlock(1, 1, n, l, r) << endl;
    }
    return 0;
}