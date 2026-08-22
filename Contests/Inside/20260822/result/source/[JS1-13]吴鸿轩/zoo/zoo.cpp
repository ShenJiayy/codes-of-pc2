#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,a[1000010],b[101],p,q,ans;
unsigned long long sum,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m--){
		cin>>p>>q;
		b[p+1]=1;
	}
	for(int i=1;i<=k;i++){
		if(b[i]==1){
			for(int j=1;j<=n;j++){
				if((a[j]>>(i-1))&1){
					b[i]=0;
					break;
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		//cout<<b[i]<<" ";
		if(b[i]==1){
			ans++;
		}
	}
	cnt=2;
	k-=ans;
	if(k==64&&n==0){
		if(n==0){
			cout<<"18446744073709551616";
			return 0;
		}else{
			sum-=n;
			cnt=18446744073709551615;
			sum+=cnt;
			sum++;
			cout<<sum;
			return 0;
		}
	}
	sum=1;
	for(int i=1;i<=k;i++){
		sum*=cnt;
	}
	sum-=n;
	cout<<sum;
	return 0;
}
