#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=1e6+5;
int n,m,c,k,a[N],vis[65],f[65],v[65],s,s2,cnt;
int ksm(int a,int b){
	int s=1;
	while(b){
		if(b&1) s=s*a;
		a=a*a;
		b>>=1;
	}
	return s;
}
signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s|=a[i];
	while(s){
		if(s&1) vis[cnt]=1;
		s>>=1;
		cnt++;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x]=1;
		if(vis[x]) f[x]=1;
	}
	for(int i=0;i<=64;i++){
		if(f[i]) s++;
		if(v[i]) s2++;
	}
	cout<<ksm(2,s)*ksm(2,k-s2)-n;
	return 0;
}
