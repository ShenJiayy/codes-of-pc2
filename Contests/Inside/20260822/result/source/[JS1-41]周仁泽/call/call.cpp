// call
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e3+7;
struct node{
	int type,p,v;
	int c,d[MAXN];
}f[MAXN];
int n,m,q,id,a[MAXN];
void dfs(int x){
	if(f[x].type==1){
		a[f[x].p]+=f[x].v;
		return;
	}
	else if(f[x].type==2){
		for(int i=1;i<=n;i++) a[i]*=f[x].v;
		return;
	}
	else if(f[x].type==3){
		for(int i=1;i<=f[x].c;i++)
		dfs(f[x].d[i]);
		return;
	}
}
signed main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>f[i].type;
		if(f[i].type==1) cin>>f[i].p>>f[i].v;
		if(f[i].type==2) cin>>f[i].v;
		if(f[i].type==3){
			cin>>f[i].c;
			for(int j=1;j<=f[i].c;j++) cin>>f[i].d[j];
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>id;
		dfs(id);
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
