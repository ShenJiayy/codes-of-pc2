#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
ll n,a[200010],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans+=a[i]/3;
		a[i]%=3;
		if(a[i]&&a[i]+a[i+1]>=3){
			a[i+1]-=3-a[i];
			ans++;
		}  
		//cout<<ans<<" ";
	}
	cout<<ans;
	I AK IOI;
}
//100 
