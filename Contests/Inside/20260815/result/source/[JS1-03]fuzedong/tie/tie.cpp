#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,b[N],f[N],g[N],ans[N];
pair<int,int>a[N];
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	sort(a+1,a+n+2);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		f[i]=max(a[i].first-b[i],0);
		g[i]=max(a[i+1].first-b[i],0);
	}
	for(int i=1;i<=n;i++)f[i]=max(f[i-1],f[i]);
	for(int i=n;i>=1;i--)g[i]=max(g[i+1],g[i]);
	for(int i=1;i<=n+1;i++){
		ans[a[i].second]=max(f[i-1],g[i]);
	}
	for(int i=1;i<=n+1;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
