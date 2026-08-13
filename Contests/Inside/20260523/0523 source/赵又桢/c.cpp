#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b,ans;
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>a;
	for(int i=2;i<=n;++i){
		cin>>b;
		if(a+b<3){
			a=b;
			continue;
		}
		ans+=(a+b)/3;
		a=(a+b)%3;
	}
	cout<<ans+a/3;
	return 0;
}
