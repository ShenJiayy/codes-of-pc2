#include <iostream>
using namespace std;
int n,m,q,a[600][600];
bool b[600][600];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>n>>m>>q;
	while(q--){
		int qk,xk,yk,ck;
		cin>>qk;
		if(qk==1){
			cin>>xk>>yk>>ck;
			if(!b[xk][yk]){
				a[xk][yk]=ck;
			}
			if(!b[xk+1][yk]){
				a[xk+1][yk]=ck;
			}
			if(!b[xk][yk+1]){
				a[xk][yk+1]=ck;
			}
			if(!b[xk+1][yk+1]){
				a[xk+1][yk+1]=ck;
			}
		}
		if(qk==2){
			cin>>xk>>yk;
			b[xk][yk]=b[xk+1][yk]=b[xk][yk+1]=b[xk+1][yk+1]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
