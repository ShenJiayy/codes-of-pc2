// gitara
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,p,x,y,sum=0;
priority_queue<int> q[7];
signed main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	while(n--){
		cin>>x>>y;
		if(q[x].empty()){
			sum++;
			q[x].push(y);
			continue;
		}
		while(!q[x].empty()){
			int top=q[x].top();
			if(top<=y){
				if(top!=y){
					q[x].push(y);
					sum++;
				}
				break;
			}
			sum++;
			q[x].pop();
		}
		if(q[x].empty()){
			sum++;
			q[x].push(y);
		}		
	}
	cout<<sum<<endl;
	return 0;
}
