#include<bits/stdc++.h>
using namespace std;
const int N=3505;
int n,a[N],b[N],c[N],last[N],flag=1,ans;
void dfs(int k){
	if(k==n+1){
	//	for(int i=1;i<=n;i++) cout<<b[i]<<' ';
	//	cout<<endl;
		int res=2e9;
		for(int i=1;i<=n;i++) c[i]=last[i]=0;
		for(int i=1;i<=n;i++){
			c[b[i]]++;
			int x=last[b[i]];
			if(x){
				res=min(res,abs(a[i]-a[x]));
				//cout<<abs(a[i]-a[x])<<endl;
			};
			last[b[i]]=i;
		}
		for(int i=1;i<=n;i++) if(c[i]==1) return;
		if(res!=2e9)ans=max(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++){
		b[k]=i;
		dfs(k+1);
		b[k]=0;
	}
}
int main()
{
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=0;
	}
	if(flag){
		cout<<n/2;
		return 0;
	}
	if(n<=7){
		dfs(1);
		if(ans!=0)cout<<ans;
		else cout<<-1;
		return 0;
	}
	cout<<-1;
	return 0;
} 
