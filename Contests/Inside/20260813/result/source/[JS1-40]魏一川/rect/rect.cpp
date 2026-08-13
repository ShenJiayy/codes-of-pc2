#include<bits/stdc++.h>
using namespace std;
int n,m;
long long cnt;
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a[n+5][m+5],s[n+5][m+5];
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<s[i][j]<<' ';
		cout<<"\n";
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int ii=i;ii<=n;ii++){
				for(int jj=j;jj<=m;jj++){
					int sum=s[ii][jj]-s[ii][j-1]-s[i-1][jj]+s[i-1][j-1];
					int size=(ii-i+1)*(jj-j+1);
					if(sum==size)cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
/*
1 3 3
2 5 6
*/
