#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
using namespace std;
int n,m;
bitset<50010> s[2][50010];
vector<int> g[50010];
void dfs(int x,int f,int stp){
	s[stp][x][x]=1;
	for(auto v:g[x]){
		if(v==f) continue;
		if(v>x){
			if(stp){
				dfs(v,x,stp^1);
				s[stp][x]|=s[stp^1][v];
			}
		}
		if(v<x){
			if(!stp){
				dfs(v,x,stp^1);
				s[stp][x]|=s[stp^1][v];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		dfs(i,0,1);
		cout<<n-s[1][i].count()<<"\n";
	}
	I AK IOI;
}
//time:O(n^2/w)
//memory:O(n^2/w)
//[31,63]
