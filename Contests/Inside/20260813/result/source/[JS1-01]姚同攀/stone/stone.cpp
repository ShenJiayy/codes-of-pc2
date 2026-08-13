#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(int j=i-1;j;--j)
			if(a[i]==a[j]){
				for(int k=j+1;k<i;++k) a[k]=a[i];
				break;
			}
				
	}
	for(int i=1;i<=n;++i) printf("%d\n",a[i]);
	return 0;
} 
