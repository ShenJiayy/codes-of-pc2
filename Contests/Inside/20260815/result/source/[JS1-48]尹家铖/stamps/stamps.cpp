#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,n,ans,vis[205],dis[205][205];
struct node{int t,x;}a[205];
bool cmp(node x,node y){return x.x<y.x;}
void dfs(int now,int k,int tim){
	ans=max(ans,k);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(tim+dis[now][i]>a[i].t) continue;
		vis[i]=1;
		dfs(i,k+1,tim+dis[now][i]);
		vis[i]=0;
	}
}
signed main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].t);
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++){
			dis[i][j]=min(abs(a[i].x-a[j].x),l-max(a[i].x,a[j].x)+min(a[i].x,a[j].x));
		}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
