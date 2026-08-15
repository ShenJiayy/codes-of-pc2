// stamps
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e2+7;
int n,l,ans;
int x[MAXN],t[MAXN];
bool use[MAXN];
void dfs(int tim,int num,int now){
	ans=max(ans,num);
	for(int i=1;i<=n;i++){
		if(use[i]) continue;
		int len=abs(now-x[i]);
		int time=min(len,l-len)+tim;
		if(time<=t[i]){
			use[i]=1;
			dfs(time,num+1,x[i]);
			use[i]=0;
		}
	}
	return;
}
signed main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	cin>>n>>l;
	for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) cin>>t[i];
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
