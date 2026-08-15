#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[505][505],b[505][505];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>n>>m>>q;
//	for (int i=1;i<=n;i++)
//		for (int j=1;j<=m;j++)
//			cin>>a[i][j];
	while(q--){
		int op,x,y,c;
		cin>>op>>x>>y;
		if (op==1){
			cin>>c;
			if (b[x][y]==0) a[x][y]=c;
			if (b[x+1][y]==0) a[x+1][y]=c;
			if (b[x][y+1]==0) a[x][y+1]=c;
			if (b[x+1][y+1]==0) a[x+1][y+1]=c;
		}else {
			b[x][y]=1;
			b[x+1][y]=1;
			b[x][y+1]=1;
			b[x+1][y+1]=1;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
		
	return 0;
}
