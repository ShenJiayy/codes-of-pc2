#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],n,ans,last;
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]+last>=3){
			if(a[i]+last>=3){
				ans+=(a[i]+last)/3;
				a[i]=min(a[i],(a[i]+last)%3);	
			}
		}
		last=a[i];
		//cout<<last<<endl;
	}
	cout<<ans;
	return 0;
}
