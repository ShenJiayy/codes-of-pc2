#include<bits/stdc++.h>
using namespace std;
int n,p;
stack<int> stk[7];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> p;
	int ans = 0;
	while(n--){
		int i,j;
		cin >> i >> j;
		while(!stk[i].empty() && stk[i].top() > j){
			stk[i].pop();
			ans++;
		}
		if(!stk[i].empty() && stk[i].top() == j) continue;
		else{
			ans++;
			stk[i].push(j);
		}
	}
	cout << ans;
}
