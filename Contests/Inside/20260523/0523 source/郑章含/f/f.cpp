#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[3510];
void solve0(){
	int ans=a[1+n/2]-a[1];
	for(int i=1;i*2<=n;i++){
		ans=min(ans,a[i+n/2]-a[i]);
	}
	printf("%lld",ans); 
}
int solve1Sub(int x,int y,int z){
	int res=1000000000;
	if(n==3){
		return res;
	}
	int t=(n-3)/2,tag=0;
	int arr[3510];
	for(int i=1;i<=n;i++){
		if(i==x||i==y||i==z){
			tag++;
			continue;
		}
		arr[i-tag]=a[i];
	}
	for(int i=1;i*2<=n-3;i++){
		res=min(res,arr[i+(n-3)/2]-arr[i]);
	}
	return res;
}
void solve1(){
	int ans=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j]-a[i]!=a[k]-a[j]){
					continue;
				}
				int res=solve1Sub(i,j,k);
//				printf("<%d %d %d %d>",i,j,k,res);
				ans=max(ans,min(res,a[j]-a[i]));
			}
		}
	}
	if(ans==0){
		printf("-1");
	}
	else{
		printf("%lld",ans);
	}
} 
void solveA(){
	printf("%lld",n/2);
}
signed main(){
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	scanf("%lld",&n);
	int flag=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i){
			flag=0;
		}
	}
	if(n%2==0){
		solve0();
	}
	else if(flag){
		solveA();
	}
	else{
		solve1();
	}
	return 0;
}
