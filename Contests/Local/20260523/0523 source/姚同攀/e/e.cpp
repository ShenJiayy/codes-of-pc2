#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,h[N];
bool vis[N][2];
struct EDGE{ int to,nxt;}e[N*2];
void build(int u,int v,int id){
	e[id].to=v;
	e[id].nxt=h[u];
	h[u]=id;
}
void dfs(int x,int step){
	vis[x][step%2]=1;
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(step%2&&x>=y) continue;
		if(step%2==0&&x<=y) continue;
		if(!vis[y][(step+1)%2]) dfs(y,step+1);
	}
}
int check(){
	int res=0;
	for(int i=1;i<=n;++i) 
		if(!vis[i][0]&&!vis[i][1]) ++res;
	return res; 
}
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v,i);
		build(v,u,i+m);
	}
	for(int i=1;i<=n;++i){
		memset(vis,false,sizeof(vis));
		dfs(i,1);
		printf("%d\n",check());
	}
	return 0;
} 
