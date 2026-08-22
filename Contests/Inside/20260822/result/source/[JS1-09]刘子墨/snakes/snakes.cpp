#include<bits/stdc++.h>
using namespace std;

const int maxn=3e6+10;

int n,T,ttt,k,a[maxn],cnt;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	for(ttt=1;ttt<=T;ttt++){
		priority_queue<int,vector<int>,greater<int>>q1;
		priority_queue<int>q2;
		if(ttt==1){
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
		}
		else{
			cin>>k;
			for(int i=1,x,y;i<=k;i++){
				cin>>x>>y;
				a[x]=y;
			}
		}
		cnt=n;
		for(int i=1;i<=n;i++){
			q1.push(a[i]);
			q2.push(a[i]);
		}
		while(1){
			int mn=q1.top(),mx=q2.top();
			q1.pop();q2.pop();
			if((mx-mn<q1.top()&&cnt>2)||cnt==1){
				break;
			}
			cnt--;
			q1.push(mx-mn);
			q2.push(mx-mn);
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

