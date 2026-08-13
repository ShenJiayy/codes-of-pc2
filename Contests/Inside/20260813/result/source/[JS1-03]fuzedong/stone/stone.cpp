#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,a[N],book[N],b[N],nxt[N];
void discrete(){
	for(int i=1;i<=n;i++)b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	discrete();
	for(int i=n;i>=1;i--){
		nxt[i]=book[a[i]];
		book[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=nxt[i];j++)a[j]=a[i];
		if(nxt[i])i=nxt[i]-1;
	}
	for(int i=1;i<=n;i++)printf("%d\n",b[a[i]]);
	return 0;
}
