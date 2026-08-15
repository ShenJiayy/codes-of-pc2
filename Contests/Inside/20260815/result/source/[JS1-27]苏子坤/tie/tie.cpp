#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005],ans;
bool vis[200005];
void dfs(int nowp,int cnt){
	if(nowp>n){
		ans=min(cnt,ans);
		return;
	}
	for(int i=1;i<=n+1;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(nowp+1,max(cnt,max(a[i]-b[nowp],0)));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n+1;i++){
		memset(vis,0,sizeof vis);
		vis[i]=1;
		ans=2147483647;
		dfs(1,-1);
		cout<<ans<<" ";
	}
	return 0;
}
