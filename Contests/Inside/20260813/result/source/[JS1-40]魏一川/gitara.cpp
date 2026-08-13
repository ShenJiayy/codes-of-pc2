#include<bits/stdc++.h>
using namespace std;
int n,p;
long long cnt;
stack<int>st[7];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		while(!st[a].empty()&&st[a].top()>b){
			st[a].pop();
			cnt++;
		}
		if(st[a].empty()||st[a].top()!=b){
			st[a].push(b);
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
