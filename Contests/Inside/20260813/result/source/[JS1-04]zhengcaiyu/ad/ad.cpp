#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5;
const int M=5e3;
struct G
{
	int x,e;
}a[N+4];
struct T
{
	int x,e,l,r;
}b[N+4];
int z,dp[M][M];
inline int read()
{
	int sum=0,f;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
bool cmp1(G x,G y)
{
	return x.x==y.x?x.e>y.e:x.x<y.x;
}
bool cmp2(T x,T y)
{
	return x.r==y.r?x.l<y.l:x.r<y.r;
}
int main()
{
	freopen("ad.in","r",stdin);
//	freopen("ad.out","w",stdout);
	int n=read();
	bool f=true;
	a[1].x=read();
	a[1].e=read();
	for(int i=2;i<=n;++i)
	{
		a[i].x=read();
		a[i].e=read();
		if(a[i].e!=a[i-1].e) f=false;
	}
	sort(a+1,a+n+1,cmp1);
	if(f)
	{
		int ans=0;
		for(int i=1;i<=n;++i) if(a[i].x!=a[i-1].x) ++ans;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i].x!=a[i-1].x)
		{
			b[++z].e=a[i].e;
			b[z].x=a[i].x;
			b[z].l=b[z].r=z;
		}
	}
	for(int i=1;i<=z;++i)
	{
		for(int j=i-1;j;--j) if(b[i].x-b[j].x<=b[i].e-b[j].e) b[i].l=j;
		for(int j=i+1;j<=z;++j) if(b[j].x-b[i].x<=b[i].e-b[j].e) b[i].r=j;
	}
	sort(b+1,b+z+1,cmp2);
	for(int i=1;i<=z;++i) for(int j=1;j<=z;++j) dp[i][j]=2e9;
	for(int i=1;i<=z;++i) 
		for(int j=1;j<=min(b[i].r,z);++j) 
			dp[i][j]=min(dp[i-1][b[i].l]+1,dp[i][j]);
	for(int i=1;i<=z;++i)
	{
		for(int j=1;j<=z;++j) cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	cout<<dp[z][z];
}
