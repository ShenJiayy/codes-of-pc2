#include<bits/stdc++.h>		//O(n*n*logn)
using namespace std;
const int N=5e5+5;
int n,m,l[N],r[N],use[N],cnt,ans=2e9;
int lsh[N<<1]={-1},tot;
int rk(int x){ return lower_bound(lsh+1,lsh+n+1,x)-lsh;}
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&l[i],&r[i]);
		lsh[i]=l[i];
		lsh[i+n]=r[i];
	}
	sort(lsh+1,lsh+n+n+1);
	for(int i=1;i<=n+n;++i)
		if(lsh[i]>lsh[i-1]) lsh[++tot]=lsh[i];
	for(int i=1;i<=tot;++i){
		for(int j=1;j<=n;++j)
			if(l[j]<=lsh[i]&&lsh[i]<=r[j])
				use[++cnt]=r[j]-l[j]+1;
		sort(use+1,use+cnt+1);
		for(int j=1;j+m-1<=cnt;++j)
			ans=min(ans,use[j+m-1]-use[j]);
		cnt=0;
	}
	ans==2e9?printf("-1"):printf("%d",ans);
	return 0;
} 
