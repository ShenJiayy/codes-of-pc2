// mask
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e2+7;
int h,w,q,t,x,y,c;
int col[MAXN][MAXN];
bool z[MAXN][MAXN];
signed main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>h>>w>>q;
	while(q--){
		cin>>t;
		if(t==1){
			cin>>x>>y>>c;
			if(!z[x][y]) col[x][y]=c;
		    if(!z[x+1][y]) col[x+1][y]=c;
		    if(!z[x][y+1]) col[x][y+1]=c;
		    if(!z[x+1][y+1]) col[x+1][y+1]=c;
		}
		else if(t==2){
			cin>>x>>y;
			z[x][y]=1;
			z[x+1][y]=1;
			z[x][y+1]=1;
			z[x+1][y+1]=1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++) cout<<col[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
