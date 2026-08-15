#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],b[200010],q,f=1,c[200010],qma[200010],hma[200010];
map < int , int > m,ans;
signed main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;++i){
		cin>>a[i];
		c[i]=a[i];
		m[c[i]]=i;
	}
	for(int i=1;i<=n;++i) cin>>b[i];
	sort(c+1,c+n+2);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		qma[i]=max(c[i]-b[i],qma[i-1]);
		ans[m[c[i]]]=i;
	}
	ans[m[c[n+1]]]=n+1;
	for(int i=n;i>=1;--i) hma[i]=max(c[i+1]-b[i],hma[i+1]);
	for(int i=1;i<=n+1;++i){cout<<max(qma[ans[i]-1],hma[ans[i]])<<" ";}
	return 0;
}
