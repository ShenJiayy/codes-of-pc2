#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,id;
}a[200005];
int n,b[200005],ans[200005];
bool cmp(node x,node y){
	return x.l<y.l;
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		scanf("%d",&a[i].l);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(a+1,a+n+2,cmp);//3 4 6 7
	sort(b+1,b+n+1);//2 4 6
	for(int i=1;i<=n+1;i++){
		int _ans=0;
		for(int j=1,k=1;j<=n+1;j++){
			if(j==i)continue;
			//cout<<a[j].l<<' '<<b[k]<<"\n";
			_ans=max(_ans,max(a[j].l-b[k],0));
			k++;
		}
		ans[a[i].id]=_ans;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<ans[n+1];
	return 0;
}
