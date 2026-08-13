#include<bits/stdc++.h>
using namespace std;
#define int long long
#define c(i,j) (i-1)*m+j
int n,m,a[250030],dp[250020];
void sv1(){
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=i;k<=n;k++){
				for (int l=j;l<=m;l++){
					int sum=0,siz=0;
					for (int o=i;o<=k;o++){
						sum+=dp[c(i,l)]-dp[c(i,j-1)];
						siz+=(l-j+1);
					}
					ans+=(siz==sum);
				}
			}
		}
	}
	cout<<ans<<"\n";
}
void sv2(){

}
signed main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[c(i,j)];
			dp[c(i,j)]=dp[c(i,j-1)]+a[c(i,j)];
		}
	}
	sv1();
	return 0;
}
