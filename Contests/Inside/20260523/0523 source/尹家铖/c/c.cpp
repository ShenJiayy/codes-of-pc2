#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],ans,dp[200005];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld",&n);
	if(n==1){
		scanf("%lld",&a[1]);
		printf("%lld",a[1]/3);
		return 0;
	}
	if(n==2){
		scanf("%lld%lld",&a[1],&a[2]);
		printf("%lld",a[1]/3+(a[2]+a[1]%3)/3);
		return 0;
	}
	int flg1=1,flg2=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]%3ll!=0) flg1=0;
		if(a[i]!=2) flg2=0;
	}
	if(flg1){
		for(int i=1;i<=n;i++) ans+=a[i]/3;
		printf("%lld",ans);
		return 0;
	}
	if(flg2){
		for(int i=1;i<=n/3;i++) ans+=2;
		printf("%lld",ans);
		return 0;
	}
	return 0;
} 
