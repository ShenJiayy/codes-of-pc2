#include <bits/stdc++.h>
using namespace std;
vector<int>v[300005];
bool is[300005];
int dfn[300005];
void dfs(int x, int fa)
{
	if(is[x]) return;
	dfn[x] = dfn[fa] + 1;
	is[x] = 1;
	if(dfn[fa] % 2 == 0)
	{
		if(fa <= x) return;
	}
	if(dfn[fa] % 2 == 1)
	{
		if(fa >= x) return;
	}
	for(int i : v[x])
	{
		if(i != fa)
		{
			dfs(i, x);
		}
	}
}
int main()
{
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++)
	{
		int cnt = 0;
		memset(is, 0, sizeof(is));
		memset(dfn, 0, sizeof(dfn));
		dfs(i, 0);
		for(int j = 1; j <= n; j++)
		{
			if(is[j] == 0) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
 } 
