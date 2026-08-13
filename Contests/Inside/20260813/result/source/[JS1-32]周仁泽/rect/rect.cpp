// rect
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool type_1=0;
signed main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	int a[n+10][m+10];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>a[i][j];
	}
	if(n<=30&&m<=30) type_1=1;
	else if(n==1) type_2=1;
	if(type_1){
		int sum=0;
		int pre[n+10][m+10];
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int l=i;l<=n;l++){
					for(int r=j;r<=m;r++){
						int x=(l-i+1)*(r-j+1);
						int y=pre[l][r]-pre[i-1][r]-pre[l][j-1]+pre[i-1][j-1];
						if(x==y) sum++;
					}
				}
			}
		}
		cout<<sum<<endl;
		return 0;
	}
	else if(type_2){
		
	}
	return 0;
}
