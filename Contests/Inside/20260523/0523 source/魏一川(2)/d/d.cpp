#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[300005],c,d;
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	while(q--){
		scanf("%lld%lld",&c,&d); 
		int sum=0,ans=LLONG_MAX;
		for(int k=0;;k++){
			for(int i=1;i<=n;i++)if(a[i]-d*k>0)sum+=a[i]-d*k;
			sum+=c*k;
			if(sum<ans)ans=sum,sum=0;
			else break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
