#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200030],ans,dp[200030][3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i]/3;
		a[i]%=3;
		if (a[i]==0) a[i]=3,ans--;
		if (i!=1){
			if (a[i]==2 && a[i-1]==1) ans++,a[i]=a[i-1]=0;
			else if (a[i]==1 && a[i-1]==2) ans++,a[i]=a[i-1]=0;
			else if (a[i]==2 && a[i-1]==2) ans++,a[i]=1,a[i-1]=0;
			else if (a[i]==3 && a[i-1]==2) ans++,a[i]=2,a[i-1]=0;
			else if (a[i]==3 && a[i-1]==1) ans++,a[i]=1,a[i-1]=0;
			else if (a[i]==3 && a[i-1]==0) ans++,a[i]=0;
		}
	}
	if (a[n]==3) ans++;
	cout<<ans;
	return 0;
} 
