#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,a[500005],ans,min_chazhi=1e18;
vector<pair<ll,ll>> vec;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>N;
	for(ll i=1;i<=N;++i){
		cin>>a[i];
	}
	sort(a+1,a+N+1,greater<ll>());
	for(ll i=1;i<=N;++i){
		if(i==1||vec.back().first!=a[i]){
			vec.push_back(make_pair(a[i],i));
		}
		else{
			++vec.back().second;
		}
	}
	for(auto i:vec){
		ll chazhi=llabs(N-i.second*2);
		if(chazhi<min_chazhi){
			min_chazhi=chazhi;
			ans=i.first;
		}
	}
	cout<<ans<<endl;
	return 0;
}
