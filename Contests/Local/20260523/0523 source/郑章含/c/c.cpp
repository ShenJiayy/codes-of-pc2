#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans;
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++){
		if(a[i]%3==0){
			continue;
		}
		if(a[i]%3==1){
			if(a[i+1]>=2){
				a[i]-=1;
				a[i+1]-=2;
				ans++;
			}
		}
		if(a[i]%3==2){
			if(a[i+1]>=1){
				a[i]-=2;
				a[i+1]-=1;
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=a[i]/3; 
	}
	printf("%lld",ans);
	return 0;
}
