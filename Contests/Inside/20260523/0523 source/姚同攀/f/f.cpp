#include<bits/stdc++.h>
using namespace std;
const int N=3505;
int n,a[N],ans=1e9;
int main(){
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n%2){
		printf("-1");
	}
	else{
		for(int i=1;i<=n>>1;++i) ans=min(ans,a[i+(n>>1)]-a[i]);
		printf("%d",ans);
	}
	return 0;
} 
