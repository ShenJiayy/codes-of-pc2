//gitara
#include<bits/stdc++.h>
using namespace std;
const int pian=6e5+10; 
int n,p,ans;
priority_queue<int,vector<int>,greater<int> >xd[7];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		y=pian-y;
		while(!xd[x].empty()&&xd[x].top()<y){
			xd[x].pop();
			ans++;
		}
		if(!xd[x].empty()&&xd[x].top()==y)continue;
		xd[x].push(y);
		ans++;
	}
	cout<<ans;
	return 0;
} 
