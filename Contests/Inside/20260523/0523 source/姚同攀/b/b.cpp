#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],pos;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	pos=(n>>1)+1;
	int i=pos,j=pos;
	while(a[i]==a[pos]) ++i;
	while(a[j]==a[pos]) --j;
//	printf("%d %d\n",a[i],a[pos]);
	if(abs((n-i+1)-(i-1))<=abs((n-j)-j)) printf("%d",a[i]);
	else printf("%d",a[pos]);
	return 0;
} 
