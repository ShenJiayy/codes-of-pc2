#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[300005];
int temp[300005];
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long sum=0;
		for(int i=1;i<=n;i++){
			temp[i]=a[i];
		}
		int k=0;
		while(sum<ans){
			sum=0;
			for(int i=1;i<=n;i++){
				if(temp[i]<y){
					temp[i]=0;
				}
				else{
					temp[i]-=y;
				}
				sum+=temp[i];
			}
			k++;
			sum+=x*k;
			if(ans>sum){
				ans=sum;
			}
//			cout<<sum<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
