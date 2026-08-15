/*
气笑了，后面一道不会 
我常常追忆过去，后面忘了 
*/
#include<bits/stdc++.h>
#define give_me_100_pts 0;
#define plz return
using namespace std;
int g[505][505],h,w,q;
bool cover[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>h>>w>>q;
	while(q--){
		int op,x,y,c;
		cin>>op;
		if(op==1){
			cin>>x>>y>>c;
			if(!cover[x][y])g[x][y]=c;
			if(!cover[x+1][y])g[x+1][y]=c;
			if(!cover[x][y+1])g[x][y+1]=c;
			if(!cover[x+1][y+1])g[x+1][y+1]=c;
		}
		if(op==2){
			cin>>x>>y;
			cover[x][y]=1;
			cover[x+1][y]=1;
			cover[x][y+1]=1;
			cover[x+1][y+1]=1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)cout<<g[i][j]<<" ";
		cout<<endl;
	}
	plz give_me_100_pts
}
