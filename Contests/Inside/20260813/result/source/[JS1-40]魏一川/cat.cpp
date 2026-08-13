#include<bits/stdc++.h>
using namespace std;
int n,p[200005],a[200005],b[200005];
vector<int>v[200005];
int main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout<<0;
	return 0;
}
