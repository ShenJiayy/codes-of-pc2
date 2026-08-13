#include<bits/stdc++.h>
using namespace std;
int n,m,p[50][50],s[250020];
map<int,int> mp;
long long ans;
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n!=1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>p[i][j];
				p[i][j]--;
				p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=i;k<=n;k++)
					for(int l=j;l<=m;l++) if(p[k][l]-p[k][j-1]-p[i-1][l]+p[i-1][j-1]==0) ans++;
		cout<<ans;
	}
	else
	{
		mp[0]=1;
		for(int i=1;i<=m;i++) 
		{
			cin>>s[i];
			s[i]--;
			s[i]+=s[i-1];			
			ans+=mp[s[i]];
			mp[s[i]]++;
		}
		cout<<ans;
	}
	return 0;
}
