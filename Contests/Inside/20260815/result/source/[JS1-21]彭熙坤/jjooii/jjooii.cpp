#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int dp[MAXN][4],n,k,to[MAXN],st=1;
int p[4][MAXN],cnt[4];
char s[MAXN];
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	memset(dp,0x3f3f3f3f,sizeof(dp));
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	while(s[st]!='J') st++;
	for(int i=st;i<=n;i++){
		if(s[i]=='J'){
			p[1][++cnt[1]]=i;
			if(cnt[1]>=k) to[p[1][cnt[1]-k+1]]=i;
		}
		if(s[i]=='O'){
			p[2][++cnt[2]]=i;
			if(cnt[2]>=k) to[p[2][cnt[2]-k+1]]=i;
		}
		if(s[i]=='I'){
			cnt[3]++;
			p[3][cnt[3]]=i;
			if(cnt[3]>=k) to[p[3][cnt[3]-k+1]]=i;
		}
	}
	dp[st-1][0]=0;
	for(int i=st;i<=n;i++){
		dp[i][0]=min(dp[i][0],dp[i-1][0]);
		dp[i][1]=min(dp[i][1],dp[i-1][1]+1);
		dp[i][2]=min(dp[i][2],dp[i-1][2]+1);
		if(to[i]!=0){
			if(s[i]=='J') dp[to[i]][1]=min(dp[to[i]][1],dp[i-1][0]+to[i]-i+1-k);
			if(s[i]=='O') dp[to[i]][2]=min(dp[to[i]][2],dp[i-1][1]+to[i]-i+1-k);
			if(s[i]=='I') dp[to[i]][3]=min(dp[to[i]][3],dp[i-1][2]+to[i]-i+1-k);
		}
	}
	int ans=2147483647;
	for(int i=st;i<=n;i++) ans=min(ans,dp[i][3]);
	if(ans>2e5+5) printf("-1");
	else printf("%d",ans);
	return 0;
}
