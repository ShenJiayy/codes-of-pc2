#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[3000010];
bool vis[3000010];
void dfs(int no,int p)
{
	vis[no]=1;
	for(int i:g[no])
	{
		if(vis[i]||(i>no&&no>p)||(i<no&&no<p))
		{
			//cout<<no<<" "<<p<<" "<<i<<" NO"<<endl;
			continue;
		}
		//cout<<no<<" "<<p<<" "<<i<<" YES"<<endl;
		dfs(i,no);
	}
	return;
}
int main() 
{
	freopen("e.in","r",stdin);freopen("e.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<endl;
		dfs(i,3000005);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				ans++;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
		}
	}
    return 0;
}

