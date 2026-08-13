#include<bits/stdc++.h>
using namespace std;
stack<int>s[10];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	int n,p,cnt=0;
	cin>>n>>p;
	while(n--){
		int a,b;
		cin>>a>>b;
		while(!s[a].empty()&&s[a].top()>b){
			s[a].pop();
			cnt++;
		}
		if(s[a].empty()||s[a].top()!=b){
			s[a].push(b);
			cnt++;
			continue;
		}
	}
	cout<<cnt;
	return 0;
}
