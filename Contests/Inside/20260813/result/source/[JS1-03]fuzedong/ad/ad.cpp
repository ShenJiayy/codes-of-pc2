#include<bits/stdc++.h>
using namespace std;
#define N 500005
int ans,n;
bool book[N],vis[20];
struct node{
	int x,e;
	bool operator ==(const node &y)const{
		return x==y.x&&e==y.e;
	}
}a[N];
bool cmp(node x,node y){
	return x.x<y.x;
}
void dfs(int step,int ch){
	if(step==n+1){
		memset(vis,0,sizeof(vis));
//		int cnt=0;
		for(int i=1;i<=n;i++){
//			cout<<book[i]<<' ';
//			cnt+=book[i];
			if(!book[i])continue;
			vis[i]=1;
			for(int j=i-1;j>=1;j--){
				if(a[j].x<a[i].x-a[i].e)break;
				if(a[i].x-a[j].x<=a[i].e-a[j].e)vis[j]=1;
			}
			for(int j=i+1;j<=n;j++){
				if(a[j].x>a[i].x+a[i].e)break;
				if(a[j].x-a[i].x<=a[i].e-a[j].e)vis[j]=1;
			}
		}
//		cout<<'\n'<<ch<<'\n';
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				return;
			}
		}
		ans=min(ans,ch);
		return;
	}
	book[step]=1;
	dfs(step+1,ch+1);
	book[step]=0;
	dfs(step+1,ch);
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].e;
	sort(a+1,a+n+1,cmp);
	ans=n;
	if(n<=16){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	else {
		cout<<unique(a+1,a+n+1)-a-1;
		
	}
	return 0;
}
