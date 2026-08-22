#include <bits/stdc++.h>
using namespace std;
int arr[1145141];
int cnt;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=m;i++){
		int p,q;
		cin>>p>>q;
	}
	cout<<pow(2,k)-n;
	return 0;
}
/*
6 7 3 4 5 6 14 8 9 10
*/
