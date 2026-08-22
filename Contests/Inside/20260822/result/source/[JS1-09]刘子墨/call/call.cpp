#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int maxn=5005;
int n,m,a[maxn],q,d[maxn];
struct node{
	int t,p,v,c,g[maxn];
}f[maxn];
void solve(int d){
	if(f[d].t==1){
			a[f[d].p]+=f[d].v;
		}
	else if(f[d].t==2){
		for(int j=1;j<=n;j++){
			a[j]*=f[d].v;
		}
	}
	else{
		for(int j=1;j<=f[d].c;j++){
			solve(f[d].g[j]);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>f[i].t;
		if(f[i].t==1){
			cin>>f[i].p>>f[i].v;
		}
		else if(f[i].t==2){
			cin>>f[i].v;
		}
		else{
			cin>>f[i].c;
			for(int j=1;j<=f[i].c;j++){
				cin>>f[i].g[j];
			}
		}
	}
	cin>>q;
	for(int i=1,d;i<=q;i++){
		cin>>d;
		solve(d);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

