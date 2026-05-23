#include <bits/stdc++.h>
using namespace std;

const int N=3505;
int n,a[N],b[N][N],top[N],ans=-1;

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

void dfs (int t)
{
	if (t>n)
	{
		int m=1e9;
		for (int i=1;i<=n;i++)
		{
			if (top[i]==1) return ;
			if (top[i]==0) continue;
			for (int j=3;j<=top[i];j++)
			{
				if (a[b[i][j]]-a[b[i][j-1]]!=a[b[i][j-1]]-a[b[i][j-2]]) return ;
			}
			m=min(m,a[b[i][2]]-a[b[i][1]]);
		}
		ans=max(ans,m);
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		top[i]++;
		b[i][top[i]]=t;
		dfs(t+1);
		top[i]--;
	}
}

signed main()
{
	freopen ("f.in","r",stdin);
	freopen ("f.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n<=7)
	{
		dfs(1);
		write(ans);
	}
	else write(n/2);
	return 0;
}
