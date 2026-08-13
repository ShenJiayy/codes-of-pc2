#include<bits/stdc++.h>
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)

using namespace std;
using ll=long long;

const int maxn=2e5+5;

int n,a[maxn],q[maxn],b[maxn],h[maxn],lst[maxn],ltt,lll=maxn,dep=1;
int tr[maxn<<2],prt[maxn];
void pushdown(int x){
	if(tr[x]){
		tr[ls(x)]=tr[x];
		tr[rs(x)]=tr[x];
		tr[x]=0;
	}
}
void update(int x,int l,int r,int nl,int nr,int cl){
	if(nl<=l&&nr>=r){
		tr[x]=cl;
		return;
	}
	pushdown(x);
	int mid=(l+r)>>1;
	if(nl<=mid)update(ls(x),l,mid,nl,nr,cl);
	if(nr>mid)update(rs(x),mid+1,r,nl,nr,cl);
}
void query(int x,int l,int r,int nl,int nr){
	if(nl<=l&&nr>=r&&tr[x]){
		for(int i=l;i<=r;i++){
			prt[i]=tr[x];
		}
		return;
	}
	int mid=(l+r)>>1;
	if(nl<=mid)query(ls(x),l,mid,nl,nr);
	if(nr>mid)query(rs(x),mid+1,r,nl,nr);
}
int main(){
	freopen("stone.in","r",stdin);  //搞么子 
	freopen("stone.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(dep<n){
		dep<<=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int ln=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		int ss=a[i];
		h[i]=lower_bound(b+1,b+ln+1,ss)-b;//注意最后还是输出a[i] 
	}
	for(int i=1;i<=n;i++){
		if(lst[h[i]]>ltt||(lst[h[i]]<lll&&lst[h[i]]>0)){
			update(1,1,dep,lst[h[i]],i,a[i]);
			lll=lst[h[i]];
			ltt=i;
		}
		else{
			update(1,1,dep,i,i,a[i]);
		}
		lst[h[i]]=i;
	}
	query(1,1,dep,1,n);
	for(int i=1;i<=n;i++){
		cout<<prt[i]<<"\n";
	}
	return 0;
}
