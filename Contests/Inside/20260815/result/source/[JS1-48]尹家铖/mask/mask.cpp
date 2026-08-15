#include<bits/stdc++.h>
using namespace std;
int h,w,a[505][505],vis[505][505];
int q;
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	scanf("%d%d%d",&h,&w,&q);
	int x,y,c,opt;
	while(q--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&x,&y,&c);
			if(!vis[x][y]) a[x][y]=c;
			if(!vis[x+1][y]) a[x+1][y]=c;
			if(!vis[x][y+1]) a[x][y+1]=c;
			if(!vis[x+1][y+1]) a[x+1][y+1]=c;
		}
		if(opt==2){
			scanf("%d%d",&x,&y);
			vis[x][y]=1;
			vis[x+1][y+1]=1;
			vis[x][y+1]=1;	
			vis[x+1][y]=1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
} 
