#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[600010],siz[600010];
stack<int> son[600010];
int getf(int u){
	if(u==fa[u]){
		return u;
	}
	return fa[u]=getf(fa[u]);
}
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
		son[i].push(i);
	}
}
void unite(int u,int v){
	u=getf(u);
	v=getf(v);
	if(u==v){
		return;
	}
	if(siz[u]>siz[v]){
		swap(u,v);
	}
	siz[v]+=siz[u];
	siz[u]=0;
	fa[u]=v;
	while(!son[u].empty()){
		son[v].push(son[u].top());
		son[u].pop();
	}
}
int t[300010],ans[300010],cnt;
stack<int> tmmp;
signed main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	scanf("%d%d",&n,&m);
	init(n*2+1);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		unite(u*2+1,v*2);
	}
	for(int i=2;i<=n*2+1;i++){
		if(siz[i]==0){
			continue;
		}
		while(!son[i].empty()){
			t[son[i].top()/2]++;
			if(t[son[i].top()/2]==1){
				cnt++;
			}
			tmmp.push(son[i].top());
			son[i].pop();
		}
		while(!tmmp.empty()){
			int topx=tmmp.top();
			if(topx%2==1){
				ans[topx/2]=n-cnt;
			}
			t[topx/2]=0;
			tmmp.pop();
		}
		cnt=0;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
