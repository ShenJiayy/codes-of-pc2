#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200020;
int n;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(a[i]+a[i-1]<=2)continue;
		ans+=(a[i]+a[i-1])/3;
		a[i] = (a[i]+a[i-1])%3;
	}
	cout<<ans<<endl;
	
	return 0;
}
