#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200010];
map<int,queue<int> > mp;
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(mp[arr[i]].empty()) mp[arr[i]].push(i);
		else{
			for(int j=mp[arr[i]].front();j<=i;j++){
				if(arr[j]!=arr[i]){
					while(!mp[arr[j]].empty()) mp[arr[j]].pop();
				}
				arr[j] = arr[i];
			}
			mp[arr[i]].push(i);
		}
	}
	for(int i=1;i<=n;i++) cout<<arr[i]<<"\n";
	return 0;
}
