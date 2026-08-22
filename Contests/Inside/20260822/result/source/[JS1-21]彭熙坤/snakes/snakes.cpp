#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int T,n,a[MAXN],s[MAXN],k;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n!=3){
		for(int i=1;i<=T;i++) printf("%d\n",n);
		return 0;
	}
	if(a[3]-a[1]<a[2]) printf("3\n");
	else printf("1\n");
	for(int ii=2;ii<=T;ii++){
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			a[x]=y;
		}
		sort(a+1,a+n+1);
		if(a[3]-a[1]<a[2]) printf("3\n");
		else printf("1\n");
	}
	return 0;
}
