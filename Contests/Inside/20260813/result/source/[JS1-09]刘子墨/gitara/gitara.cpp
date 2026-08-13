#include<bits/stdc++.h>

using namespace std;
using ll=long long;

const int maxn=5e5+5;
const int maxp=3e5+5;

int n,p,x,y,l[7][maxp],cnt=0,h[7]={1,1,1,1,1,1,1};
bool a[7][maxp];

int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		while(l[x][h[x]]>y){
			a[x][l[x][h[x]]]=0;
			h[x]++;
			cnt++;
		}
		if(!a[x][y]){
			l[x][--h[x]]=y;
			cnt++;
			a[x][y]=1;
		}
	}
	cout<<cnt;
	return 0;
}
