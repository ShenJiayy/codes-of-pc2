#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,cnt;
int ans;
unordered_map<int,int> mp;
pair<int,int> pos[N];
vector<int> e[N];
int in[N];
bool book[N];
bool special=true;
struct node {
	int x,e;
}p[N];
bool cmp(node u,node v) {
	if(u.x==v.x)
		return u.e>v.e;
	return u.x<v.x;
}
bool cmp2(node u,node v) {
	return u.e>v.e;
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>p[i].x>>p[i].e;
		if(p[i].e!=p[i-1].e&&i>1)
			special=false;
	}
	if(special) {
		int ans=0;
		for(int i=1;i<=n;i++) {
			if(!mp[p[i].x]) {
				mp[p[i].x]=true;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(p+1,p+1+n,cmp);
	p[0].x=-1;
	for(int i=1;i<=n;i++) {
		if(p[i].x==p[i-1].x) continue;
		p[++cnt]={p[i].x,p[i].e};
	}
	n=cnt;
	sort(p+1,p+1+n,cmp2);
	for(int i=1;i<=n;i++) {
		if(book[i]) continue;
		for(int j=i+1;j<=n;j++) {
			if(abs(p[i].x-p[j].x)<=p[i].e-p[j].e) {
				book[j]=true;
			}
		}
		ans++;
	}
	cout<<ans;
	return 0;
}

