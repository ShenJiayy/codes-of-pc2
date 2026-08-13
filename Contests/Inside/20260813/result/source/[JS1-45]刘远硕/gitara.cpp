#include<bits/stdc++.h>
using namespace std;
int n,p,ans;
stack<int> q[10];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	for (int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		while(!q[a].empty() && q[a].top()>b){
			q[a].pop();
			ans++;
		}
		if (!q[a].empty() && q[a].top()==b) continue;
		q[a].push(b);
		ans++;
	}
	cout<<ans;
	return 0;
}
