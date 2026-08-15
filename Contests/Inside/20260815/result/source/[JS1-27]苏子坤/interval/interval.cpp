#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,sz;
}a[500005];
vector<node>v[100005];
int n,m,maxr,minr;
bool cmp(node a,node b){return a.sz<b.sz;}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		maxr=max(maxr,a[i].r);
		a[i].sz=a[i].r-a[i].l+1;
		for(int j=a[i].l;j<=a[i].r;j++)v[j].push_back(a[i]);
	}
	int ans=2147483647;
	for(int i=1;i<=maxr;i++){
		if(v[i].size()<m)continue;
		sort(v[i].begin(),v[i].begin()+v[i].size(),cmp);
		for(int j=0;j+m-1<v[i].size();j++)ans=min(ans,abs(v[i][j+m-1].sz-v[i][j].sz));
	}
	if(ans==2147483647)cout<<-1;
	cout<<ans;
	return 0;
}
