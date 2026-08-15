#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,Q,a[N][N],cov[N][N];
int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	while(Q--){
		int opt,x,y,c;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1){
			scanf("%d",&c);
			for(int d=0;d<4;++d){
				int fx=x+dx[d],fy=y+dy[d];
				if(!cov[fx][fy]) a[fx][fy]=c; 
			}
		}else
			for(int d=0;d<4;++d){
				int fx=x+dx[d],fy=y+dy[d];
				cov[fx][fy]=1;
			}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	
	return 0;
}

/*
10 10 10
2 5 7
2 5 6
1 5 6 1
1 9 2 1
2 1 1
1 2 4 2
2 3 2
1 2 2 3
1 9 9 2
1 8 8 1
*/
