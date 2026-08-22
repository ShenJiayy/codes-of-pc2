#include<bits/stdc++.h>
using namespace std;
#define int __int128
inline int read()
{
     int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
inline void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
int a[1000010];bool b[70];
bool vis[70];
int qp(int x,int y)
{
	int ans=1;
	while(y>0)
	{
		if(y&1)
		{
			ans*=x;
		}
		x*=x;y>>=1;
	}
	return ans;
}
signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	n=read();
	m=read();
	c=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int j=0;j<=k;j++)
		{
			int c=a/qp(2,j);
			if(c&1)b[j]=1;
			//cout<<i<<" "<<j<<" "<<b[j]<<" "<<a<<" "<<c<<endl;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int p,q;
		p=read();
		q=read();
		vis[p]=1;
		if(!b[p]&&vis[p])k--;
		//cout<<p<<" "<<b[p]<<" "<<vis[p]<<" "<<k<<endl;
	}
	out(qp(2,k)-n);
    return 0;
}

