#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[100005],q;
int t[100005],p[100005],v[100005];
vector<int>c[100005];
void han(int x){
	if(t[x]==1)
		a[p[x]]=(a[p[x]]+v[x])%mod;
	else if(t[x]==2){
		for(int i=1;i<=n;i++)
			a[i]=a[i]*v[x]%mod;
	}
	else{
		for(int i=0;i<c[x].size();i++)
			han(c[x][i]);
	}
}
signed main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++){
		scanf("%lld",&t[i]);
		if(t[i]==1) scanf("%lld%lld",&p[i],&v[i]);
		if(t[i]==2) scanf("%lld",&v[i]);
		if(t[i]==3){
			int cj,g;scanf("%d",&cj);
			for(int j=1;j<=cj;j++){
				scanf("%d",&g);
				c[i].push_back(g);
			}	
		}
	}
	scanf("%d",&q);int x;
	while(q--){
		scanf("%d",&x);han(x);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
