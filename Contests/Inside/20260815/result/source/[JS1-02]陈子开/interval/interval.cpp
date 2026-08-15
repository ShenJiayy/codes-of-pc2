#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
struct node {
	int l,r;
	int len;
}q[N];
unordered_map<int,int> mp;
vector<int> num;
vector<int> s[2*N];
int ans=2e9;
bool cmp(int x,int y) {
	return q[x].len<q[y].len;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>q[i].l>>q[i].r;
		num.push_back(q[i].l);
		num.push_back(q[i].r);
		q[i].len=q[i].r-q[i].l;
	}
	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
	for(int i=0;i<num.size();i++) {
		mp[num[i]]=i+1;
	}
	for(int i=1;i<=n;i++) {
		q[i].l=mp[q[i].l];
		q[i].r=mp[q[i].r];
		for(int j=q[i].l;j<=q[i].r;j++) {
			s[j].push_back(i);
		}
	}
	for(int i=1;i<=num.size();i++) {
		if(s[i].size()<m) continue;
		sort(s[i].begin(),s[i].end(),cmp);
		int sz=s[i].size();
		for(int j=0;j+m-1<sz;j++) {
			int k=j+m-1;
			ans=min(ans,q[s[i][k]].len-q[s[i][j]].len);
		}
	}
	cout<<ans;
	return 0;
}

