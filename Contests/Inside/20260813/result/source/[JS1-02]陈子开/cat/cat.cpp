#include<bits/stdc++.h>
#define int long long
#define mid (pl+pr>>1)
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int N=2e5+5;
int pos[N];
int t[N<<2];
int n;
int a[N];
void build(int p,int pl,int pr) {
	if(pl==pr) {
		t[p]=a[pl];
		return ;
	}
	build(ls,pl,mid);
	build(rs,mid+1,pr);
	t[p]=max(t[ls],t[rs]);
	return ;
}
int query(int l,int r,int p,int pl,int pr) {
	if(l>r) return 0;
	if(l<=pl&&pr<=r) {
		return t[p];
	}
	int res=0;
	if(mid>=l) res=max(res,query(l,r,ls,pl,mid));
	if(mid<r) res=max(res,query(l,r,rs,mid+1,pr));
	return res;
}
int getans(int p,int l,int r) {
	if(l>=r) return 0;
	int L=pos[query(l,p-1,1,1,n)];
	int R=pos[query(p+1,r,1,1,n)];
	if(L==0)
		return R-p+getans(R,p+1,r);
	if(R==0)
		return p-L+getans(L,l,p-1);
	return max(p-L+getans(L,l,p-1),R-p+getans(R,p+1,r));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		pos[a[i]]=i;
	}
	pos[0]=0;
	for(int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
	}
	build(1,1,n);
	cout<<getans(pos[n],1,n);
	return 0;
}

