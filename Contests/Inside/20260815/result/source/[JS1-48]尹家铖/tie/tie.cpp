#include<bits/stdc++.h>
using namespace std;
int n;
struct node{int id,val;}a[200005];
bool cmp(node x,node y){return x.val<y.val;}
int rk[200005],b[200005],ans[200005],p[200005];
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+n+2,cmp);
	for(int i=1;i<=n+1;i++) rk[i]=a[i].id;
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		p[i]=max(0,a[i].val-b[i]);
		ans[rk[n+1]]=max(ans[rk[n+1]],p[i]);
	}
	for(int i=n;i>=1;i--){
		p[i]=max(0,a[i+1].val-b[i]);
		ans[rk[i]]=max(p[i],ans[rk[i+1]]);
	}
	for(int i=1;i<=n+1;i++){
		printf("%d",ans[i]);
		if(i!=n+1) printf(" "); 
	}
	return 0;
}
