#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,m;
int a[100005];
int ans[100005<<2];
int tag1[100005<<2],tag2[100005<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int x)
{
	ans[x]=ans[ls(x)]+ans[rs(x)];
}
void build(int x,int l,int r)
{
	tag1[x]=1;
	tag2[x]=0;
	if(l==r)
	{
		ans[x]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	push_up(x);
}
void f(int x,int l,int r,int k1,int k2)
{
	ans[x]=(k1*ans[x]%MOD+(r-l+1)*k2%MOD)%MOD;
	tag1[x]=(tag1[x]*k1)%MOD;
	tag2[x]=(k2+k1*tag2[x])%MOD;
}
void push_down(int x,int l,int r)
{
	int mid=(l+r)>>1;
	f(ls(x),l,mid,tag1[x],tag2[x]);
	f(rs(x),mid+1,r,tag1[x],tag2[x]);
	tag1[x]=1;
	tag2[x]=0;
}
void update1(int x,int nl,int nr,int l,int r,int k)
{
	if(l<=nl&&nr<=r)
	{
		ans[x]=ans[x]*k%MOD;
		tag1[x]=tag1[x]*k%MOD;
		tag2[x]=tag2[x]*k%MOD;
		return;
	}
	push_down(x,nl,nr);
	int mid=(nl+nr)>>1;
	if(l<=mid) update1(ls(x),nl,mid,l,r,k);
	if(mid<r) update1(rs(x),mid+1,nr,l,r,k);
	push_up(x);
}
void update2(int x,int nl,int nr,int l,int r,int k)
{
	if(l<=nl&&nr<=r)
	{
		ans[x]=(ans[x]+k*(nr-nl+1)%MOD)%MOD;
		tag2[x]=(tag2[x]+k)%MOD;
		return ;
	} 
	push_down(x,nl,nr);
	int mid=(nl+nr)>>1;
	if(l<=mid) update2(ls(x),nl,mid,l,r,k);
	if(mid<r) update2(rs(x),mid+1,nr,l,r,k);
	push_up(x); 
}
int query(int x,int nl,int nr,int l,int r)
{
	if(l<=nl&&nr<=r) return ans[x];
	int res=0;
	push_down(x,nl,nr);
	int mid=(nl+nr)>>1;
	if(l<=mid) res=(res+query(ls(x),nl,mid,l,r))%MOD;
	if(mid<r) res=(res+query(rs(x),mid+1,nr,l,r))%MOD;
	return res%MOD; 
}
struct cz
{
	int op;
	int wei,kkk;
	vector<int> czxl;
	int len;
}xjc[100005];
void jingxincaozuo3(int xuhao)
{
	for(int i=0;i<xjc[xuhao].czxl.size();i++)
	{
		int xindexuhao=xjc[xuhao].czxl[i];
		if(xjc[xindexuhao].op==1)
		{
			update2(1,1,n,xjc[xindexuhao].wei,xjc[xindexuhao].wei,xjc[xindexuhao].kkk);
		}
		else if(xjc[xindexuhao].op==2)
		{
			update1(1,1,n,1,n,xjc[xindexuhao].kkk);
		}
		else
		{
			jingxincaozuo3(xindexuhao);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>xjc[i].op;
		if(xjc[i].op==1)
		{
			cin>>xjc[i].wei>>xjc[i].kkk;
		}
		else if(xjc[i].op==2)
		{
			cin>>xjc[i].kkk;
		}
		else
		{
			int xcx;
			cin>>xcx;
			xjc[i].len=xcx;
			while(xcx--)
			{
				int genshin;
				cin>>genshin;
				xjc[i].czxl.push_back(genshin);
			}
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int xuhao;
		cin>>xuhao;
		if(xjc[xuhao].op==1)
		{
			update2(1,1,n,xjc[xuhao].wei,xjc[xuhao].wei,xjc[xuhao].kkk);
		}
		else if(xjc[xuhao].op==2)
		{
			update1(1,1,n,1,n,xjc[xuhao].kkk);
		}
		else
		{
			jingxincaozuo3(xuhao);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<query(1,1,n,i,i)<<" ";
	}
	return 0;
}
