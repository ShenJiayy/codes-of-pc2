#include<bits/stdc++.h>
using namespace std;
int n,ans=0,f=1;
struct p{
	int x,e;
} a[500020];
int vis[500020],x[500020];
bool cmp(p a,p b){
	return a.e>b.e;
}
bool cmmp(p a,p b){
	return a.x<b.x;
}
void dfs(int now){
	if (vis[now]==1) return ;
	vis[now]=1;
	for (int i=now;i<=n;i++){
		if (vis[i]==1) continue;
		if (abs(a[now].x-a[i].x)<=a[now].e-a[i].e) dfs(i);
	}
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].e;
		x[i]=a[i].x;
		if (a[i].e!=a[1].e) f=0;
	}
	if (f){
		sort(x+1,x+1+n);
		cout<<unique(x+1,x+1+n)-x-1<<"\n";
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		dfs(i);
		ans++;
	}
	cout<<ans;
	return 0;
}
