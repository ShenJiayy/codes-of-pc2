#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005],x[5005],ma[5005][5005];
int main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		dp[i][i]=0,ma[i][i]=i;
	}
	for(int len=2;len<=n;len++){
		for(int j=1;j+len-1<=n;j++){
			int l=j,r=j+len-1;
			if(x[ma[l][r-1]]<x[r]){
				ma[l][r]=ma[l][r-1];
			}
			else{
				ma[l][r]=r;
			}
		}
	}
	for(int len=2;len<=n;len++){
		for(int j=1;j+len-1<=n;j++){
			int l=j,r=j+len-1;
			dp[l][r]=max(ma[l][r]-ma[l][ma[l][r]-1]+dp[l][ma[l][r]-1],ma[ma[l][r]+1][r]-ma[l][r]+dp[ma[l][r]+1][r]);
		}
	}
	cout<<dp[1][n];
	return 0;
}
