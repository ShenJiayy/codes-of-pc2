// zoo
#include <bits/stdc++.h>
#define ll long long
#define ul unsigned long long
using namespace std;
const int MAXN=1e6+7;
int n,m,c,k,p,q,cnt,g;
ul t,o,ans,a[MAXN];
bool ok[MAXN];
signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>p>>q;
		t|=(1<<p);
		if(!ok[p]) g++;
		ok[p]=1;
	}
	for(int i=1;i<=n;i++) a[i]&=t;
	for(int i=0;i<=n;i++) o|=a[i];
	for(int i=0;i<k;i++) if(o&(1<<i)) cnt++;
	ans=(1<<(k-g+cnt))-n;
	cout<<ans<<endl;
	return 0;
}
