#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> pq[15];
ll n,p,cnt;
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>p;
	pq[1].push_back(0);
	pq[2].push_back(0);
	pq[3].push_back(0);
	pq[4].push_back(0);
	pq[5].push_back(0);
	pq[6].push_back(0); 
	for(ll _=1;_<=n;++_){
		ll a,b;
		cin>>a>>b;
		while(pq[a].back()>b){
			++cnt;
			pq[a].pop_back();
		}
		if(pq[a].back()!=b){
			++cnt;
			pq[a].push_back(b);
		}
	}
	
	cout<<cnt;
	return 0;
}
