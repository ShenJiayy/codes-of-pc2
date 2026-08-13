#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
ll n,q,a[300010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
	}	
	while(q--){
		int c,d;
		cin>>c>>d;
		ll ans=1e17;
		bool f=0;
		for(int i=0;i<=maxn/d+1;i++){
			ll t=i*d,tmp=i*c;
			for(int j=1;j<=n;j++){
				tmp+=max(0ll,a[j]-d*i);
			}
			if(tmp>=ans){
				cout<<ans<<"\n";
				f=1;
				break;
			}
			else ans=tmp;
		}
		if(!f) cout<<ans<<"\n";
	}
	I AK IOI;
}
//[0,17]
