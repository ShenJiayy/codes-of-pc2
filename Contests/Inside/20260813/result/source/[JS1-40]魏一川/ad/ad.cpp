#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,e;
}per[500005];
int n,fa[500005],cnt;
int find(int x){
	return (fa[x]==x?fa[x]:fa[x]=find(fa[x]));
}
bool cmp(node a,node b){
	return a.x<b.x;
}
void task_1(){
	int ans=0;
	for(int i=2;i<=n;i++)if(per[i].x==per[i-1].x)ans++;
	cout<<n-ans;
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)scanf("%d%d",&per[i].x,&per[i].e);
	sort(per+1,per+n+1,cmp);
	bool fl=1;
	for(int i=2;i<=n&&fl;i++)if(per[i].e!=per[i-1].e)fl=0;
	if(fl){
		task_1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(abs(per[i].x-per[j].x)<=(per[i].e-per[j].e))fa[j]=find(i);
		}
	}
	for(int i=1;i<=n;i++)if(fa[i]==i)cnt++;
	cout<<cnt;
	return 0;
}
