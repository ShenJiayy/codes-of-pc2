#include <bits/stdc++.h>
#define Rainbow return
#define after 0
#define rain
#define ll long long
using namespace std;
int n,m,k,fa[20010];
struct ed{
	int u,v,w;
}e[100010],mst[20010];
bool cmp(ed x,ed y){
	return x.w<y.w;
}
int f(int x){
	return fa[x]==x?x:fa[x]=f(fa[x]);
}
void mg(int x,int y){
	x=f(x),y=f(y);
	if(x!=y) fa[x]=y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
    // Kruskarl 1
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int cnt=0,x=0;
	for(int i=1;i<=m;i++){
		if(f(e[i].u)!=f(e[i].v)&&e[i].w==0){
			mg(e[i].u,e[i].v);
			mst[++x]=e[i];
			cnt++;
			if(cnt==k) break;
		}
	}
	if(cnt<k){
		cout<<"no solution";
		Rainbow after rain;
	}
    // Kruskarl 2
	for(int i=m;i>=1;i--){
		if(f(e[i].u)!=f(e[i].v)&&e[i].w){
			mg(e[i].u,e[i].v);
			mst[++x]=e[i];
			if(x==n-1) break;
		}
	}
    
	for(int i=1;i<n;i++){
		cout<<mst[i].u<<" "<<mst[i].v<<" "<<mst[i].w<<"\n";  
	}
	Rainbow after rain;
}

