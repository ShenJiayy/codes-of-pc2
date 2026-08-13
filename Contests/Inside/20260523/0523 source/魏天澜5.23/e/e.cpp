#include<bits/stdc++.h>
using namespace std;
const int N = 600060;
vector<int>e[N];
int n,m;
int fa[N];
int sz[N];
bool vis[N];
int find(int x){
	if(fa[x]!=x)fa[x] = find(fa[x]);
	return fa[x];
}
void dfs(int u){
	vis[u] = 1;
	sz[find(u)]++;
	for(auto v:e[u]){
		if(!vis[v])dfs(v);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=2*n;i++)fa[i] = i;
	for(int i = 1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v+n);
		e[v+n].push_back(u);
		int ru = find(u);
		int rv = find(v+n);
		if(ru==rv)continue;
		if(rv>ru)swap(rv,ru);
		fa[ru] = rv;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i])dfs(i);
	}
	for(int i = 1;i<=n;i++){
		if(find(i)==find(n+i))sz[find(i)]--;
	}
	for(int i = 1;i<=n;i++){
		cout<<n-sz[find(i)]<<"\n";
	}
	return 0;
}
