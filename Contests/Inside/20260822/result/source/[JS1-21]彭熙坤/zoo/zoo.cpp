#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+5;
int n,m,c,k,a[MAXN],sa,cnt;
bool t[100];
signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sa|=a[i];
	}
	for(int i=1;i<=m;i++){
		int p,q;
		scanf("%lld %lld",&p,&q);
		t[p+1]=true;
	}
	for(int i=1;i<=k;i++){
		if(sa&1) cnt++;
		else if(!t[i]) cnt++;
		sa>>=1;
	}
	printf("%lld",(1<<cnt)-n);
	return 0;
}
