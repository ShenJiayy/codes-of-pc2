//20pts
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
vector< vector<int> > num;
int p;
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	cin>>n>>m;
	num.resize(n+2);
	for(int i=1;i<=m;i++) num[0].push_back(0);
	for(int i=1;i<=n;i++){
		num[i].push_back(0);
		for(int j=1;j<=m;j++){
			cin>>p;
			num[i].push_back(p);
			num[i][j]+=num[i][j-1]+num[i-1][j]-num[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=i;k++){
				for(int l=1;l<=j;l++){
					int siz=(i-k+1)*(j-l+1);
					if(siz==num[i][j]+num[k-1][l-1]-num[k-1][j]-num[i][l-1]) ans++;
					//cout<<siz<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<num[i][j]-num[k-1][l-1]<<" "<<ans<<"\n";
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
zhen de shi Div.2 ma???
*/
