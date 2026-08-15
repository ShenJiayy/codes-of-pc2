#include<bits/stdc++.h>
using namespace std;
int h,w,q;
int nxt[5][3]={{0,0},{1,0},{0,1},{1,1}};
int color[510][510],x,y,c,opt;
bool is[510][510];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	cin>>h>>w>>q;
	while(q--){
		cin>>opt;
		if(opt==1){
			cin>>x>>y>>c;
			for(int i=0;i<4;i++){
				int nx=x+nxt[i][0],ny=y+nxt[i][1];
				if(nx>h||ny>w||nx<1||ny<1||is[nx][ny]) continue;
				color[nx][ny]=c;
			}
		}else{
			cin>>x>>y;
			for(int i=0;i<4;i++){
				int nx=x+nxt[i][0],ny=y+nxt[i][1];
				if(nx>h||ny>w||nx<1||ny<1) continue;
				is[nx][ny]=1;
			}			
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cout<<color[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
