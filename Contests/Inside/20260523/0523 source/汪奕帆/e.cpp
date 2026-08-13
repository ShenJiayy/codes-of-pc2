#include <bits/stdc++.h>
using namespace std;

const int N=3e5+5;
int n,m,u,v,ans[N][2],vis[N][2],cnt;
vector <int > e[N];

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

void dfs (int x,int t)
{
	if (vis[x][t]) return ;
	if (!vis[x][1]&&!vis[x][0]) cnt++;
//	printf("(%d %d) ",x,t);
	vis[x][t]=1;
	ans[x][t]=1;
	for (int i=0;i<e[x].size();i++)
	{
		if (t==1)
		{
			if (e[x][i]>x)
			{
				dfs(e[x][i],0);
			} 
		}
		else
		{
			if (e[x][i]<x)
			{
				dfs(e[x][i],1);
			}
		}
	}
//	printf("[%d]\n",ans[x][t]);
}

signed main()
{
	freopen ("e.in","r",stdin);
	freopen ("e.out","w",stdout);
	n=read();
	m=read();
	for (int i=1;i<=m;i++) u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		memset(vis,0,sizeof(vis));
		dfs(i,1);
		printf("%d\n",n-cnt);
	}
	return 0;
}
