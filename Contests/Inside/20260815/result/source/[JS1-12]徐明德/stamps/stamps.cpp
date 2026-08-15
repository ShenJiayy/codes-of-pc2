//stamps
#include<bits/stdc++.h>
const int N=210;
using namespace std;
struct sta{
	int x,t;
}bb[N];
int dp[N][N];//在顺时针第i个位置，当前时间为j(离散）
int tm[N][N][N];//在顺时针第i个位置，获得 
int n,l; 
vector<int>x;
int t;
int dis(int a,int b){
	//a=x[a-1];
	//b=x[b-1];
	return min(abs(a-b),abs(l-abs(a-b)));
}
int qwq[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>bb[i].x;
		//x.push_back(bb[i].x);
	}
	for(int i=1;i<=n;i++){
		cin>>bb[i].t;
		qwq[bb[i].x]=bb[i].t;
		t=max(t,bb[i].t);
		//t.push_back(bb[i].t);
	}
	if(l<=200){
		for(int i=1;i<=t;i++){
			dp[1][i]=max(dp[1][i],max(dp[l][i-1],dp[2][i-1]));
			if(qwq[1]==i)dp[1][i]++;
			dp[l][i]=max(dp[l][i],max(dp[l-1][i-1],dp[1][i-1]));
			if(qwq[l]==i)dp[l][i]++;
			for(int j=2;j<=l-1;j++){
				dp[j][i]=max(dp[j][i],max(dp[j-1][i-1],dp[j+1][i-1]));
				if(qwq[j]==i)dp[j][i]++;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i][t]);
		}
		cout<<ans;
		return 0;
	}
	/*sort(x.begin(),x.end());
	//sort(t.begin(),t.end());
	x.erase(unique(x.begin(),x.end),x.end());
	//t.erase(unique(t.begin(),t.end),t.end());
	for(int i=1;i<=n;i++){
		bb[i].x=lower_bound(x.begin(),x.end(),bb[i].x)-x.begin()+1;
		bb[i].t=lower_bound(t.begin(),t.end(),bb[i].t)-t.begin()+1;
	}*/
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][0]=0;
	for(int i=0;i<=t;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int p=0;p<i&&p+dis(j,k)<=i;p++){
					if(bb[j].t<p+dis(j,k))dp[j][i]=max(dp[j][i],dp[k][p]);
					else if(bb[j].t==p+dis(j,k)){
						dp[j][i]=max(dp[j][i],dp[k][p]+1);
					}
				} 
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i][t]);
	}
	cout<<ans;
	return 0;
} 
