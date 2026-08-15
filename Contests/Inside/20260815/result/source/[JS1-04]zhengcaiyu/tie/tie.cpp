#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5;
struct G
{
	int id;
	ll len,maxx;
}a[N+4];
ll b[N+4],ans[N+4],c[N+4],d[N+4],t1[N<<2],t2[N<<2];
inline ll read()
{
	ll sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
bool cmp(G x,G y)
{
	return x.len<y.len;
}
inline ll ma(ll x,ll y)
{
	return x>y?x:y;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		t1[p]=c[l];
		t2[p]=d[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	t1[p]=ma(t1[p<<1],t1[p<<1|1]);
	t2[p]=ma(t2[p<<1],t2[p<<1|1]);
}
ll fd1(int p,int l,int r,int nl,int nr)
{
	if(nr<nl) return 0;
	if(nl<=l&&nr>=r) return t1[p];
	int mid=(l+r)>>1;
	ll xx=0;
	if(nl<=mid) xx=ma(xx,fd1(p<<1,l,mid,nl,nr));
	if(nr>mid) xx=ma(xx,fd1(p<<1|1,mid+1,r,nl,nr));
	return xx;
}
ll fd2(int p,int l,int r,int nl,int nr)
{
	if(nr<nl) return 0;
	if(nl<=l&&nr>=r) return t2[p];
	int mid=(l+r)>>1;
	ll xx=0;
	if(nl<=mid) xx=ma(xx,fd2(p<<1,l,mid,nl,nr));
	if(nr>mid) xx=ma(xx,fd2(p<<1|1,mid+1,r,nl,nr));
	return xx;
}
int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	int n=read();
	for(int i=1;i<=n+1;++i)
	{
		a[i].len=read();
		a[i].id=i;
	}
	for(int i=1;i<=n;++i) b[i]=read();
	sort(a+1,a+n+2,cmp);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
	{
		c[i]=ma(a[i].len-b[i],0);
		d[i]=ma(a[i+1].len-b[i],0);
	}
	build(1,1,n);
	for(int i=1;i<=n+1;++i) ans[a[i].id]=ma(fd1(1,1,n,1,i-1),fd2(1,1,n,i,n));
	for(int i=1;i<=n+1;++i) printf("%lld ",ans[i]);
}
