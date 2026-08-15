#include<bits/stdc++.h>
using namespace std;
long long h,w,q,a[1010][1010];
bool b[1010][1010];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>h>>w>>q;
	while(q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,y,k;
			cin>>x>>y>>k;
			if(b[x][y]==0){
				a[x][y]=k;
			}
			if(b[x+1][y]==0){
				a[x+1][y]=k;
			}
			if(b[x][y+1]==0){
				a[x][y+1]=k;
			}
			if(b[x+1][y+1]==0){
				a[x+1][y+1]=k;
			}
		}else{
			int x,y;
			cin>>x>>y;
			b[x][y]=1;
			b[x+1][y]=1;
			b[x][y+1]=1;
			b[x+1][y+1]=1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
