#include <bits/stdc++.h>
using namespace std;

int n, m;

priority_queue <int> q[7];

int main(){
	freopen("gitara.in", "r", stdin);
	freopen("gitara.out", "w", stdout);
	cin>>n>>m;
	int ans = 0;
	for(int i=1; i<=n; i++){
		int x, y;
		cin>>x>>y;
		while(!q[x].empty() && q[x].top()>y){
			q[x].pop();
			ans++;
		}
		if(q[x].empty() || (!q[x].empty()&&q[x].top()!=y)){
			q[x].push(y);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
