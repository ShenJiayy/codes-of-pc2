#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300020;
int n,q,c,d,a[N],sum[N],mx=0,p,mi=LONG_LONG_MAX;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	sort(a+1,a+1+n); 
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	while(q--){
		int ans=sum[n];
		cin>>c>>d;
		for (int i=mi/d;(i-1)*d<=mx;i++) {
			p=(upper_bound(a+1,a+1+n,i*d)-a-1);
			ans=min(ans,sum[n]-sum[p]-(n-p)*d*i+i*c);
		} 
		cout<<ans<<"\n";
	}
	return 0;
} 
