#include<bits/stdc++.h>
using namespace std;
const int MXN=3e5+10;
int n,p,x,y,cnt,a[7][MXN];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		while(a[x][a[x][0]]>y) cnt++,a[x][0]--;
		if(a[x][a[x][0]]!=y) a[x][++a[x][0]]=y,cnt++;
	}
	cout<<cnt;
	return 0;
}
