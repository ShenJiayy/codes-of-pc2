#include<bits/stdc++.h>
using namespace std;
#define int long long
int xxkan[200005<<2][2];
pair<int,int> a[200005];
int b[200005],c[200005];
int cf[200005][2];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
void pushup(int p,int op)
{
	xxkan[p][op]=max(xxkan[ls(p)][op],xxkan[rs(p)][op]);
}
void build(int p,int l,int r,int op)
{
	if(l==r)
	{
		xxkan[p][op]=cf[l][op];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid,op);
	build(rs(p),mid+1,r,op);
	pushup(p,op);
}
int getans(int p,int nl,int nr,int l,int r,int op)
{
	if(l<=nl&&nr<=r)
	{
		return xxkan[p][op];
	}
	int mid=(nl+nr)>>1,re=0;
	if(l<=mid) re=max(getans(ls(p),nl,mid,l,r,op),re);
	if(mid<r) re=max(getans(rs(p),mid+1,nr,l,r,op),re);
	return re; 
}
signed main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n+2);
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		cf[i][0]=max(a[i].first-b[i],0ll);
		cf[i+1][1]=max(a[i+1].first-b[i],0ll);
	}
	build(1,1,n,0);
	build(1,1,n+1,1);
	for(int i=1;i<=n+1;i++)
	{
		if(i==1)
		{
			c[a[i].second]=getans(1,1,n+1,2,n+1,1);
		}
		else if(i==n+1)
		{
			c[a[i].second]=getans(1,1,n,1,n,0);
		}
		else
		{
			c[a[i].second]=max(getans(1,1,n,1,i-1,0),getans(1,1,n+1,i+1,n+1,1));
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
