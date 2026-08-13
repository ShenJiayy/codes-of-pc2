#include<bits/stdc++.h>
using namespace std;
const int N=35;
const int M=3e5+5;
int a[N][N],qzh[N][N],sum[M],b[M];
int n,m,ass;
map<int,int>p;
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n==1){
		for(int i=1;i<=m;i++){
			cin>>b[i];
			sum[i]=sum[i-1]+b[i];
		}
		for(int i=1;i<=m;i++){
			p[i-sum[i-1]-1]++;
			ass+=p[i-sum[i]];
		}cout<<ass;
		exit(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			a[i][j]-=1;
			qzh[i][j]=qzh[i-1][j]+qzh[i][j-1]-qzh[i-1][j-1]+a[i][j];
		}
	}int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				for(int u=j;u<=m;u++){
					if(qzh[k][u]-qzh[i-1][u]-qzh[k][j-1]+qzh[i-1][j-1]==0)ans++;
				}
			}
		}
	}cout<<ans; 
	return 0;
}
