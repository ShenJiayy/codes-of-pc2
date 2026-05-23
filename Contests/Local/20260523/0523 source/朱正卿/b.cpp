#include <iostream>
#include <algorithm>
using namespace std;
long long n,a[600000],an=1000000000000000,k;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		if(a[i]==a[i+1])continue;
		if(abs(n-i-i)<=an){
			k=a[i+1];
			an=abs(n-i-i);
		}
	//	cout<<a[i]<<' '<<n-i-i<<' '<<k<<' '<<an<<'\n';
	}
	printf("%lld",k);
	return 0;
}
