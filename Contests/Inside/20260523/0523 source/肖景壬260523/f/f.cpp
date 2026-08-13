#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans=-1;
vector<int> v[500005];
void dfs(int layer)
{
	if(layer>n)
	{
		int now=1000000000;
		for(int i = 1; i <= n; i++)
		{
			if(v[i].size()==1) return;
			for(int j = 1; j < v[i].size(); j++)
			{
				if(v[i][j]-v[i][j-1]!=v[i][1]-v[i][0]) return;
			}
			if(v[i].size()) now=min(now,v[i][1]-v[i][0]);
		}
		ans=max(ans,now);
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		v[i].push_back(a[layer]);
		dfs(layer+1);
		v[i].pop_back();
	}
	return;
}
int main()
{
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	if(n<=7)
	{
		dfs(1);
		cout<<ans;
	}
	else
	{
		if(n%2==1) cout<<(n-1)/2;
		else cout<<n/2;
	}
}
