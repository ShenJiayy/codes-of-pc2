#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,k,a[N];
bool eaten(int len){
	if(a[len]-a[1]>=a[2]) return true;
	int p=a[1];
	a[1]=a[len]-a[1];
	bool res=!(eaten(len-1));
	a[1]=p;
	return res;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int cur=n;
	while(1){
		if(cur<=3){
			a[3]-a[1]>=a[2]?printf("1\n"):printf("3\n");
			break;
		}
		if(eaten(cur)){
			printf("%d\n",cur);
			break;
		}
		a[1]=a[cur]-a[1];
		--cur;
		for(int i=1;i<cur;++i)
			if(a[i]>a[i+1]) swap(a[i],a[i+1]);
	}
	--T;
	while(T--){
		scanf("%d",&k);
		for(int i=1,x,y;i<=k;++i){
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		cur=n;
		while(1){
			if(cur<=3){
				a[3]-a[1]>=a[2]?printf("1\n"):printf("3\n");
				break;
			}
			if(eaten(cur)){
				printf("%d\n",cur);
				break;
			}
			a[1]=a[cur]-a[1];
			--cur;
			for(int i=1;i<cur;++i)
				if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		}
	}
	return 0;
}
