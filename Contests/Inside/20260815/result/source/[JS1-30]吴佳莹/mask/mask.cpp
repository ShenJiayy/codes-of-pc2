#include<bits/stdc++.h>
using namespace std;
const int N=505;
int h,w,q,a[N][N],vis[N][N];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>h>>w>>q;
	while(q--){
		int op,x,y,k;
		cin>>op>>x>>y;
		if(op==1){
			cin>>k;
			if(!vis[x][y]) a[x][y]=k;
			if(!vis[x+1][y]) a[x+1][y]=k;
			if(!vis[x][y+1]) a[x][y+1]=k;
			if(!vis[x+1][y+1]) a[x+1][y+1]=k;
		}
		else vis[x][y]=vis[x+1][y]=vis[x][y+1]=vis[x+1][y+1]=1;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
