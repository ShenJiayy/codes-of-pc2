#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
struct G
{
	int l,r,len;
}a[N+4];
struct T
{
	int x,len;
}d[100*N];
int b[4+N<<1],z,c[4+N<<1],kk[N+4];
long long ans=4e18+697;
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
bool cmp(T x,T y)
{
	return x.x==y.x?x.len<y.len:x.x<y.x;
}
int main()
{
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	const int n=read(),m=read();
	int now;
	for(int i=1;i<=n;++i)
	{
		b[++z]=a[i].l=read();
		b[++z]=a[i].r=read();
		a[i].len=a[i].r-a[i].l+1;
	}
	sort(b+1,b+z+1);
	map<int,int> mp;
	for(int i=1;i<=z;++i) if(mp.find(b[i])==mp.end()) mp.insert(pair<int,int>{b[i],mp.size()+1});
	z=0;
	for(int i=1;i<=n;++i)
	{
		const int l=mp[a[i].l],r=mp[a[i].r];
		for(int j=l;j<=r;++j)
		{
			d[++z].x=j;
			d[z].len=a[i].len;
		}
	}
	sort(d+1,d+z+1,cmp);
	for(int i=1,j;i<=z;i=now+1)
	{
		int nn=1;
		kk[1]=d[i].len;
		for(j=i+1;j<=z&&d[j].x==d[i].x;++j) kk[++nn]=d[j].len;
		now=j-1;
		if(nn<m) continue;
		sort(kk+1,kk+nn+1);
		for(int j=1;j+m-1<=nn;++j) ans=(ans>kk[j+m-1]-kk[j]?kk[j+m-1]-kk[j]:ans);
	}
	printf("%lld",(ans==4e18+697?-1:ans));
}
