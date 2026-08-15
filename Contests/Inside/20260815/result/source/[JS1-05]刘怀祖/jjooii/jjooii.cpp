#include<bits/stdc++.h>
using namespace std;
const int N=3005,K=1005,inf=0x3fffffff;
int n,k,dp[N][N],ans=inf;
char s[N],st[N];
int main()
{
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",&s[1]);
	for(int i=1;i<=k;i++)
	{
		st[i]='J';
		st[i+k]='O';
		st[i+2*k]='I';
	}
	for(int i=0;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=inf;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3*k;j++)
		{
			if(s[i]!=st[j])dp[i][j]=dp[i-1][j]+1;
			else dp[i][j]=dp[i-1][j-1];
		}
		ans=min(ans,dp[i][3*k]);
	}
	if(ans==inf)printf("-1");
	else printf("%d",ans);
	return 0;
}
