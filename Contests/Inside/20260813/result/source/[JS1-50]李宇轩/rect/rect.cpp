#include<bits/stdc++.h>
using namespace std;
const int N=250005;
int n,m,ans,q[N],t;
vector<int> a[250005];
int mp[N*20];
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin >> n >> m;
	for(int j=0;j<=m;j++)
	{
		a[0].push_back(0);
	}
	for(int i=1;i<=n;i++)
	{
		a[i].push_back(0);
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			a[i].push_back(x-1);
			a[i][j]+=a[i-1][j]+
			a[i][j-1]-a[i-1][j-1];
		}
	}
	if(n<=m)
	for(int i=1;i<=n;i++)
	{
		for(int i1=0;i1<i;i1++)
		{
			mp[10*N]=1;
			for(int j=1;j<=m;j++)
			{
				q[++t]=a[i][j]-a[i1][j];
				ans+=mp[a[i][j]-a[i1][j]+10*N];
				mp[a[i][j]-a[i1][j]+10*N]++;
			}
			for(int j=0;j<=t;j++)
			{
				mp[q[j]+10*N]=0;
			}
			t=0;
		}
	}
	else
	for(int i=1;i<=m;i++)
	{
		for(int i1=0;i1<i;i1++)
		{
			mp[10*N]=1;
			for(int j=1;j<=n;j++)
			{
				q[++t]=a[j][i]-a[j][i1];
				ans+=mp[a[j][i]-a[j][i1]+10*N];
				mp[a[j][i]-a[j][i1]+10*N]++;
			}
			for(int j=0;j<=t;j++)
			{
				mp[q[j]+10*N]=0;
			}
			t=0;
		}
	}
	cout << ans;
	return 0;
}
