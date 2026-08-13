#include <bits/stdc++.h>
using namespace std;
int n,q,c,d;
long long a[300004];
long long sum[300004];
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	while(q--){
		cin>>c>>d;
		int l=1,r=(a[n]+d-1)/d,ans=sum[n];
		while(l<=r){
			int mid=(l+r)/2;
			int t=mid-1;
			int ll=0,rr=n;
			int u;
			while(ll<=rr){
				int mmid=(ll+rr)/2;
				if(a[mmid]>=d*t){
					u=mmid;
					rr=mmid-1;
				}
				else ll=mmid+1;
			}
			ll=u,rr=n;
			int v;
			while(ll<=rr){
				int mmid=(ll+rr)/2;
				if(a[mmid]<=d*mid){
					v=mmid;
					ll=mmid+1;
				}
				else rr=mmid-1;
			}
			int x=d*(v-u+1)-(d*(v-u+1)*mid-(sum[v]-sum[u-1]));
			int y=(n-v)*d;
			int z=x+y;
			//cout<<c<<" "<<d<<" "<<t<<" "<<mid<<" "<<u<<" "<<v<<endl;
			if(z<c){
				r=mid-1;
			}
			else{	
				l=mid+1;
				ans=c*mid+sum[n]-sum[v]-mid*d*(n-v);
				//cout<<ans<<" ";
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
