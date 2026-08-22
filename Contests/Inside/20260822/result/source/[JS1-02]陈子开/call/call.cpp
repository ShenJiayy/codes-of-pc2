#include<bits/stdc++.h>
#define mid (pl+pr>>1)
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int MOD=998244353;
const int N=1e5+5;
int n,m,q;
int a[N];
int t[N<<2];
int tag[N<<2];
struct node {
	int type;
	int p;
	int v;
	int c;
	vector<int> op;
}f[N];
void build(int p,int pl,int pr) {
	tag[p]=1;
	if(pl==pr) {
		t[p]=a[pl];
		return ;
	}
	build(ls,pl,mid);
	build(rs,mid+1,pr);
	t[p]=t[ls]+t[rs];
	return ;
}
void pushdown(int p) {
	if(tag[p]>1) {
		tag[ls]=(tag[ls]*tag[p])%MOD;
		tag[rs]=(tag[rs]*tag[p])%MOD;
		t[ls]=(t[ls]*tag[p])%MOD;
		t[rs]=(t[rs]*tag[p])%MOD;
		tag[p]=1;
	}
	return ;
}
void add(int x,int p,int pl,int pr,int k) {
	if(pl==pr) {
		t[p]+=k;
		return ;
	}
	pushdown(p);
	if(mid>=x) add(x,ls,pl,mid,k);
	else add(x,rs,mid+1,pr,k);
	t[p]=t[ls]+t[rs];
	return ;
}
void operate(int id) {
//	cerr<<id<<' ';
	if(f[id].type==1) {
		add(f[id].p,1,1,n,f[id].v);
	}
	else if(f[id].type==2){
		tag[1]=(tag[1]*f[id].v)%MOD;
		t[1]=(t[1]*f[id].v)%MOD;
	}
	else {
		for(int u:f[id].op) {
			operate(u);
		}
	}
	return ;
}
void cnt(int p,int pl,int pr) {
	if(pl==pr) {
//		t[p]=(t[p]*tag[p])%MOD;
		cout<<t[p]<<' ';
		return ;
	}
	pushdown(p);
	cnt(ls,pl,mid);
	cnt(rs,mid+1,pr);
	return ;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++) {
		cin>>f[i].type;
		if(f[i].type==1) {
			cin>>f[i].p>>f[i].v;
		}
		else if(f[i].type==2) {
			cin>>f[i].v;
		}
		else {
			cin>>f[i].c;
			for(int j=1;j<=f[i].c;j++) {
				int t;
				cin>>t;
				f[i].op.push_back(t);
			}
		}
	}
	cin>>q;
	while(q--) {
		int id;
		cin>>id;
		operate(id);
	}
	cnt(1,1,n);
	return 0;
}

