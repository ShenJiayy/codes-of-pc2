#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,b[25],vis[25],v[1005],ans=INT_MAX;
struct node{
	int x,e;
}a[N];
bool cmp(node a,node b){
	return a.e>b.e;
}
set<pair<int,int> > s;
void dfs(int k){
	if(k==n+1){
		int res=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(b[i]){
				res++;
				vis[i]=1;
				for(int j=i-1;j>=1;j--) if(abs(a[i].x-a[j].x)<=a[i].e-a[j].e) vis[j]=1;
				for(int j=i+1;j<=n;j++) if(abs(a[i].x-a[j].x)<=a[i].e-a[j].e) vis[j]=1;
			}
		}
		for(int i=1;i<=n;i++) if(!vis[i]) return;
		ans=min(ans,res);
		return;
	}
	b[k]=1;
	dfs(k+1);
	b[k]=0;
	b[k]=0;
	dfs(k+1);
	b[k]=0;
}
signed main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].e;
	if(n<=16){
		dfs(1);
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++) s.insert({a[i].x,a[i].e});
		cout<<s.size();
	}
	return 0;
}
