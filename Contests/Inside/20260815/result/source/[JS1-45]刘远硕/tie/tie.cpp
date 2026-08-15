#include<bits/stdc++.h>
using namespace std;
int n,mxa[200020],mxb[200020];
struct nd{
	int v,id;
} a[200020],b[200020],ans[200020];

bool cmp (nd a,nd b){
	return a.v<b.v;
}
bool cmmp (nd a,nd b){
	return a.id<b.id;
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n+1;i++){
		cin>>a[i].v;
		a[i].id=i;
	} 
	for (int i=1;i<=n;i++) {
		cin>>b[i].v;
		b[i].id=i;
	}
	sort(a+1,a+2+n,cmp);
	sort(b+1,b+1+n,cmp);
	for (int i=1;i<=n;i++) mxa[i]=max(mxa[i-1],max(a[i].v-b[i].v,0));
	for (int i=n;i>=1;i--) mxb[i+1]=max(mxb[i+2],max(a[i+1].v-b[i].v,0));
//	for (int i=1;i<=n+1;i++) cout<<a[i].v<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++) cout<<b[i].v<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n+1;i++) cout<<a[i].id<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++) cout<<b[i].id<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++) cout<<mxa[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++) cout<<mxb[i]<<" ";
//	cout<<"\n";
	for (int k=1;k<=n+1;k++) ans[k]={max(mxa[k-1],mxb[k+1]),a[k].id};
	sort(ans+1,ans+2+n,cmmp);
	for (int i=1;i<=n+1;i++) cout<<ans[i].v<<" ";
	return 0;
}
