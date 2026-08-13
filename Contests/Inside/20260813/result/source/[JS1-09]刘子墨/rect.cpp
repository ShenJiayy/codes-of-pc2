#include<bits/stdc++.h>

using namespace std;
using ll=long long;

const int maxn=3e5+5;

int n,m,sum,sz,ans=0;

int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int a[n+5][m+5],s[n+5][m+5],sp[n+5][m+5];
	for(int i=1;i<=n;i++){
		for(int j=1,x;j<=m;j++){
			cin>>x;
			s[i][j]=x+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	for(int h=1;h<=n;h++){
		for(int w=1;w<=m;w++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(i>=h&&j>=w)
						if(s[i][j]-s[i-h][j]-s[i][j-w]+s[i-h][j-w]==h*w)ans++;
				}
			}		
		}
	}
	cout<<ans;
	return 0;
}
