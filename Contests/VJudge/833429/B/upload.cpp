#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Query {
	int opt, l, r, d;
} qs[N + 5];
int a[N + 5], s[(N << 2) + 5];
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
void buildAll(int id, int l, int r) {
    if (l == r) {
        s[id] = a[l];
		return ;
	}
    pushdown(id, l, r);
	int mid = l + r >> 1;
	buildAll(id * 2, l, mid);
	buildAll(id * 2 + 1, mid + 1, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
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
	set<int> st;
	map<int, int> mmp;
	for (int t = 1; t <= T; t ++) {
		cin >> qs[t].opt >> qs[t].l >> qs[t].r;
		st.insert(qs[t].l), st.insert(qs[t].r);
		if (qs[t].opt == 1)
			cin >> qs[t].d; 
	}
	int curr = 0;
	for (int val : st)
		mmp[val] = ++ curr;
    buildAll(1, 1, curr);
    for (int t = 1; t <= T; t ++) {
		if (qs[t].opt == 1) 
			updateBlock(1, 1, curr, mmp[qs[t].l], mmp[qs[t].r], qs[t].d);
		else
			cout << base(qs[t].l, qs[t].r) + queryBlock(1, 1, curr, mmp[qs[t].l], mmp[qs[t].r]) << endl;
	}
    return 0;
}