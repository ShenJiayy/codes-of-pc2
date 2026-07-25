#pragma GCC optimize(2)
#pragma GCC optimize(3)


#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int N = 2e6 + 5; 
int n, q, a[N], t[N], l, l2, tmp[N];
int x[N], y[N];
map<int, int> vis, vs;


struct edge {
	int l, r, sum, lazy, minn;
}tree[N * 4];

void push_up(int p) {
	tree[p].minn = min(tree[p << 1].minn, tree[p << 1 | 1].minn);
}

void push_down(int p) {
	if (tree[p].lazy) {
		tree[p << 1].lazy += tree[p].lazy;
		tree[p << 1 | 1].lazy += tree[p].lazy;
		tree[p << 1].minn += tree[p].lazy;
		tree[p << 1 | 1].minn += tree[p].lazy;
		tree[p].lazy = 0;
	}
}

void build(int p, int l, int r) {
	tree[p].l = l, tree[p].r = r;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	push_up(p);
}

void modify(int p, int l, int r, int v) {
	if (l <= tree[p].l && tree[p].r <= r) {
		tree[p].minn += v;
		tree[p].lazy += v;
		return;
	}
	push_down(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (l <= mid) modify(p << 1, l, r, v);
	if (r > mid) modify(p << 1 | 1, l, r, v);
	push_up(p); 
}

int query_min(int p, int l, int r) {
	if (l <= tree[p].l && tree[p].r <= r) return tree[p].minn;
	push_down(p);
	int mid = (tree[p].l + tree[p].r) >> 1, res = 1e9;
	if (l <= mid) res = min(res, query_min(p << 1, l, r));
	if (r > mid) res = min(res, query_min(p << 1 | 1, l, r));
	return res;
}

int flg, cnt;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) cin >> a[i], t[++l] = a[i], t[++l] = a[i] + 1;
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
		t[++l] = y[i];
		t[++l] = y[i] + 1;
	}
	t[++l] = 0;
	for (int i = 1; i <= l; i++) tmp[i] = t[i];
	sort(t + 1, t + l + 1);
	l2 = l;
	l2 = unique(t + 1, t + l + 1) - t - 1;
	for (int i = 1; i <= l; i++) {
		int k = lower_bound(t + 1, t + l2 + 1, tmp[i]) - t;
		vis[tmp[i]] = k;
		vs[k] = tmp[i];
	}
	build(1, 1, l);
	for (int i = 1; i <= n; i++) modify(1, vis[a[i]], vis[a[i]], 1);
	for (int i = 1; i <= q; i++) {
		modify(1, vis[a[x[i]]], vis[a[x[i]]], -1);
		modify(1, vis[y[i]], vis[y[i]], 1);
		
		a[x[i]] = y[i];
		int L = 1, R = l;
		while (L < R) {
			int mid = (L + R + 1) >> 1;
			if (query_min(1, 1, mid) >= 1) L = mid;
			else R = mid - 1; 
		} 
		if (query_min(1, 1, 1) == 0) cout << 0 << endl;
		else cout << vs[L] + 1 << endl;
	}
}
/*
2 1
0 10
1 0
*/

// 虽然不加入 x+1 可以过掉 34/35 个点，但是会被这组数据卡掉
