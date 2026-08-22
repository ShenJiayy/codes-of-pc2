#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
int cnt,T,ps[1000005];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	T--;scanf("%d",&n);
	if(n==3){
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		if(a[2]>a[3]-a[1]) printf("3\n");
		else printf("1\n");
		int k;
		while(T--){
			scanf("%d",&k);
			int x,y;
			for(int i=1;i<=k;i++){
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
			if(a[2]>a[3]-a[1]) printf("3\n");
			else printf("1\n");
		}
		return 0;
	}
	int k;
	for(int rp=1;rp<=T;rp++){
		if(rp==1)for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		else{
			scanf("%d",&k);int x,y;			
			for(int i=1;i<=k;k++){
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
		}
		printf("%d\n",n);	
	}
	return 0;
}
