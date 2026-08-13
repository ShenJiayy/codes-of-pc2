//stone
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,x,y;
int color[N];
vector<int>que,san;
map<int,int>s;
int xd[N];
int ans[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	san.push_back(-1);
	que.push_back(-1);
	for(int i=1;i<=n;i++){
		cin>>x;
		que.push_back(x);
		san.push_back(x);
	}
	sort(san.begin(),san.end());
	san.erase(unique(san.begin(),san.end()),san.end());
	for(int i=1;i<san.size();i++){
		s[san[i]]=i;
	}
	for(int i=1;i<=n;i++){
		xd[s[que[i]]]=max(xd[s[que[i]]],i);
	}
	int qwq,wei;
	for(int i=1;i<=n;i++){
		wei=s[que[i]];
		if(xd[wei]==0)continue;
		if(xd[wei]==i){
			ans[i]=san[xd[wei]];
			continue;
		}
		qwq=xd[wei];
		for(i;i<=qwq;i++)ans[i]=san[wei];
		i--;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
