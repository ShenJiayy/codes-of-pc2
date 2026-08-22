#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int maxn=1e6+10;
ll n,m,c,k,a[maxn],cnt=0,ans;
vector<int>f[70];
bool v[70];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1,p,q;i<=m;i++){
		cin>>p>>q;
		f[p].push_back(q);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			if(f[j].empty()&&!v[j]){
				v[j]=1;
				cnt++;
				continue;
			}
			if(a[i]&(1<<j)){
				if(!v[j]){
					v[j]=1;
					cnt++;
				}
			}
		}
	}
	ll cp[70][70];
	for(int i=0;i<=cnt;i++){
		cp[i][0]=cp[i][i]=1;
	}
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<i;j++){
			cp[i][j]=cp[i-1][j]+cp[i-1][j-1];
		}
	}
	for(int i=0;i<=cnt;i++){
		ans+=cp[cnt][i];
	}
	cout<<ans-n;
	return 0;
}

