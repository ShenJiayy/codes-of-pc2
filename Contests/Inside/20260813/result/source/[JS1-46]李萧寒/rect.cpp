#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int x[750005],y[750005],cnt[5000005],d[750005];
int ch(int a,int b){
	return a*(m+1)+b+1;
}
void iinit(){
	cin>>n>>m;
	if(n>m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x[ch(j,i)];
			}
		}
		swap(n,m);
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x[ch(i,j)];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			y[ch(i,j)]=y[ch(i-1,j)]+y[ch(i,j-1)]-y[ch(i-1,j-1)]+x[ch(i,j)];
		}
	}
}
signed main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	iinit();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=j-i+1;
			cnt[2500000]=1;
			for(int k=1;k<=m;k++){
				int sum=y[ch(j,k)]-y[ch(i-1,k)];
				int neeed=s*k-sum;
				ans+=cnt[neeed+2500000];
				cnt[2500000+neeed]++;
				d[k]=neeed+2500000;
			}
			for(int k=1;k<=m;k++){
				cnt[d[k]]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
