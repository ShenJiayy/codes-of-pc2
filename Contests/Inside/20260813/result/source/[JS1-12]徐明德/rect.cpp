//rect
#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[510][510],sum[510][510];
int ans=0;
bool check(int sx,int sy,int ex,int ey){
	int cnt=0;
	cnt=sum[ex][ey]-sum[sx-1][ey]-sum[ex][sy-1]+sum[sx-1][sy-1];
	if(cnt==0)return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			--mp[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i][j]=mp[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				for(int p=j;p<=m;p++){
					if(check(i,j,k,p)){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
