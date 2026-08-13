#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[35][35],p[35][35];
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	if(n<=30&&m<=30){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
			}
		}
		for(int x1=1;x1<=n;x1++){
			for(int y1=1;y1<=m;y1++){
				for(int x2=x1;x2<=n;x2++){
					for(int y2=y1;y2<=m;y2++){
						if((x2-x1+1)*(y2-y1+1)==p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1]){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
