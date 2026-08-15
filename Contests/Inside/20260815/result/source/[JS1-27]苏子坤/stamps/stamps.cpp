#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second 
using namespace std;
int n,l,ti,ans;
bool vis[205];
pii a[205];//fi->dist,se->time
void dfs(int sum,int pos,int t){
	if(t>ti){
		ans=max(ans,sum);
		return;
	}
	if(abs(a[pos+1].fi-a[pos].fi)+t<=a[pos+1].se&&!vis[pos+1]){
		vis[pos+1]=1;
		dfs(sum+1,pos+1,t+abs(a[pos+1].fi-a[pos].fi));
		vis[pos+1]=0;
	}
	if(pos==0||pos==1){
		if(a[pos].fi+l-a[n].fi+t<=a[n].se){
			vis[n]=1;
			dfs(sum+1,n,t+a[pos].fi+l-a[n].fi+t);
			vis[n=0];
		}
	}
	if(a[pos].fi-a[pos-1].fi+t<=a[pos-1].se){
		vis[pos-1]=1;
		dfs(sum+1,pos-1,a[pos].fi-a[pos-1].fi+t);
		vis[pos-1]=0;
	}
}
int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	cin>>n>>l;
	a[0]={0,0};
	for(int i=1;i<=n;i++)cin>>a[i].fi;
	for(int i=1;i<=n;i++){
		cin>>a[i].se;
		ti=max(ti,a[i].se);
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
