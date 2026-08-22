//snakes
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
int a[N];
vector<int>ans;
void solve(){
	int all=n;
	if(n==3){
		if(a[2]==a[3]){
			cout<<3;
			return ;
		}
		if(a[3]-a[1]>=a[2]){
			cout<<1;
			return ;
		}
		if(a[3]-a[1]<a[2]){
			cout<<3;
			return ;
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int _;
	cin>>_;
	bool f=0;
	int x,y;
	while(_--){
		if(!f){
			f=1;
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
		}
		else{
			cin>>k;
			for(int i=1;i<=k;i++){
				cin>>x>>y;
				a[x]=y;
			}
		}
		solve();
	}
	return 0;
}
