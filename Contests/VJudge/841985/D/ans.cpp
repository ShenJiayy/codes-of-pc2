#include<bits/stdc++.h>
using namespace std;
int Abs(int x){return x>0?x:-x;}
int dp[305][305][2],n,m,a[305],ans;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int N=1;N<=n;++N)
	{
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;++i)
			dp[i][i][0]=dp[i][i][1]=m-Abs(a[i])*N,
			ans=max(ans,dp[i][i][0]);
		for(int dis=2;dis<=N;++dis)
		{
			for(int l=1,r=dis;r<=n;++l,++r)
			{
				dp[l][r][0]=max(
					dp[l+1][r][0]+m-Abs(a[l+1]-a[l])*(N-dis+1),
					dp[l+1][r][1]+m-Abs(a[r]-a[l])*(N-dis+1));
				dp[l][r][1]=max(dp[l][r-1][1]+m-Abs(a[r]-a[r-1])*(N-dis+1),dp[l][r-1][0]+m-Abs(a[r]-a[l])*(N-dis+1));
				ans=max(ans,max(dp[l][r][0],dp[l][r][1]));
			}
		}
	}
	printf("%d",ans);
	return 0;
}
