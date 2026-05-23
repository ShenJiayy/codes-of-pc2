#include<bits/stdc++.h>
using namespace std;
int n,m,b1[300005],b2[300005],b[300005];
vector<int> a[300005];
void dfs(int x,int f)
{
	b[x]++;
	for(auto y:a[x])
	{
		if(f==2&&y<x)
		{
			if(b1[y]==0)
			{
				b1[y]=max(b1[y],1);
				dfs(y,1);
			}
			if(b[y]==0)
				b2[x]+=b1[y],b[y]++;
		}
		if(f==1&&y>x)
		{
			if(b2[y]==0)
			{
				b2[y]=max(b2[y],1);
				dfs(y,2);
			}
			if(b[y]==0)
				b1[x]+=b2[y],b[y]++;
		}
	}
	b[x]--;
}
int main()
{
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	a[n+1].push_back(1);
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=n;i++)
		{
			b1[i]=b2[i]=b[i]=0;
		}
		a[n+1][0]=i;
		dfs(n+1,2);
		cout << n-b1[i] << '\n';
	}
	return 0;
}
