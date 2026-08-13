#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> Go[300020],Gs[300020];
int bfs(int s){
	int ans=0;
	static int vis[300020][2];
	queue<pair<int,int> > q;
	memset(vis,0,sizeof vis);
	vis[s][1]=1;
	q.push({s,1});
	while(!q.empty()){
		auto now=q.front();
		q.pop();
		int v=now.first,ng=now.second;
		if (ng==1){
			for (int r : Go[v]){
				if (vis[r][0]==1) continue;
				vis[r][0]=1;
				q.push({r,0});
			}
		}
		else {
			for (int r : Gs[v]){
				if (vis[r][1]==1) continue;
				vis[r][1]=1;
				q.push({r,1});
			}
		}
	}
	for (int i=1;i<=n;i++) if (vis[i][1]==0 && vis[i][0]==0) ans++;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if (u==v) continue;
		if (u>v) swap(u,v);
		Go[u].push_back(v);
		Gs[v].push_back(u);
	}
	for (int i=1;i<=n;i++) cout<<bfs(i)<<"\n";
	return 0;
} 
