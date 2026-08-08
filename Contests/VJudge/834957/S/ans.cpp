#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=1,k=0;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) k=k*10+(c-'0'),c=getchar();
	return f*k;
}
const int N=1e4+10;
int n,m,cc,cnt,v[N*20],w[N*20],dp[N*20];
signed main(){
	n=read(),m=read(),cc=read();
	for(int i=1;i<=n;i++){
		int vv=read(),ww=read(),d=read(),pw=1;
		while(d>pw){
			d-=pw,v[++cnt]=vv*pw,w[cnt]=ww*pw;pw*=2;
		}
		v[++cnt]=vv*d,w[cnt]=ww*d; 
	}
	for(int i=1;i<=cnt;i++){
		for(int j=cc;j>=v[i];j--) dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	}
	for(int i=1;i<=m;i++){
		int a=read(),b=read(),c=read();
		for(int j=cc;j>=0;j--){
			for(int k=0;k<=j;k++) dp[j]=max(dp[j],dp[j-k]+a*k*k+b*k+c);
		}
	}
	int ans=0;
	for(int i=0;i<=cc;i++) ans=max(dp[i],ans);
	cout<<ans;
	return 0;
}
