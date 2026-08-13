#include <bits/stdc++.h>
using namespace std;
int n,p,x,y,ans;
stack < int > q[500010];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;++i){
		cin>>x>>y;
		while(!q[x].empty()&&q[x].top()>y){
			ans++;
			q[x].pop();
		}
		if(!q[x].empty()&&q[x].top()==y) continue;
		ans++;
		q[x].push(y);
	}
	cout<<ans;
	return 0;
}
