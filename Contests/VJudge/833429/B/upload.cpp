#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int s[(N << 2) + 5];
int tag[(N << 2) + 5];
inline int base(int l, int r) {
	return (r - l + 1) * (r + l) / 2;
}
inline void pushdown(int id, int l, int r) {
    if (!tag[id]) return ;
    int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
    tag[lft] += tag[id];
    s[lft] += tag[id] * (mid - l + 1);
    tag[rgt] += tag[id];
    s[rgt] += tag[id] * (r - mid);
    tag[id] = 0;
}
void updateOne(int id, int l, int r, int p, int d) {
    if (l == r) {
        s[id] += d;
        return ;
    }
    pushdown(id, l, r);
    int mid = l + r >> 1;
    if (p <= mid)
        updateOne(id * 2, l, mid, p, d);
    else
        updateOne(id * 2 + 1, mid + 1, r, p, d);
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
void updateBlock(int id, int l, int r, int ql, int qr, int qd) {
    if (ql <= l && r <= qr) {
        tag[id] += qd;
        s[id] += qd * (r - l + 1);
		return ;
	}
    pushdown(id, l, r);
    int mid = l + r >> 1;
    if (ql <= mid)
        updateBlock(id * 2, l, mid, ql, qr, qd);
    if (mid + 1 <= qr)
        updateBlock(id * 2 + 1, mid + 1, r, ql, qr, qd);
    s[id] = s[id * 2] + s[id * 2 + 1];
}
signed main() {
    int n, T;
    cin >> n >> T;
    while (T --) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1) {
			int d;
			cin >> d;
            updateBlock(1, 1, n, l, r, d);
		}
        else
            cout << base(l, r) + queryBlock(1, 1, n, l, r) << endl;
    }
    return 0;
}