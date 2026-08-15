#include<bits/stdc++.h>
using namespace std;
int mape[505][505];
bool book[505][505];
int h,w,q;
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	scanf("%d %d %d",&h,&w,&q);
//	cin>>h>>w>>q;
	while(q--){
		int op,x,y,c;
		scanf("%d %d %d",&op,&x,&y);
	//	cin>>op>>x>>y;
		if(op==1){
			scanf("%d",&c);
		//	cin>>c;
			for(int i=0;i<=1;i++){
				for(int j=0;j<=1;j++){
					if(!book[x+i][y+j]){
						mape[x+i][y+j]=c;
					}
				}
			}
		}
		else{
			book[x][y]=book[x+1][y]=book[x][y+1]=book[x+1][y+1]=1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			printf("%d ",mape[i][j]);
		//	cout<<mape[i][j]<<' ';
		}
	//	cout<<'\n';
		printf("\n");
	}
	return 0;
}
