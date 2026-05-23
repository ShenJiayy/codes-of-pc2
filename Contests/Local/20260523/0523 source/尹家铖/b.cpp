#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
int m[500005],sum[500005];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m[i]++;
	}
	sort(a+1,a+n+1);
	int pre=a[0];
	for(int i=1;i<=n;i++){
		if(a[i-1]==a[i]) {
			sum[i]=sum[i-1];
		}
		sum[i]=sum[i-1]+m[i];
	}
	int minn=1e9,mini=0;
	for(int i=1;i<=n;i++){
		if(pre==a[i]) continue;
		int k=2*sum[i-1]-n;
		if(k<0) k=-k;
		if(k<=minn){
			minn=k;
			mini=a[i];
		}
		pre=a[i];
	}
	printf("%d",mini);
	return 0;
} 
