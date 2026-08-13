#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5;
struct T
{
	int x,id;
}t[N<<2];
int h[N+4],n;
ll ans,sum;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		t[p].x=h[l];
		t[p].id=l;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	if(t[p<<1].x>t[p<<1|1].x) t[p].id=t[p<<1].id;
	else t[p].id=t[p<<1|1].id;
	t[p].x=t[p<<1].x>t[p<<1|1].x?t[p<<1].x:t[p<<1|1].x;
}
T fd(int p,int l,int r,int nl,int nr)
{
	if(nl>r||nr<l||nr<nl) return {-1,-1};
	if(nl<=l&&nr>=r) return t[p];
	int mid=(l+r)>>1;
	T x=fd(p<<1,l,mid,nl,nr),y=fd(p<<1|1,mid+1,r,nl,nr);
	if(x.x>y.x) return x;
	else return y;
}
void dfs(int now,int zl,int zr)
{
	if(zl==zr)
	{
		ans=ans>=sum?ans:sum;
		return;
	}
	T kl=fd(1,1,n,zl,now-1),kr=fd(1,1,n,now+1,zr);
	if(kl.id>0)
	{
		sum+=(now-kl.id);
		dfs(kl.id,zl,now-1);
		sum-=(now-kl.id);
	}
	if(kr.id>0)
	{
		sum+=(kr.id-now);
		dfs(kr.id,now+1,zr);
		sum-=(kr.id-now);
	}
}
int main()
{
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	n=read();
	int sta;
	for(int i=1;i<=n;++i)
	{
		h[i]=read();
		if(h[i]==n) sta=i;
	}
	build(1,1,n);
	dfs(sta,1,n);
	cout<<ans;
}
