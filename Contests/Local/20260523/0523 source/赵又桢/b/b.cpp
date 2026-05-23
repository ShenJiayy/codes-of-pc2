#include <bits/stdc++.h>
using namespace std;
int n,a[500010],ans,l=1e9+10;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=1;j<=n;++j) if(a[j]>=a[i]) cnt++;
		if(l==abs(cnt-(n-cnt))) if(ans<a[i]) ans=a[i];
		if(l>abs(cnt-(n-cnt))){
			l=abs(cnt-(n-cnt));
			ans=a[i];
		}
	}
	cout<<ans;
	return 0;
}
