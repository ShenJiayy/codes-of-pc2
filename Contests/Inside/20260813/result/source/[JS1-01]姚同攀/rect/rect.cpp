#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
const int X=N*10;
int n,m,a[N],s[N],t[N],h[N*30];
ll ans;
int b[N],sm[N];
int C(int x,int y){
	if(!x||!y) return 0;
	return (x-1)*m+y;
}
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;++i) scanf("%d%d",&b[i],&sm[i]);
	
	if(n<m)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				int c=C(i,j);
				scanf("%d",&a[c]);
				s[c]=s[C(i-1,j)]+s[C(i,j-1)]-s[C(i-1,j-1)]+a[c];
				t[c]=s[c]-i*j;
			}
	else{
		swap(n,m);
		for(int j=1;j<=n;++j)
			for(int i=1;i<=m;++i){
				int c=C(i,j);
				scanf("%d",&a[c]);
				s[c]=s[C(i-1,j)]+s[C(i,j-1)]-s[C(i-1,j-1)]+a[c];
				t[c]=s[c]-i*j;	
			}
	}
	for(int d=1;d<=n;++d)
	for(int u=0;u<d;++u){
		h[X]=1;
		for(int r=1;r<=m;++r){
			ans+=h[t[C(d,r)]-t[C(u,r)]+X];
			++h[t[C(d,r)]-t[C(u,r)]+X];
		}
		h[X]=0;
		for(int r=1;r<=m;++r) --h[t[C(d,r)]-t[C(u,r)]+X];
	}
//	for(int i=1;i<=m;++i) if(t[C(1,i)]-t[(0,i)]!=sm[i]-i) printf("%d ",i);
	printf("%lld",ans);
	return 0;
}

/*


*/
