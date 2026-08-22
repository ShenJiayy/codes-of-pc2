#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,n;
	cin>>T;
	T--;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(a[3]-a[1]<a[2]) {
		cout<<3<<'\n';
	}
	else {
		cout<<1<<'\n';
	}
	while(T--) {
		int k;
		cin>>k;
		for(int i=1;i<=k;i++) {
			int u,v;
			cin>>u>>v;
			a[u]=v;
		}
		if(a[3]-a[1]<a[2]) {
			cout<<3<<'\n';
		}
		else {
			cout<<1<<'\n';
		}
	}
	return 0;
}
//CSP-S RP++
