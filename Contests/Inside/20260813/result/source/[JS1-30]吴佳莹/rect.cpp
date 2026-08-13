#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=35;
int n,m,s[N][N],a[N][N],ans;
signed main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int l=i;l<=n;l++){
				for(int r=j;r<=m;r++){
					int res=s[l][r]-s[i-1][r]-s[l][j-1]+s[i-1][j-1];
					if(res==(l-i+1)*(r-j+1)) ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
