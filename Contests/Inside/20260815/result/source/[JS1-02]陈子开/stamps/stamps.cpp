#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=405;
int n,l;
int p[N],t[N];
//p是坐标，t是时间 
int dp[N][N][2];//走完的时间 
int f[N][N][2];//走完的价值 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout); 
	cin>>n>>l;
	for(int i=1;i<=n;i++) {
		int tmp;
		cin>>tmp;
		p[i+n+1]=tmp;
		p[i]=-(l-tmp);
		dp[i][i][0]=dp[i][i][1]=abs(p[i]);
		dp[i+n+1][i+n+1][0]=dp[i+n+1][i+n+1][1]=abs(p[i+n+1]);
	}
	for(int i=1;i<=n;i++) {
		int tmp;
		cin>>tmp;
		t[i+n+1]=t[i]=tmp;
		if(dp[i][i][0]<=tmp) f[i][i][0]=f[i][i][1]=1;
		if(dp[i+n+1][i+n+1][0]<=tmp) f[i+n+1][i+n+1][0]=f[i+n+1][i+n+1][1]=1;
	}
	t[0]=2e9+5;
	for(int len=2;len<=n+1;len++) {
		for(int i=1;i+len-1<=2*n+1;i++) {
			int j=i+len-1;
			int u,v;
			//最后停在i
			u=dp[i+1][j][0]+p[i+1]-p[i];
			v=dp[i+1][j][1]+p[j]-p[i];
			if(u<=t[i]) {
				f[i][j][0]=f[i+1][j][0]+1;
			}
			else {
				f[i][j][0]=f[i+1][j][0];
			}
			if(v<=t[i]) {
				f[i][j][0]=max(f[i][j][0],f[i+1][j][1]+1);
			}
			else {
				f[i][j][0]=max(f[i][j][0],f[i+1][j][1]);
			}
			dp[i][j][0]=min(u,v);
			//最后停在j 
			u=dp[i][j-1][1]+p[j]-p[j-1];
			v=dp[i][j-1][0]+p[j]-p[i];
			if(u<=t[j]) {
				f[i][j][1]=f[i+1][j][1]+1;
			}
			else {
				f[i][j][1]=f[i+1][j][1];
			}
			if(v<=t[j]) {
				f[i][j][1]=max(f[i][j][1],f[i+1][j][0]+1);
			}
			else {
				f[i][j][1]=max(f[i][j][1],f[i+1][j][0]);
			}
			dp[i][j][1]=min(u,v);
		}
	}
	int ans=0;
	ans=max(f[1][n+1][0],f[n+1][n*2+1][1]);
	cout<<min(n,ans);
	return 0;
}

