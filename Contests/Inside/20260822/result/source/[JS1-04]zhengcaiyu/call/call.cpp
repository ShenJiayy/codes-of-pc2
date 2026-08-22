#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5,M=1e6;
const ll mod=998244353;
struct G
{
	int op,x,l,r;
	ll y;
}b[N+4];
int cc[M+4],z,a[N+4],n;
ll t[N<<2],tag[N<<2];
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
	tag[p]=1;
	if(l==r)
	{
		t[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	t[p]=t[p<<1]+t[p<<1|1];
}
void add(int p,int l,int r,int x,ll k)
{
	if(l==r)
	{
		t[p]+=k;
		t[p]=(t[p]>=mod?t[p]-mod:t[p]);
		return;
	}
	if(tag[p]!=1)
	{
		tag[p<<1]*=tag[p];
		tag[p<<1|1]*=tag[p];
		t[p<<1]*=tag[p];
		t[p<<1|1]*=tag[p];
		tag[p]=1;
		tag[p<<1]%=mod;
		tag[p<<1|1]%=mod;
		t[p<<1]%=mod;
		t[p<<1|1]%=mod;
	}
	int mid=(l+r)>>1;
	if(x<=mid) add(p<<1,l,mid,x,k);
	else add(p<<1|1,mid+1,r,x,k);
	t[p]=t[p<<1]+t[p<<1|1];
}
void tis(ll x)
{
	if(tag[1]!=1)
	{
		tag[2]*=tag[1];
		tag[3]*=tag[1];
		t[2]*=tag[1];
		t[3]*=tag[1];
		tag[2]%=mod;
		tag[3]%=mod;
		t[2]%=mod;
		t[3]%=mod;
	}
	tag[1]=x;
}
void fff(int x)
{
	for(int i=b[x].l;i<=b[x].r;++i)
	{
		if(b[cc[i]].op==1) add(1,1,n,b[cc[i]].x,b[cc[i]].y);
		if(b[cc[i]].op==2) tis(b[cc[i]].y);
		if(b[cc[i]].op==3) fff(cc[i]);
	}
}
void write(int p,int l,int r)
{
	if(l==r)
	{
		printf("%lld ",(t[p]>=mod?t[p]-mod:t[p]));
		return;
	}
	if(tag[p]!=1)
	{
		tag[p<<1]*=tag[p];
		tag[p<<1|1]*=tag[p];
		t[p<<1]*=tag[p];
		t[p<<1|1]*=tag[p];
		tag[p]=1;
		tag[p<<1]%=mod;
		tag[p<<1|1]%=mod;
		t[p<<1]%=mod;
		t[p<<1|1]%=mod;
	}
	int mid=(l+r)>>1;
	write(p<<1,l,mid);
	write(p<<1|1,mid+1,r);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	build(1,1,n);
	int m=read();
	for(int i=1;i<=m;++i)
	{
		b[i].op=read();
		if(b[i].op==1)
		{
			b[i].x=read();
			b[i].y=read();
		}
		if(b[i].op==2) b[i].y=read();
		if(b[i].op==3)
		{
			b[i].l=z+1;
			b[i].r=z+read();
			for(int j=b[i].l;j<=b[i].r;++j) cc[j]=read();
			z=b[i].r;
		}
	}
	int q=read();
	while(q--)
	{
		int x=read();
		if(b[x].op==1) add(1,1,n,b[x].x,b[x].y);
		if(b[x].op==2) tis(b[x].y);
		if(b[x].op==3) fff(x);
	}
	write(1,1,n);
}
