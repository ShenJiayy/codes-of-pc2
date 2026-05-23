#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5+5;
int n,q,a[N],c,d,s[N];

inline int read()
{
    int x=0,f=1;
	char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}

inline void write (int x)
{
    if (x<0) putchar('-'),x=-x;
    if (x>9) write(x/10);
    putchar(x%10+'0');
}

inline int query (int x,int c,int d)
{
	int y=x*d;
	int l=1,r=n,mid,ans=-1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (a[mid]>=y) ans=mid,r=mid-1;
		else l=mid+1;
	}
	//printf("(%d %d %d %d %lld)\n",x,c,d,ans,x*c+(s[n]-s[ans-1])-y*(n-ans+1));
	if (ans==-1) return min(s[n],c*x);
	return x*c+(s[n]-s[ans-1])-y*(n-ans+1);
}

inline int solve (int c,int d)
{
	int l=a[1]/d,r=a[n]/d+1,mid,m1,m2,ans=s[n];
	while (l<=r)
	{
		mid=(l+r)>>1;
		m1=query(mid,c,d);
		m2=query(mid+1,c,d);
		if (m1<=m2) ans=min(ans,m1),r=mid-1;
		else ans=min(ans,m2),l=mid+1; 
	}
	write(ans);
	putchar('\n');
}

signed main()
{
	freopen ("d.in","r",stdin);
	freopen ("d.out","w",stdout);
	n=read();
	q=read();
	for (register int i=1;i<=n;i++) a[i]=read();
	sort (a+1,a+n+1);
	for (register int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	while (q--)
	{
		c=read();
		d=read();
		solve(c,d);
	}
	return 0;
}
