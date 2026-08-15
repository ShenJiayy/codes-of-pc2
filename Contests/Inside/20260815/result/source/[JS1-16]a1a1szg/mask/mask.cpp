#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[505][505];
int fl[505][505];
int h,w,q;
signed main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>h>>w>>q;
	for(int i=1;i<=q;i++){
		int s;
		cin>>s;
		if(s==1){
			int x,y,c;
			cin>>x>>y>>c;
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					if(!fl[x+j][y+k])a[x+j][y+k]=c;
				}
			}
		}else{
			int x,y;
			cin>>x>>y;
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					fl[x+j][y+k]=1;
				}
			}
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cout<<a[i][j]<<" ";
		}cout<<"\n";
	}
	return 0;
}
