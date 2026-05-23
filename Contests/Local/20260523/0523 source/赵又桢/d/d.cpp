#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[300010],q,x,y;
void solve(){
	cin>>x>>y;
	int cnt=1e9+10,ans=1e9+10;
	for(int i=0;cnt>=ans;++i){
		cnt=ans;
		ans=i*x;
		for(int j=1;j<=n;++j) ans+=max(0ll,a[j]-i*y);
	}
	cout<<cnt<<endl;
}
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>a[i];
	while(q--) solve();
	return 0;
}
