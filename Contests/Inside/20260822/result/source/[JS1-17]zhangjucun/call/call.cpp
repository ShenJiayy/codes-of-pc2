#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,m,q,cnt;
ll a[100010],t[400040],tmg[400040];
struct func
{
	int o;
	ll x,y;
	int l,r;
}f[100010];
vector<int> e;
void build(int p,int pl,int pr)
{
	if(pl==pr)
	{
		t[p]=a[pl]%mod;
		tmg[p]=1;
		return ;
	}
	int mid=(pl+pr)>>1;
	build(p<<1,pl,mid);
	build(p<<1|1,mid+1,pr);
	t[p]=t[p<<1]+t[p<<1|1];
	tmg[p]=1;
}
void pd(int p,int pl,int pr)
{
	if(tmg[p]>1)
	{
		t[p<<1]*=tmg[p],t[p<<1|1]*=tmg[p];
		t[p<<1]%=mod,t[p<<1|1]%=mod;
		tmg[p<<1]=tmg[p<<1|1]=tmg[p];
		tmg[p]=1;
	}
}
void uad(int p,int pl,int pr,int pos,int d)
{
	if(pl==pr)
	{
		t[p]=(t[p]+d)%mod;
		tmg[p]=1;
		return ;
	}
	pd(p,pl,pr);
	int mid=(pl+pr)>>1;
	if(pos<=mid) uad(p<<1,pl,mid,pos,d);
	else uad(p<<1|1,mid+1,pr,pos,d);
	t[p]=t[p<<1]+t[p<<1|1];
}
ll que(int p,int pl,int pr,int pos)
{
	if(pl==pr)
	{
		return t[p];
	}
	pd(p,pl,pr);
	int mid=(pl+pr)>>1;
	if(pos<=mid) return que(p<<1,pl,mid,pos);
	else return que(p<<1|1,mid+1,pr,pos);
}
void runn(func x)
{
	if(x.o==1)
	{
		uad(1,1,n,x.x,x.y);
	}
	if(x.o==2)
	{
		tmg[1]*=x.x;
		tmg[1]%=mod;
	}
	if(x.o==3)
	{
		for(int i=x.l;i<=x.r;i++) 
		{
			runn(f[e[i]]);
		}
	}	
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	e.push_back(-1);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>f[i].o;
		if(f[i].o==1)
		{
			cin>>f[i].x>>f[i].y;
		}
		if(f[i].o==2)
		{
			cin>>f[i].x;
		}
		if(f[i].o==3)
		{
			int k;
			cin>>k;
			f[i].l=cnt+1,f[i].r=cnt+k;
			cnt+=k;
			for(int j=1;j<=k;j++)
			{
				int c;
				cin>>c;
				e.push_back(c);
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int k;
		cin>>k;
		runn(f[k]);
	}
	for(int i=1;i<=n;i++) cout<<que(1,1,n,i)<<' ';
	return 0;
}
