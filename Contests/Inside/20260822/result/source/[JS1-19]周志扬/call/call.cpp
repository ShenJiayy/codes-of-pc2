#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[100005];
struct Fuction { int op, pos, val, len;  vector<int> G; } F[100005];

struct AutoMod {
	const int Mod = 998244353;
	
	int Add(int X, int Y) {
		int res = X + Y;
		while(res > Mod) res -= Mod;
		while(res < -Mod) res += Mod;
		return res;
	}
	
	int Mul(int X, int Y) {
		int res = X * Y;
		while(res > Mod) res -= Mod;
		while(res < -Mod) res += Mod;
		return res;
	}
	
	void Add_give(int &X, int Y) {
		int res = X + Y;
		while(res > Mod) res -= Mod;
		while(res < -Mod) res += Mod;
		X = res;
	}
	
	void Mul_give(int &X, int Y) {
		int res = X * Y;
		while(res > Mod) res -= Mod;
		while(res < -Mod) res += Mod;
		X = res;
	}
} Cal;

struct SegmentTree {
	struct Point { int l, r, tag, val; } tree[100005 << 2];
	
	void Add_tag(int pos, int K) { Cal.Mul_give(tree[pos].tag, K);  Cal.Mul_give(tree[pos].val, K); }
	
	void Push_up(int pos) { tree[pos].val = Cal.Add(tree[pos << 1].val, tree[pos << 1 | 1].val); }
	
	void Push_down(int pos) {
		if(tree[pos].tag == 1) return;
		Add_tag(pos << 1, tree[pos].tag);
		Add_tag(pos << 1 | 1, tree[pos].tag);
		tree[pos].tag = 1;
	}
	
	void Build(int pos, int L, int R, int *Data) {
		tree[pos].l = L, tree[pos].r = R, tree[pos].tag = 1;
		if(L == R) { tree[pos].val = Data[L];  return; }
		
		int mid = L + R >> 1, Left_son = pos << 1, Right_son = pos << 1 | 1;
		Build(Left_son, L, mid, Data);
		Build(Right_son, mid + 1, R, Data);
		
		Push_up(pos);
	}
	
	void Update(int pos, int P, int K) {
		if(tree[pos].r < P || P < tree[pos].l) return;
		if(tree[pos].l == tree[pos].r) { Cal.Add_give(tree[pos].val, K);  return; }
		
		Push_down(pos);
		
		int Left_son = pos << 1, Right_son = pos << 1 | 1;
		Update(Left_son, P, K);
		Update(Right_son, P, K);
		
		Push_up(pos);
	}
	
	int Query(int pos, int L, int R) {
		if(tree[pos].r < L || R < tree[pos].l) return 0;
		if(L <= tree[pos].l && tree[pos].r <= R) return tree[pos].val;
		
		Push_down(pos);
		
		int Left_son = pos << 1, Right_son = pos << 1 | 1, res = 0;
		Cal.Add_give(res, Query(Left_son, L, R));
		Cal.Add_give(res, Query(Right_son, L, R));
		
		return res;
	}
} Tree;

void Use(int x) {
	if(F[x].op == 1) { Tree.Update(1, F[x].pos, F[x].val);  return; }
	if(F[x].op == 2) { Tree.Add_tag(1, F[x].val);  return; }
	if(F[x].op == 3) { for(int i = 0; i < F[x].G.size(); i++) Use(F[x].G[i]);  return; }
}

signed main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	
	int n, m, Q;  scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);  Tree.Build(1, 1, n, A);
	scanf("%lld", &m);  m++;
	
	for(int i = 1; i <= m; i++) {
		if(i < m)  scanf("%lld", &F[i].op);
		else F[i].op = 3;
		
		if(F[i].op == 1) scanf("%lld %lld", &F[i].pos, &F[i].val);
		if(F[i].op == 2) scanf("%lld", &F[i].val);
		if(F[i].op == 3) {
			scanf("%lld", &F[i].len);
			for(int j = 1; j <= F[i].len; j++) { int x;  scanf("%lld", &x);  F[i].G.push_back(x); }
		}
	}
	
	Use(m);
	
	for(int i = 1; i <= n; i++) printf("%lld ", Tree.Query(1, i, i));
	return 0;
}
