#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6;
struct Node {
	int val, l, r, id;
} a[N + 5];
bool cmp(Node x, Node y) {
	return x.val < y.val;
}

/*
然后我们思考一种最朴素的做法，那就是按排序后的顺序逐一加入区间，然后看看是否有一个点的被覆盖次数>=m。
如果有的话那就统计一下答案，然后将前面加入的按顺序删掉，直到<m。
重复上诉的过程。
很显然这利用了尺取法的思想。
那么问题就是我们如何快速地得知是否有一个点的被覆盖次数>=m。
那就很显然维护一棵线段树就好了。
于是这题就成功解决。
*/
int t[(N << 2) + 5], tag[(N << 2) + 5];
inline void pushdown(int id) {
	if (!tag[id])
		return ;
	int lft = id << 1, rgt = id << 1 | 1;
	t[lft] += tag[id];
	tag[lft] += tag[id];
	t[rgt] += tag[id];
	tag[rgt] += tag[id];
	tag[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int qd) {
	if (ql > r || qr < l)
		return ;
	if (ql <= l && r <= qr) {
		tag[id] += qd;
		t[id] += qd;
		return ;
	}
	int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
	pushdown(id);
	if (ql <= mid)
		update(lft, l, mid, ql, qr, qd);
	if (mid + 1 <= qr)
		update(rgt, mid + 1, r, ql, qr, qd);
	t[id] = max(t[lft], t[rgt]);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> st;
	for (int i = 1; i <= n; i ++) {
		int l, r;
		cin >> l >> r;
		a[i] = {r - l, l, r, i};
		st.push_back(l), st.push_back(r);
	}
	sort(st.begin(), st.end());
	unique(st.begin(), st.end());
	int curr = 0;
	map<int, int> mp;
	for (int val : st)
		mp[val] = ++ curr;
	sort(a + 1, a + n + 1, cmp);
	int ans = 2147483647, l = 0, r = 0;
	while (1) {
		while (r <= n) {
			if (t[1] >= m)
				break;
			r ++;
			update(1, 1, curr, mp[a[r].l], mp[a[r].r], 1);
		}
		if (t[1] < m)
			break;
		while (l <= n) {
			if (t[1] < m)
				break;
			l ++;
			update(1, 1, curr, mp[a[l].l], mp[a[l].r], -1);
		}
		ans = min(ans, a[r].val - a[l].val);
	}
	if (ans == 2147483647)
		puts("-1");
	else cout << ans;
	return 0;
}
