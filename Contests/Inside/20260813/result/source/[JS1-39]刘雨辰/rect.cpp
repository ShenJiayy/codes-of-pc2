#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("rect.in","r",stdin);
    freopen("rect.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10][m+10],s[n+10][m+10];
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int i2=i;i2<=n;i2++)
			{
				for(int j2=j;j2<=m;j2++)
				{
					int sum=s[i2][j2]-s[i-1][j2]-s[i2][j-1]+s[i-1][j-1];
					int sz=(i2-i+1)*(j2-j+1);
					if(sum==sz)ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

