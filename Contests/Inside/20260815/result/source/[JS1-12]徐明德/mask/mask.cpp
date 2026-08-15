//mask
#include<bits/stdc++.h>
using namespace std;
int h,w,q;
int mp[600][600];
bool f[600][600]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>h>>w>>q;
	int op,x,y,c;
	for(int i=1;i<=q;i++){
		cin>>op>>x>>y;
		if(op==1){
			cin>>c;
			if(!f[x][y])mp[x][y]=c;
			if(!f[x+1][y])mp[x+1][y]=c;
			if(!f[x][y+1])mp[x][y+1]=c;
			if(!f[x+1][y+1])mp[x+1][y+1]=c;
		}
		else if(op==2){
			f[x][y]=1;
			f[x+1][y]=1;
			f[x][y+1]=1;
			f[x+1][y+1]=1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
/*
Ä£Äâ
*/
