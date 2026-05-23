#include<bits/stdc++.h>
using namespace std;
int n,a[500010],ans,peo=10000000;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,[](int xx,int yy){return xx<yy;});
	a[0]=-1;
	for(int i=n;i>=1;i--){
		if(a[i]==a[i-1]){
			continue;
		}
//		printf("<%d>",i);
		int npeo=n-i+1,cha=abs(n-npeo-npeo);
		if(cha<peo){
			peo=cha;
			ans=i;
		}
	}
	printf("%d",a[ans]);
	return 0;
}
