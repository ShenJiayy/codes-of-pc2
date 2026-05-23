#include <bits/stdc++.h>
using namespace std;
int n,l,r,ans;
int a[500004];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	l=1,r=n;
	while(l<=r){
		if(a[l]==a[r]){
			ans=a[l-1];
			break;
		}
		else if(l==r){
			ans=a[l-1];
			break;
		}
		else if(r-l==1){
			ans=a[l];
			break;
		}
		l++,r--;
	}
	cout<<ans<<endl;
	return 0;
}
