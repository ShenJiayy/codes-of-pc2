#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,mod=998244353;
ll n,m,a[N],t[N],p[N],v[N],q;
vector<ll>g[N];
void kk(int x){
	//cout<<x<<" ";
	if(t[x]==1) a[p[x]]+=v[x],a[p[x]]%=mod;
	if(t[x]==2){
		for(int i=1;i<=n;i++){
			a[i]*=v[x];
			a[i]%=mod;
		}
	}
	if(t[x]==3){
		for(int i=0;i<g[x].size();i++){
			kk(g[x][i]);
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i];
		if(t[i]==1){
			cin>>p[i]>>v[i];
		}
		if(t[i]==2){
			cin>>v[i];
		}
		if(t[i]==3){
			cin>>v[i];
			for(int j=1;j<=v[i];j++){
				int x;
				cin>>x;
				g[i].push_back(x);
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int x;
		cin>>x;
		kk(x);
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
