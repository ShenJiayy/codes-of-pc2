#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
int a[N],n,q,x,y,ans,sum[N];
int get(int t){
	int p=t*y;
	int pos=upper_bound(a+1,a+n+1,p)-a;
	return sum[n]-sum[pos-1]-(n-pos+1)*p+x*t;
}
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	while(q--){
		scanf("%lld%lld",&x,&y);
		int r=a[n]/y+1,l=0,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int z=get(mid);
			if(z<get(mid-1)) l=mid+1,ans=z;
			else r=mid-1;
		}
		if(ans==0) ans=sum[n];
		printf("%lld\n",ans);
	}
	return 0;
}


