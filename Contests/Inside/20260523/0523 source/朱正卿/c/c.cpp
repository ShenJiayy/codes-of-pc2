#include <iostream>
#include <cstdio>
using namespace std;
long long n,a[500000],an;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++){
		an+=a[i]/3;
		a[i]%=3;
		if(a[i]+a[i+1]>=3){
			an++;
			a[i+1]=max((long long)0,a[i+1]-3+a[i]);
			a[i]=0;
		}
//		for(long long j=1;j<=n;j++)cout<<a[j]<<' ';
//		cout<<'\n';
	}
	printf("%lld",an);
	return 0;
}
