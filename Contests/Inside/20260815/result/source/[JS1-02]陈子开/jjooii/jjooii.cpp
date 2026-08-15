#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
string s;
int n,k;
int dp[3][70005];
int ans=INF;
int lstj=-1,lsto=-1,lsti=-1;
int maxj,maxo,maxi;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout); 
	cin>>n>>k;
	cin>>s;
	s=" "+s;
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++) {
		if(s[i]=='J') {
			maxj++;
			for(int j=min(k,maxj);j>1;j--) {
				dp[0][j]=dp[0][j-1]+i-lstj-1;
			}
			dp[0][1]=0;
			lstj=i;
//			for(int l=1;l<=k;l++) {
//				cout<<dp[0][l]<<' ';
//			}
		}
		else if(s[i]=='O'&&maxj>=k) {
			maxo++;
			for(int j=min(k,maxo);j>1;j--) {
				dp[1][j]=dp[1][j-1]+i-lsto-1;
			}
			dp[1][1]=dp[0][k]+i-lstj-1;
			lsto=i;
//			for(int l=1;l<=k;l++) {
//				cout<<dp[1][l]<<' ';
//			}
		}
		else if(s[i]=='I'&&maxo>=k) {
			maxi++;
			for(int j=min(k,maxi);j>1;j--) {
				dp[2][j]=dp[2][j-1]+i-lsti-1;
			}
			dp[2][1]=dp[1][k]+i-lsto-1;
			lsti=i;
			ans=min(ans,dp[2][k]);
//			for(int l=1;l<=k;l++) {
//				cout<<dp[2][l]<<' ';
//			}
		}
//		else {
//			for(int l=1;l<=k;l++) {
//				cout<<-2<<' ';
//			}
//		}
//		cout<<'\n';
	}
	if(ans==INF) cout<<-1;
	else cout<<ans;
	return 0;
}

