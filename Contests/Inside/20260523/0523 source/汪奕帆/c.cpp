#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,a[N],ans=0,dp[N][10];

signed main()
{
	freopen ("c.in","r",stdin);
	freopen ("c.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]>=6) ans=ans+a[i]/3-1,a[i]=a[i]%3+3;
	}
	/*for (int i=1;i<=n;i++)
	{
		if (a[i]>=1&&a[i-1]>=2) ans++,a[i]--,a[i-1]-=2;
		if (a[i]>=2&&a[i-1]>=1) ans++,a[i]-=2,a[i-1]--;
		if (a[i]>=2&&a[i+1]>=1) ans++,a[i+1]--,a[i]-=2;
		if (a[i]>=1&&a[i+1]>=2) ans++,a[i+1]-=2,a[i]--;
		if (a[i]>=3) ans++,a[i]-=3;
	}*/
	for (int i=2;i<=n;i++)
	{
		for (int j=a[i];j>=0;j--)
		{
			dp[i][j]=dp[i][j+1];
			int t=a[i]-j;
			for (int k=a[i-1];k>=0;k--)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][k]+(k+t)/3);
			}
			//printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	cout<<dp[n][0]+ans;
	return 0;
}
