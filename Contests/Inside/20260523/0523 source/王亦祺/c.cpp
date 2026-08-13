#include<iostream>
#include<fstream>
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n,arr[200005]={},l[200005],r[200005],laster,now=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		if(!arr[i-1]&&arr[i]) l[++now]=i;
		if(arr[i]&&!arr[i+1]) r[now]=i;
	}
	for(int i=1;i<=now;i++){
		laster=0;
		//cout<<l[i]<<" "<<r[i]<<"\n";
		for(int j=l[i];j<=r[i];j++){
			if(arr[j]<laster){
				laster=3-arr[j]%3;
				continue;
			}
			if(laster){
				arr[j]-=laster;
				ans++;
				laster=0;
			}
			ans+=arr[j]/3;
			arr[j]%=3;
			laster=3-arr[j]%3;
		}
	}
	cout<<ans;
	return 0;
}
