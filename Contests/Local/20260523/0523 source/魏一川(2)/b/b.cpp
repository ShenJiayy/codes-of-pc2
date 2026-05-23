#include<bits/stdc++.h>
using namespace std;
int n,a[500005],cnt=1,pu,cha=1e9,ans;
vector<int>v;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])cnt++;
		else{
			v.push_back(cnt);
			cnt=1;
		}
	}
	v.push_back(cnt);
	for(int i:v){
		pu+=i;
		int sheng=n-pu;
		int now=abs(sheng-pu); 
		if(now<=cha){
			cha=now;
			ans=pu+1;
		}
	}
	cout<<a[ans];
	return 0;
}
