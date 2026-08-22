#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5,MAXM=1e6+1e5+5;
const long long MOD=998244353;
struct hyoli{
	int opt,p,v;
}op[MAXM];
vector<int> diao[MAXN];
int n,a[MAXN],m,cnt,c,q,f[MAXN];
long long s=1,add[MAXN];
void work(int x){
	if(op[x].opt==1){
		add[op[x].p]+=op[x].v*s%MOD;
		add[op[x].p]%=MOD;
	}
	else{
		s*=op[x].v;
		s%=MOD;
	}
	return ;
}
void solve(int x){
	if(op[x].opt==3){
		for(int i=diao[x].size()-1;i>=0;i--) solve(diao[x][i]);
	}
	else work(x);
	return ;
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&op[i].opt);
		if(op[i].opt==1){
			scanf("%d %d",&op[i].p,&op[i].v);
		}
		else if(op[i].opt==2){
			scanf("%d",&op[i].v);
		}
		else{
			scanf("%d",&c);
			for(int j=1;j<=c;j++){
				int x;
				scanf("%d",&x);
				diao[i].push_back(x);
			}
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&f[i]);
	}
	for(int i=q;i>=1;i--) solve(f[i]);
	for(int i=1;i<=n;i++){
		printf("%d ",(a[i]*s%MOD+add[i])%MOD);
	}
	return 0;
}
