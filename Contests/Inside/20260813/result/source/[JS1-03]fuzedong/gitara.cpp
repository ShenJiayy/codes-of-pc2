#include<bits/stdc++.h>
using namespace std;
stack<int>stk[7];
int n,P;
long long ans;
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	scanf("%d %d",&n,&P);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		while(stk[x].size()&&y<stk[x].top()){
			stk[x].pop();
			ans++;
		}
		if(stk[x].empty()||(stk[x].size()&&stk[x].top()<y)){
			stk[x].push(y);
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
