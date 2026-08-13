#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m,ans,a[35][35],sum[35][35],b[250005],sum2[250005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	if(n<=30&&m<=30){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int x=i;x<=n;x++){
					for(int y=j;y<=m;y++){
						if((x-i+1)*(y-j+1)==sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1])ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	if(n==1){
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		int ans=0,l=1,r=1,num=b[1];
		while(l<=n&&r<=n){
			if(num==r-l+1)ans++;
			if(num>r-l+1){
				l++;
				num-=b[l-1];
			}
			if(num<r-l+1){
				r++;
				num+=b[r];
			}
		}
		cout<<ans;
	}
	return 0;
}
