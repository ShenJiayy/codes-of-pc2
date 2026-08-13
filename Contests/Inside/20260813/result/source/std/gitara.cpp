#include<bits/stdc++.h>
using namespace std;
int n,p;
int ans;
stack<int> sta[10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	while(n--) {
		int u,v;
		cin>>u>>v;
		if(sta[u].empty()) {
			ans++;
			sta[u].push(v);
		}
		else if(sta[u].top()<v) {
			ans++;
			sta[u].push(v);
		}
		else {
			while(!sta[u].empty()&&sta[u].top()>v) {
				ans++;
				sta[u].pop();
			}
			if(sta[u].empty()||sta[u].top()<v) {
				ans++;
				sta[u].push(v);
			}
		}
	}
	cout<<ans;
	return 0;
}
