#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> g[300005];
bool f[300005][2];
void bfs(int s)
{
	for(int i=1;i<=n;i++)
	{
		f[i][0]=f[i][1]=0;
	}
	queue<pair<int,int>> q;
	q.push({s,1});
	while(!q.empty())
	{
		int u=q.front().first,st=q.front().second;
		q.pop();
		f[u][st]=1;
		for(int v:g[u])
		{
			if(f[v][!st]) continue;
			if(st&&u<v)
			{
				q.push({v,(st+1)&1});
			}
			else if(!st&&u>v)
			{
				q.push({v,(st+1)&1});
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!(f[i][0]||f[i][1]))
		{
			cnt++;
		}
	}
	cout<<cnt<<'\n';
}
int main()
{
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}
}
