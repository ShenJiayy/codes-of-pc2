#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,q,a[500000],k[500000],ma;
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	
	scanf("%lld%lld",&n,&q);	
	for(long long i=1;i<=n;i++)scanf("%d",&a[i]),ma=max(a[i],ma);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)k[i]=k[i-1]+a[i];
	for(long long i=1,c,d;i<=q;i++){
		scanf("%lld%lld",&c,&d);
		long long l=0,r=ma/d+1,an=0;
		while(l<=r){
			long long m=(l+r)/2;
			long long g=upper_bound(a+1,a+n+1,m*d)-1-a,f=upper_bound(a+1,a+n+1,m*d+d)-1-a;
			if((n-f)*d+k[f]-k[g]-(f-g)*d*(m)>c){
				l=m+1;
				an=m+1;
			}
			else r=m-1;
		//	cout<<f<<' '<<g<<' '<<m<<' '<<(n-f)*d+k[f]-k[g]-(f-g)*d*(m)<<'\n';
		}
		long long h=upper_bound(a+1,a+n+1,an*d )-1-a;
	//	cout<<h<<' '<<k[h]<<' '<<an<<' ';
		printf("%lld\n",k[n]-(k[h]+(n-h)*d*an)+c*an);
	}
	return 0;
}
/*
3 4 
8 10 3 
12 5 
3 2 
3 4 
100 100
2^19
*/
