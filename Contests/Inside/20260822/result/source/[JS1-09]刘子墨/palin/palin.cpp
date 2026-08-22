#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int maxn=1e6+10;
int n,T;
struct prq{
	
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		vector<int>nm[maxn>>1];
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
			nm[a[i]].push_back(i);
		}
		cout<<-1;
	}
	return 0;
}
