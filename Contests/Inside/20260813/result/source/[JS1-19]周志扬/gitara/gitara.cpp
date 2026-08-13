#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegmentTree {
	struct Point { int l, r, tag, val; }  tree[300005 << 2];
	
	int Len(int pos) { return tree[pos].r - tree[pos].l + 1; }
	
	void Add_tag(int pos, int K) { tree[pos].tag = K, tree[pos].val = K * Len(pos); }
	
	void Push_up(int pos) { tree[pos].val = tree[pos << 1].val + tree[pos << 1 | 1].val; }
	
	void Push_down(int pos) {
		if(tree[pos].tag == -1) return;
		Add_tag(pos << 1, tree[pos].tag);  Add_tag(pos << 1 | 1, tree[pos].tag);
		tree[pos].tag = -1;
	}
	
	void Build(int pos, int L, int R) {
		tree[pos].l = L, tree[pos].r = R, tree[pos].tag = -1;
		if(L == R) { tree[pos].val = 0;  return; }
		
		int mid = L + R >> 1, Left_son = pos << 1, Right_son = pos << 1 | 1;
		Build(Left_son, L, mid);
		Build(Right_son, mid + 1, R);
		
		Push_up(pos);
	}
	
	void Update(int pos, int L, int R, int K) {
		if(tree[pos].r < L || R < tree[pos].l) return;
		if(L <= tree[pos].l && tree[pos].r <= R) { Add_tag(pos, K);  return; }
		
		Push_down(pos);
		
		int Left_son = pos << 1, Right_son = pos << 1 | 1;
		Update(Left_son, L, R, K);
		Update(Right_son, L, R, K);
		
		Push_up(pos);
	}
	
	int Query(int pos, int L, int R) {
		if(tree[pos].r < L || R < tree[pos].l) return 0;
		if(L <= tree[pos].l && tree[pos].r <= R) return tree[pos].val;
		
		Push_down(pos);
		
		int Left_son = pos << 1, Right_son = pos << 1 | 1, res = 0;
		res += Query(Left_son, L, R);
		res += Query(Right_son, L, R);
		
		return res;
	}
} Tree[10];

signed main() {
	freopen("gitara.in", "r", stdin);
	freopen("gitara.out", "w", stdout);
	int n, P, Ans = 0;  scanf("%lld %lld", &n, &P);  for(int i = 1; i <= 6; i++) Tree[i].Build(1, 1, P);
	for(int i = 1; i <= n; i++) {
		int x, y;  scanf("%lld %lld", &x, &y);
		Ans += Tree[x].Query(1, y + 1, P);  Tree[x].Update(1, y + 1, P, 0);
		Ans += (Tree[x].Query(1, y, y) == 0);  Tree[x].Update(1, y, y, 1);
	}
	printf("%lld", Ans);
	return 0;
}
