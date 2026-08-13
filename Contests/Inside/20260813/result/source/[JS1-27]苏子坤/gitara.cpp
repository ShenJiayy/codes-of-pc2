#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p,ans;
bool on[10][300005];
priority_queue<int,vector<int>,less<int> >q[10];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		int op,x;
		cin>>op>>x;
		while(!q[op].empty()&&q[op].top()>x){
			on[op][q[op].top()]=0;
			q[op].pop();
			ans++;
		}
		if(!on[op][x]){
			q[op].push(x);
			ans++;
			on[op][x]=1;
		}
	}
	cout<<ans;
	return 0;
}
