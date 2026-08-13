#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
const int N=2750010;
int n,m;
ll ans,cnt[N*2];
vector<ll> a[250010],sum[250010];
int main(){
    freopen("rect.in","r",stdin);
    freopen("rect.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	a[i].push_back(0);
    	for(int j=1;j<=m;j++){
    		int x;
    		scanf("%d",&x);
    		a[i].push_back(x-1);
		}
	}
	for(int i=1;i<=m;i++){
		sum[0].push_back(0);
	}
	for(int i=1;i<=n;i++){
		sum[i].push_back(0);
		for(int j=1;j<=m;j++){
			sum[i].push_back(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]);
			//cout<<sum[i][j]<<" ";
		}
		//cout<<"\n";
	}
    if(n>m){
		for(int x1=1;x1<=m;x1++){
			for(int x2=0;x2<x1;x2++){
				for(int x=0;x<=n;x++){
					ans+=cnt[sum[x][x1]-sum[x][x2]+N];
					cnt[sum[x][x1]-sum[x][x2]+N]++;
				}
				for(int x=0;x<=n;x++){
					cnt[sum[x][x1]-sum[x][x2]+N]--;
				}
			}
		}
	} 
	else{
		for(int x1=1;x1<=n;x1++){
			for(int x2=0;x2<x1;x2++){
				for(int x=0;x<=m;x++){
					ans+=cnt[sum[x1][x]-sum[x2][x]+N];
					cnt[sum[x1][x]-sum[x2][x]+N]++;
				}
				for(int x=0;x<=m;x++){
					cnt[sum[x1][x]-sum[x2][x]+N]--;
				}
			}
		}
	} 
	printf("%lld",ans);
    I AK IOI;
} 