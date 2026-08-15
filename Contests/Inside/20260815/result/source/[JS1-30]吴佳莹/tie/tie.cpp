#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,b[N],l[N],r[N],ans[N];
struct node{
	int id,x;
}a[N];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++) cin>>a[i].x,a[i].id=i;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+2+n,cmp);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++) l[i]=max(l[i-1],max(a[i].x-b[i],0));
	for(int i=n+1;i>=2;i--) r[i]=max(r[i+1],max(a[i].x-b[i-1],0));
	for(int i=1;i<=n+1;i++) ans[a[i].id]=max(l[i-1],r[i+1]);
	for(int i=1;i<=n+1;i++) cout<<ans[i]<<' ';
	return 0;
}
