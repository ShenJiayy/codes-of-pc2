#include<bits/stdc++.h>
using namespace std;
int n,m,d[20],t[20],dis[20][20],ma,ans=0,book[20];
struct node
{
	int l,r;
}a[20];
int dfs(int x,int y,int step)
{
	if(y>ma)
	    return step;
	if(book[x]) return step;
	book[x]=1;
	if(y<=t[x])
		step++;
	int L=a[x].l,R=a[x].r;
	if(L!=R)
		a[R].l=L,a[L].r=R;
	int cnt=max(dfs(L,y+dis[x][L],step),
	dfs(R,y+dis[x][R],step));
	a[R].l=x,a[L].r=x;
	book[x]=0;
	return cnt;
}
int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> d[i] >> t[i];
		a[i].l=i-1,a[i].r=i+1;
		ma=max(t[i],ma);
	}
	a[1].l=n,a[n].r=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=min(abs(d[i]-d[j])
			,m-abs(d[i]-d[j]));
	cout << max(dfs(n,min(abs(m-d[n]),m-abs(m-d[n])),0),
	dfs(1,min(abs(m-d[1]),m-abs(m-d[1])),0));
	return 0;
}
