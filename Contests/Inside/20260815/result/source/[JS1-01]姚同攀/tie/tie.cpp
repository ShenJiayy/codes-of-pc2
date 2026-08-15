#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,b[N],ans[N];
struct A{ int l,id;} a[N];
bool cmp(A x,A y){ return x.l<y.l;}
int s1[N*3][25],s2[N*3][25];
int mx1(int l,int r){
	int len=r-l+1,k=0;
	while((1<<k)<=len) ++k;
	--k;
	return max(s1[l][k],s1[r-(1<<k)+1][k]);
}
int mx2(int l,int r){
	int len=r-l+1,k=0;
	while((1<<k)<=len) ++k;
	--k;
	return max(s2[l][k],s2[r-(1<<k)+1][k]);
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n+1;++i) scanf("%d",&a[i].l),a[i].id=i;
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	sort(a+1,a+n+2,cmp);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		s1[i][0]=max(a[i].l-b[i],0);
		s2[i][0]=max(a[i+1].l-b[i],0);
	}
	for(int j=1;j<=18;++j)
	for(int i=1;i<=n;++i){
		s1[i][j]=max(s1[i][j-1],s1[i+(1<<(j-1))][j-1]);
		s2[i][j]=max(s2[i][j-1],s2[i+(1<<(j-1))][j-1]);
	} 
	ans[a[1].id]=s2[1][18];
	ans[a[n+1].id]=s1[1][18];
	for(int i=2;i<=n;++i){
		ans[a[i].id]=max(mx1(1,i-1),mx2(i,n));
	}
	for(int i=1;i<=n+1;++i) printf("%d ",ans[i]);
	return 0;
} 
