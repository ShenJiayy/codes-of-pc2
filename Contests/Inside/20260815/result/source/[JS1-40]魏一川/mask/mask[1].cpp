#include<bits/stdc++.h>
using namespace std;
int h,w,q,a[505][505],vis[505][505];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	scanf("%d%d%d",&h,&w,&q);
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			if(vis[x][y]!=-1)a[x][y]=c;
			if(vis[x+1][y]!=-1)a[x+1][y]=c;
			if(vis[x][y+1]!=-1)a[x][y+1]=c;
			if(vis[x+1][y+1]!=-1)a[x+1][y+1]=c;
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			vis[x][y]=-1;
			vis[x+1][y]=-1;
			vis[x][y+1]=-1;
			vis[x+1][y+1]=-1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)cout<<a[i][j]<<' ';
		cout<<"\n";
	}
	return 0;
}
