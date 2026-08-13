#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q[7];
int n,p,ans;
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(q[x].empty()){
			q[x].push(y);
			ans++;
			continue;
		}
		if(q[x].top()<y) q[x].push(y),ans++;
		else if(q[x].top()==y) ans=ans;
		else{
			while(!q[x].empty()){
				if(q[x].top()>y){
					ans++;
					q[x].pop();
				}
				else break;
			}
			if(q[x].empty()){
				q[x].push(y);
				ans++;
			}
			else if(q[x].top()!=y){
				q[x].push(y);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
