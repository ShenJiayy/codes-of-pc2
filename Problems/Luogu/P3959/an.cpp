#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int M=(1<<12),inf=0x3f3f3f3f;
int cost[M][M],n,m,c[12][12];
long long dp[12][M],ans=inf;
void init(){
	for(int i=1;i<(1<<n);i++){
		for(int j=i;j;j=(j-1)&i){
			if(j==i)continue;
			for(int t=0,tmp;t<n;t++,tmp=inf){
				if(!(((i^j)>>t)&1))continue;
				for(int l=0;l<n;l++)if((j>>l)&1)tmp=min(tmp,c[l][t]);
				if(tmp>=inf){cost[j][i]=inf;break;}
                else cost[j][i]+=tmp;
			}
		}
	}
	return;
}
long long DP(int x){
    for(int i=0;i<12;i++)for(int j=0;j<M;j++)dp[i][j]=inf;//dp值取min,所以先清空
	dp[0][1<<x]=0;
	long long res=inf;
	for(int i=1;i<n;i++){
		for(int j=1;j<(1<<n);j++){
			for(int k=j;k;k=(k-1)&j){//枚举前i-1层的k和第i层的j
				if(k==j)continue;
				dp[i][j]=min(dp[i][j],dp[i-1][k]+1ll*i*cost[k][j]);
			}
			if(j==(1<<n)-1)res=min(res,dp[i][j]);
		}
	}
	return res;
}
int main(){
	scanf("%d %d",&n,&m);
	if(n==1){
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)c[i][j]=inf;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w),u--,v--;
		c[v][u]=c[u][v]=min(c[u][v],w);
	}
	init();
	for(int i=0;i<n;i++)ans=min(ans,DP(i));
    // for (int i = 0; i < (1 << n); i ++)
    //     for (int j = 0; j < (1 << n); j ++)
    //         cout << cost[i][j] << " ";
    // for (int i = 0; i < n; i ++)
    //     for (int j = 0; j < (1 << n); j ++)
    //         cout << dp[i][j] << " ";
	printf("%lld\n",ans);
	return 0;
}
