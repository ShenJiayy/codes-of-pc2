#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
unordered_map<int,int> mp;
vector<int> ans;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		mp[a[i]]=i;
	}
	int i=1;
	while(i<=n) {
		i=mp[a[i]];
		ans.push_back(i);
		i++;
	}
	i=1;
	for(int p:ans) {
		int t=i;
		while(i<=p) {
			cout<<a[t]<<'\n';
			i++;
		}
	}
	return 0;
}

