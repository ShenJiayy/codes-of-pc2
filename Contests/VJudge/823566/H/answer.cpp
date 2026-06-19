#include<bits/stdc++.h>
#define ll long long
#define mxn 500003
#define md 998244353
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rept(i,a,b) for(int i=a;i<b;++i)
using namespace std;
int power(int x,int y) {}
int n,m,c,c1,a[mxn],d[mxn],f[mxn],s[mxn],sm[mxn],sz[mxn],up[mxn],as[mxn],ans[mxn];
vector<int>e,g[mxn];
bool v[mxn],b[mxn];
ll xi;
void dfs(int x){
	v[x]=1,c++,sz[x]=1;
	if(b[x])c1++;
	for(int i:g[x])if(!v[i]){
		dfs(i);
		s[x]+=s[i];
		sz[x]+=sz[i];
	}
}
void dfs1(int x,int fa){
	f[x]=s[x]-b[x];
	ans[x]=c+1;
	for(int i:g[x])if(i!=fa&&i!=1){
		dfs1(i,x);
		f[x]=(f[x]+f[i])%md;
	}
}
void dfs2(int x,int fa){
	a[x]=c,d[x]=c1;
	if(fa)up[x]=(up[fa]+(c1-s[x])+f[fa]-f[x]-s[x])%md;
	ans[x]=(ans[x]+(up[x]+f[x])*xi)%md;
	ans[x]=(ans[x]-(c-sz[x])*xi%md*s[x])%md;
	for(int i:g[x])if(i!=fa&&i!=1)ans[x]=(ans[x]-sz[i]*xi%md*(c1-s[i]))%md;
	for(int i:g[x])if(i!=fa&&i!=1){
		dfs2(i,x);
	}
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;++i){
		scanf("%d%d",&x,&y);
		g[x].pb(y),g[y].pb(x);
		if(x==1)b[y]=1,s[y]++;
		if(y==1)b[x]=1,s[x]++;
	}
	v[1]=1;
	for(int i:g[1])if(!v[i]){
		c=0,c1=0;
		dfs(i);
		xi=power(c1,md-2);
		dfs1(i,0);dfs2(i,0);
		sm[c1]=(sm[c1]+c)%md;
	}
	rep(i,1,n)if(sm[i])e.pb(i);
	for(int i:e){
		for(int j:e)if(i!=j)as[i]=(as[i]+(ll)sm[j]*j%md*power(i+j,md-2))%md;
	}
	rep(i,1,n){
		ans[i]=(ans[i]*499122177ll%md+md)%md;
		ans[i]=(ans[i]+as[d[i]]+(sm[d[i]]-a[i])*499122177ll%md)%md;
	}
	rep(i,1,n)printf("%d ",(ans[i]+1)%md);
	return 0;
}
