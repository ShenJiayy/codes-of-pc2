// interval
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
const int INF=0x3f3f3f3f;
struct node{
	int l,r;
}w[MAXN];
int n,m,ans=INF;
int h[MAXN];
bool use[MAXN];
void solve(){
	bool flag=1;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			int id=h[i];
			int idx=h[j];
			int l1=w[id].l;
			int r1=w[id].r;
			int l2=w[idx].l;
			int r2=w[idx].r;
			int maxl=max(l1,l2);
			int minr=min(r1,r2);
			if(maxl<=minr) continue;
			flag=0;
			break;
		}
	}
	if(flag){
		int a=-1,b=INF;
		for(int i=1;i<=m;i++){
			int id=h[i];
			int l0=w[id].l;
			int r0=w[id].r;
			int tmp=r0-l0;
			a=max(a,tmp);
			b=min(b,tmp);
		}
		ans=min(ans,a-b);
	}
	return;
}
void dfs(int x){
	if(x>m){
		solve();
		return;
	}
	for(int i=1;i<=n;i++){
		if(use[i]) continue;
		use[i]=1;
		h[x]=i;
		dfs(x+1);
		use[i]=0;
		h[x]=0;
	}
	return;
}
signed main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i].l>>w[i].r;
	if(m>n){
		cout<<-1<<endl;
		return 0;
	}
	dfs(1);
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
