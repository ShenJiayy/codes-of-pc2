#include<bits/stdc++.h>
using namespace std;
int ma1[200005],ma2[200005],b[200005],ans[200005]; 
struct node{
	int x,id;
}a[200005];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(a+1,a+1+n+1,cmp);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		int d=a[i].x-b[i];
		ma1[i]=max(ma1[i-1],d);
	}
	for(int i=n;i>=1;i--){
		int d=a[i+1].x-b[i];
		ma2[i]=max(ma2[i+1],d);
	}
	for(int i=1;i<=n+1;i++){
		ans[a[i].id]=max(ma1[i-1],ma2[i]);
	}
	for(int i=1;i<=n+1;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
