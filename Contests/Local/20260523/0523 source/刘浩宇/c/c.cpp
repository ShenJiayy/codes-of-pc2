#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[200005];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1]/3;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int temp=(a[i-1]+a[i])%3;
		ans+=(a[i-1]+a[i]-temp)/3;
		a[i]=temp;
	}
	cout<<ans;
	return 0;
	
} 
