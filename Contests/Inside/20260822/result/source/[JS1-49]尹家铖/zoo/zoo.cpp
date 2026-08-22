#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m,p,q,ans=1,c,k;
vector<int>si[65];
int vis[100000005];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	ll sum=0,x;
	for(int i=1;i<=n;i++){
		cin>>x;
		sum|=x;
	}
	ll p,q;
	for(int i=1;i<=m;i++){
		cin>>p>>q;
		si[p].push_back(q);
	}
	ll cnt=0;
	while(sum){
		if(sum&1)
			for(int i=0;i<si[cnt].size();i++)
				vis[si[cnt][i]]=1;
		sum>>=1;cnt++;
	}
	for(int i=0;i<=k-1;i++){
		int flag=1;
		for(int j=0;j<si[i].size();j++)
			if(!vis[si[i][j]]){
				flag=0;break;
			}
		if(flag) ans*=2;
	}
	if(ans>0){cout<<ans-n;}
	else printf("18446744073709551616");
	return 0;
}
