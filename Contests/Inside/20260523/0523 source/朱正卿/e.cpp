#include <bits/stdc++.h>
using namespace std;
vector<int>v[40000];
bool s[10000];
int j(int x,bool h){
	
	if(s[x])return 0;
	int an=1;
	s[x]=1;
	for(int i=0;i<v[x].size();i++){
		if((v[x][i]>x)^h==0){
			continue;
		}
		an+=j(v[x][i],!h);
	}
//	cout<<x<<' '<<an<<'\n';
	return an;
}
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1,a,b;i<=m;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		cout<<n-j(i,0)<<'\n';
		memset(s,0,sizeof(s));
	//	cout<<'\n';
	}
	return 0;
}
