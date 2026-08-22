#include<bits/stdc++.h>
using namespace std;
int n,T,a[500005],b[500005],vis[500005];
int flag=1;
void dfs(int l,int r,int step,string ch){
	if(!flag) return;
	if(step>2*n){cout<<ch<<"\n";flag=0;return;}
	if(step<=n){
		b[step]=a[l];vis[a[l]]++;
		if(vis[a[l]]<2)dfs(l+1,r,step+1,ch+"L");
		vis[a[l]]--;vis[a[r]]++;
		b[step]=a[r];
		if(vis[a[r]]<2)dfs(l,r-1,step+1,ch+"R");
		vis[a[r]]--;
	}
	else{
		if(a[l]==b[2*n-step+1]){
			b[step]=a[l];
			dfs(l+1,r,step+1,ch+"L");
		}
		if(a[r]==b[2*n-step+1]){
			b[step]=a[r];
			dfs(l,r-1,step+1,ch+"R");
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flag=1;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		dfs(1,2*n,1,"");
		if(flag) printf("-1\n");
	}
	return 0;
}
