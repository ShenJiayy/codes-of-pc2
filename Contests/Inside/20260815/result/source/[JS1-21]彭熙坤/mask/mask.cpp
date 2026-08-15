#include<bits/stdc++.h>
using namespace std;
int h,q,w;
int a[505][505];
bool t[505][505];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	scanf("%d %d %d",&h,&w,&q);
	for(int i=1;i<=q;i++){
		int opt,x,y,c;
		scanf("%d %d %d",&opt,&x,&y);
		if(opt==1){
			scanf("%d",&c);
			if(!t[x][y]) a[x][y]=c;
			if(!t[x+1][y]) a[x+1][y]=c;
			if(!t[x][y+1]) a[x][y+1]=c;
			if(!t[x+1][y+1]) a[x+1][y+1]=c;
		}
		else{
			t[x][y]=t[x+1][y]=t[x][y+1]=t[x+1][y+1]=true;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
