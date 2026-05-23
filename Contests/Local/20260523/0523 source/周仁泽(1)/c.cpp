#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200004];
long long sum=0;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=a[i]/3;
		sum+=k;
		a[i]%=3;
	}
	for(int i=1;i<=n;i++){
		int t=3-a[i];
		if(a[i+1]>=t){
			a[i]=0;
			a[i+1]-=t;
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
