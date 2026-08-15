#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[510][510],n,m,q,f,x,y,z,d[4][2]={{0,0},{1,0},{0,1},{1,1}};
bool val[510][510];
signed main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>n>>m>>q;
	while(q--){
		cin>>f;
		if(f==1){
			cin>>x>>y>>z;
			for(int i=0;i<4;++i){
				int nx=x+d[i][0],ny=y+d[i][1];
				if(nx>n||nx<1||ny>m||ny<1) continue;
				if(!val[nx][ny]) a[nx][ny]=z;
			}
		}
		else{
			cin>>x>>y;
			for(int i=0;i<4;++i){
				int nx=x+d[i][0],ny=y+d[i][1];
				if(nx>n||nx<1||ny>m||ny<1) continue;
				val[nx][ny]=1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
