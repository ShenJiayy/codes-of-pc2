#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long ll;
int n,Q;
ll a[N],c[N],d[N],sum[N],ans;
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(int _=1;_<=Q;++_){
		scanf("%d%d",&c[_],&d[_]);
		ans=sum[n];
		for(ll k=1;1;++k){
			ll res=0;
			for(int i=1;i<=n;++i) res+=max(0ll,a[i]-k*d[_]);
			res+=k*c[_];
			if(res>=ans) break;
			ans=res;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
