#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],e[N],cnt=1,n;
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>e[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if(a[i-1]!=a[i]){
			cnt++;
		}
	}
	cout<<cnt;
}
