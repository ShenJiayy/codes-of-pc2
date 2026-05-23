#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,a[200005];
bool xzC=true,xzD=true;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>N;
	for(ll i=1;i<=N;++i){
		cin>>a[i];
		if(a[i]%3) xzC=false;
		if(a[i]!=2) xzD=false;
	}
	if(N==1){
		cout<<a[1]/3;
		return 0;
	}
	if(N==2){
		cout<<(a[1]+a[2])/3;
		return 0;
	}
	if(xzC){
		ll sum=0;
		for(ll i=1;i<=N;++i) sum+=a[i];
		sum/=3;
		cout<<sum;
		return 0;
	}
	if(xzD){
		cout<<(2*N/3);
		return 0;
	}
	
}
