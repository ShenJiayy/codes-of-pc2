#include <bits/stdc++.h>
using namespace std;
int fa[500010],a[500010],ans,n,x[500010],e[500010];
queue < int > b[500010];
priority_queue < pair < int , int > > q;
int find(int y){
	if(fa[y]!=y) fa[y]=find(fa[y]);
	return fa[y];
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;++i) fa[i]=i;
	for(int i=1;i<=n;++i) cin>>x[i]>>e[i];
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(abs(x[i]-x[j])<=e[i]-e[j]){
				fa[j]=i;
				b[i].push(j);
				a[i]++;
			}
			else if(abs(x[i]-x[j])<=e[j]-e[i]){
				fa[i]=j;
				b[j].push(i);
				a[j]++;
			}
		}
	}
	for(int i=1;i<=n;++i) q.push({a[i],i});
	while(!q.empty()){
		int i=q.top().second,x=q.top().first;
		q.pop();
		if(x==0) continue;
		bool f=0;
		for(int j=1;!b[i].empty()&&j<=b[i].size();++j){
			if(find(b[i].front())==n+1){
				b[i].pop();
				f=1;
				x--;
			}
			else{
				fa[b[i].front()]=i;
				b[i].push(b[i].front());
				b[i].pop();
			}
		}
		if(f) q.push({x,i});
		else{
			fa[i]=n+1;
			ans++;
		}
	}
	for(int i=1;i<=n;++i) if(find(i)!=n+1) ans++;
	cout<<ans;
	return 0;
}
