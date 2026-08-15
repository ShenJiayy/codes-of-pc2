#include<bits/stdc++.h>
using namespace std;
int n,m,q,x[505][505];
bool flag[505][505];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>n>>m>>q;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int a,b,c;
			cin>>a>>b>>c;
			if(!flag[a][b]){
				x[a][b]=c;
			}
			if(!flag[a+1][b]){
				x[a+1][b]=c;
			}
			if(!flag[a][b+1]){
				x[a][b+1]=c;
			}
			if(!flag[a+1][b+1]){
				x[a+1][b+1]=c;
			}
		}
		else{
			int a,b;
			cin>>a>>b;
			flag[a][b]=flag[a+1][b]=flag[a][b+1]=flag[a+1][b+1]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
