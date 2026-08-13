#include<bits/stdc++.h>
using namespace std;
const int N=35;
int n,m;
int ans;
int sum[N][N];
int find(int x,int y) {
	int res=0;
	for(int i=1;i<=x;i++) {
		for(int j=1;j<=y;j++) {
			int s=(x-i+1)*(y-j+1);
			if(sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1]==s)
				res++;
		}
	}
	return res;
}
void solve1() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			int t;
			cin>>t;
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			ans+=find(i,j);
		}
	}
	cout<<ans;
	return ;
}
int dp[22][250002];
void solve2() {
	for(int i=1;i<=m;i++) {
		int t;
		cin>>t;
		t--;
		dp[t+11][i]=1;
		for(int j=0;j<=20;j++) {
			if(j+t>0&&j+t<=20)
				dp[j+t][i]+=dp[j][i-1];
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		ans+=dp[11][i];
	cout<<ans;
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	if(n==1) {
		solve2();
		return 0;
	}
	solve1();
	return 0;
}

