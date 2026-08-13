#include <bits/stdc++.h>
using namespace std;
int n,p,an;
priority_queue<long long>q[10];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	for(long long i=1,w,e;i<=n;i++){
		cin>>w>>e;
		while(!q[w].empty()&&q[w].top()>e){
			q[w].pop();
			an++;
		}
		if(q[w].empty()||q[w].top()<e){
			q[w].push(e);
			an++;
		}
	}
	cout<<an;
	return 0;
}
