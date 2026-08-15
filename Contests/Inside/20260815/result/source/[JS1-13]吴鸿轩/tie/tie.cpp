#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int num;
	int id;
	int ans;
}a[200010],c[200010],d[200010];
int b[200010];
bool cmp(node a1,node a2){
	return a1.num<a2.num;
}
bool cmp2(node a1,node a2){
	return a1.num>a2.num;
}
bool cmp1(node a1,node a2){
	return a1.id<a2.id;
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+2+n,cmp);
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		c[i].num=max(a[i].num-b[i],0);
		d[i].num=max(a[i+1].num-b[i],0);
		c[i].id=i;
		d[i].id=i+1;
	}
	sort(c+1,c+1+n,cmp2);
	sort(d+1,d+1+n,cmp2);
	int tail2=1,tail1=1;
	for(int i=1;i<=n;i++){
		while(d[tail2].id<=i){
			tail2++;
		}
		a[i].ans=d[tail2].num;
	}
	for(int i=n+1;i>=2;i--){
		while(c[tail1].id>=i){
			tail1++;
		}
		a[i].ans=max(a[i].ans,c[tail1].num);
	}
	sort(a+1,a+2+n,cmp1);
	for(int i=1;i<=n+1;i++){
		cout<<a[i].ans<<" ";
	}
	return 0;
}
