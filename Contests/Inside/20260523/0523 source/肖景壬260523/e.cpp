#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,fa[600005],lf[600005],ans[600005],now;
vector<int> v[600005];
int find(int x)
{
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
int main()
{
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= 2*n; i++) fa[i]=i;
	for(int i = 1; i <= m; i++)
	{
		cin>>x>>y;
		if(x>y) swap(x,y);
		fa[find(n+y)]=find(x);
	}
	for(int i = 1; i <= 2*n; i++)
	{
		v[find(i)].push_back(i);
	}
	for(int i = 1; i <= 2*n; i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			now=v[i][j];
			if(now>n) now-=n;
			if(lf[now]!=i)
			{
				lf[now]=i;
				ans[i]++;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout<<n-ans[find(i)]<<'\n';
	}
}
