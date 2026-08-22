//已完成 
#include<bits/stdc++.h>
#define unsigned int long long
using namespace std;
const int N=1e6+5;
int n,m,c,k;
int all;
int a[N];
vector<int> pos;
vector<int> need[70];
set<int> ban;
set<int> can;//可以使用的，即已购买的 
int Pow(int u,int v) {
	if(v==0) return 1;
	int res=1;
	while(v>0) {
		if(v&1) res*=u;
		v>>=1;
		u*=u;
	}
	return res;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		all|=a[i];
	}
	int p=0;
	while(all>0) {
		if(all&1) {
			pos.push_back(p);
		}
		all>>=1;
		p++;
	}
	for(int i=1;i<=m;i++) {
		int p,q;
		cin>>p>>q;
		need[p].push_back(q);
	}
	for(int u:pos) {
		for(int v:need[u]) {
			can.insert(v);
		}
	}
	int cnt=0;//记录可行的位数 
	for(int i=0;i<k;i++) {
		bool flag=true;
		for(int v:need[i]){
			if(can.count(v)==0) {
				flag=false;
				break;
			}
		}
		if(flag) cnt++;
	}
	cout<<Pow(2,cnt)-n;
	return 0;
}

