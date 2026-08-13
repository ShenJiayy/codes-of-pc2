#include<bits/stdc++.h>
using namespace std;
priority_queue <int> q[7];
int n,p,ans;
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	scanf("%d %d",&n,&p);
	for(int i=1;i<=6;i++) q[i].push(-1);
	for(int i=1;i<=n;i++){
		ans++;
		int a,b;
		scanf("%d %d",&a,&b);
		while(q[a].top()>b){
			q[a].pop();
			ans++;
		}
		if(q[a].top()==b) ans--;
		else q[a].push(b);
	}
	printf("%d",ans);
	return 0;
}
