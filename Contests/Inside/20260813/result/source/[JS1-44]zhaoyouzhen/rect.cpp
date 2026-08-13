#include <bits/stdc++.h>
using namespace std;
int n,m,sum[250010][3],x,ans,s[250010],d[250010];
map < pair < int , int > , int > p;
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		memset(d,0,sizeof d);
		for(int j=1;j<=m;++j){
			cin>>x;
			d[j]=d[j-1]+x;
			sum[j][1]=sum[j][2]+x;
			sum[j][2]=sum[j][1];
			s[j]=s[j-1]+sum[j][1];
			for(int k=1;k<=j;++k){
				int cnt=s[j]-s[k-1];
				if(cnt==(j-k+1)*i||d[j]-d[k-1]==j-k+1){
					p[{k,j}]++;
					ans+=p[{k,j}];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
