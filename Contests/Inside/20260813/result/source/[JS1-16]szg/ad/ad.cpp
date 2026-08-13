#include<bits/stdc++.h>
using namespace std;
const int N=5e5+6;
struct node{
	int x,e;
}s[N];
int n,fl,fa[N],vis[N];
vector<int> t[N];
int mp[N];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].e;
		if(i!=1&&s[i].e!=s[i-1].e)fl=1;
	//	fa[i]=i;
	}
	if(!fl){
		int ans=0;
		sort(s+1,s+n+1,cmp);
		int q=-1;
	for(int i=1;i<=n;i++){
		if(s[i].x==q)continue;
		q=s[i].x;ans++;
	}cout<<ans;exit(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||mp[i]||mp[j])continue;
			if(abs(s[i].x-s[j].x)<=s[i].e-s[j].e)mp[j]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!mp[i]){cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
