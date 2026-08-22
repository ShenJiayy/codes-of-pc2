#include <bits/stdc++.h>
using namespace std;
int t,n;
int arr[100010];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	if(n==3){
		if(arr[3]-arr[1]>=arr[2]){
			if(arr[3]>=arr[2]){
				cout<<1<<endl;
			}
			else{
				cout<<2<<endl;
			}
		}
		else cout<<3<<endl;
	}
	t--;
	while(t--){
		int a,b,c,d,e,f;
		cin>>n;
		if(n==3){
			cin>>a>>b>>c>>d>>e>>f;
			arr[a] = b;
			arr[c] = d;
			arr[e] = f;
			if(arr[3]-arr[1]>=arr[2]){
				if(arr[3]>=arr[2]){
					cout<<1<<endl;
				}
				else{
					cout<<2<<endl;
				}
			}
			else cout<<3<<endl;
		}
	}
	return 0;
}



















//QZkago Requiem
//+ERABY+E CONNEC+10N
