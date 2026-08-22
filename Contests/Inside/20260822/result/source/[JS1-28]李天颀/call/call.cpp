#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int arr[10010];
	for(int i=1;i<=n;i++) cin>>arr[i];
	int m;
	cin>>m;
	while(m--){
		int op,a,b,c;
		cin>>op;
		if(op==1) cin>>a>>b;
		else if(op==2) cin>>a;
		else cin>>a>>b>>c;
	}
	int q;
	cin>>q;
	while(q--){
		int a;
		cin>>a;
	}
	for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
	return 0;
}

/*
6 7 3 4 5 6 14 8 9 10
*/
