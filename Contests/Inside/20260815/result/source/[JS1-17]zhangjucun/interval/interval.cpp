#include<bits/stdc++.h>
using namespace std;
int n,m,mn=1e9+7,mx=-1;
int l[2020],r[2020],t[2020],ans=2147483647;
vector<int> e[100010];
int main()
{
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		for(int j=l[i];j<=r[i];j++) e[j].push_back(i);
		mn=min(mn,l[i]),mx=max(mx,r[i]);
	}	
	for(int i=mn;i<=mx;i++)
	{
		if(e[i].size()>=m)
		{			
			for(int j=0;j<e[i].size();j++) 
			{
				t[j]=r[e[i][j]]-l[e[i][j]];
			}
			sort(t,t+e[i].size());
			for(int j=0;j<e[i].size()-m+1;j++) ans=min(ans,t[j+m-1]-t[j]);
		}
	}
	cout<<ans;
	return 0;
}
