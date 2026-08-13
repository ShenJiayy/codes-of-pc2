#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,Q,maxval,a[300005],c,d,sum;
ll check(ll mid){ //使用mid张优惠券
	ll sum=0;
	for(int i=1;i<=N;++i){
		sum+=min(d,max(0LL,a[i]-d*(mid-1)));
	}
	return sum;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>N>>Q;
	for(int i=1;i<=N;++i){
		cin>>a[i];
		maxval=max(maxval,a[i]);
		sum+=maxval;
	} 
	for(int i=1;i<=Q;++i){
		cin>>c>>d;
		check(1);check(2);check(3); 
		ll l=1,r=(maxval+d-1)/d; //在“砍价序列”中找到第一个小于等于d的 
		while(l<r){
			ll mid=(l+r)/2; //使用mid张优惠券 
			cout<<mid<<" "<<check(mid);
			if(check(mid)<=c) r=mid;
			else l=mid+1;
			cout<<" "<<l<<" "<<r<<endl; 
		}

		//答案：使用l-1张优惠券
		ll ans=0;
		for(ll i=1;i<=N;++i){
			ans+=max(0LL,a[i]-d*(l-1));
		}
		ans+=c*(l-1);
		cout<<ans<<'\n';
	}
	return 0;
}
