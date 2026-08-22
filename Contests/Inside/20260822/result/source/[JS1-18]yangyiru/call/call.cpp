#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
const int mod = 998244353;
int n, m, Q;
int a[N];
ll tree[N*4], tag[N*4];

struct node{
	int op, p; ll val;
	int id, t;
	vector <int> c;
}f[N];

vector <vector <int> > c;

int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}

void push_up(int p){
	tree[p] = (tree[ls(p)] + tree[(rs(p))]) % mod;
}

void build(int p, int pl, int pr){
	if(pl == pr){
		tag[p] = 1;
		tree[p] = a[pl];
		return;
	}
	int mid = (pl+pr) >> 1;
	build(ls(p), pl, mid);
	build(rs(p), mid+1, pr);
	push_up(p); 
}

void addtag(int p, ll k){
	tag[p] = tag[p] * k % mod;
	tree[p] = tree[p] * k % mod;
}

void push_down(int p){
	if(tag[p] != 0){
		addtag(ls(p), tag[p]);
		addtag(rs(p), tag[p]);
		tag[p] = 1;
	}
}

void update(int p, int pl, int pr, int x, ll k){
	if(pl == pr){
		tree[p] = (tree[p] + k) % mod;
		return;
	}
	push_down(p);
	int mid = (pl+pr) >> 1;
	if(x <= mid) update(ls(p), pl, mid, x, k);
	else update(rs(p), mid+1, pr, x, k);
	push_up(p);
}

ll query(int p, int pl, int pr, int x){
	if(pl == pr){
		return tree[p];
	}
	push_down(p);
	int mid = (pl+pr) >> 1;
	if(x <= mid) return query(ls(p), pl, mid, x);
	else return query(rs(p), mid+1, pr, x);
}

void init(int x){
	int op = f[x].op;
	if(op == 1) update(1, 1, n, f[x].p, f[x].val); //µ¥µãÐÞ¸Ä 
	else if(op == 2) addtag(1, f[x].val);
	else{
		for(int i=0; i<f[x].t; i++)
			init(f[x].c[i]);
	}
	return;
}

void Out(int p, int pl, int pr){
	if(pl == pr){
		cout<<tree[p]<<' ';
		return;
	}
	push_down(p);
	int mid = (pl+pr) >> 1;
	Out(ls(p), pl, mid);
	Out(rs(p), mid+1, pr);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=4*n; i++) tag[i] = 1;
	build(1, 1, n);
	cin>>m;
	int tot = 0;
	for(int i=1; i<=m; i++){
		cin>>f[i].op;
		if(f[i].op == 1) cin>>f[i].p>>f[i].val;
		else if(f[i].op == 2) cin>>f[i].val;
		else{
			cin>>f[i].t;
			f[i].id = tot++;
			for(int j=1; j<=f[i].t; j++){
				int g;
				cin>>g;
				f[i].c.push_back(g);
			}
			c.push_back(f[i].c);
		}
	}
	cin>>Q;
	for(int i=1; i<=Q; i++){
		int x;
		cin>>x;
		init(x);
	}
	for(int i=1; i<=n; i++){
		cout<<query(1, 1, n, i)%mod<<' ';
	}
	return 0;
}
