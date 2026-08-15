#include<bits/stdc++.h>
using namespace std;
const int MAXN=205*2;
int n,txl;
int x[MAXN],t[MAXN],dp[MAXN][MAXN][2],ans,mint[MAXN][MAXN][2],s[MAXN];
int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	scanf("%d %d",&n,&txl);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	s[n+1]=txl;
	for(int i=n+1;i>=1;i--){
		x[i]=s[i]-s[i-1];
		x[i+n+1]=x[i];
	}
	for(int i=n+2;i<=n*2+2;i++) s[i]=s[i-1]+x[i];
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		t[i+n+1]=t[i];
	}
	for(int i=1;i<=n+1;i++){
		memset(dp,0,sizeof(dp));
		memset(mint,0x3f3f3f3f,sizeof(mint));
		int L=i-1,R=i+n-1;
		int st=n+1;
		if(i==1) st=0;
		mint[st][st][0]=mint[st][st][1]=0;
		for(int len=2;len<=n+1;len++){
			int ll=max(L,st-len+1),rr=min(R,st+len-1);
			for(int j=ll;j+len-1<=rr;j++){
				int l=j,r=j+len-1;
				int upd1=dp[l][r-1][0]+((mint[l][r-1][0]+s[r]-s[l])<=t[r]),upd2=dp[l+1][r][0]+((mint[l+1][r][0]+x[l+1])<=t[l]);
				int upd3=dp[l][r-1][1]+((mint[l][r-1][1]+x[r])<=t[r]),upd4=dp[l+1][r][1]+((mint[l+1][r][1]+s[r]-s[l])<=t[l]);
				if(dp[l][r][1]<=upd1){
					dp[l][r][1]=upd1;
					mint[l][r][1]=min(mint[l][r][1],mint[l][r-1][0]+s[r]-s[l]);
				}
				if(dp[l][r][0]<=upd2){
					dp[l][r][0]=upd2;
					mint[l][r][0]=min(mint[l][r][0],mint[l+1][r][0]+x[l+1]);
				}
				if(dp[l][r][1]<=upd3){
					dp[l][r][1]=upd3;
					mint[l][r][1]=min(mint[l][r][1],mint[l][r-1][1]+x[r]);
				}
				if(dp[l][r][0]<=upd4){
					dp[l][r][0]=upd4;
					mint[l][r][0]=min(mint[l][r][0],mint[l+1][r][1]+s[r]-s[l]);
				}
			}
		}
		ans=max(ans,max(dp[L][R][0],dp[L][R][1]));
	}
	printf("%d",ans);
	return 0;
}
