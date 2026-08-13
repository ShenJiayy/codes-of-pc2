#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
int p[N];
vector<int>s[N];
int main(){
//	freopen("cat.in","r",stdin);
//	freopen("cat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n-1;i++){
		cin>>u>>v;
		s[u].push_back(v);
		s[v].push_back(u); 
	}
	int st,rr;
	for(int i=1;i<=n;i++){
		if(p[i]==n){
			int maxn=-1;
			for(auto ed:s[i]){
				if(maxn<p[ed])maxn=p[ed],rr=ed;
			}
			cout<<ed;
			exit(0);
			st=i;
			break;
		}
	} 
	return 0;
}
