#include <bits/stdc++.h>

#define ed end()
#define bg begin()
#define all(x) x.bg,x.ed
#define newline puts("")
#define si(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int Maxn = 2e5+10;
const int Inf = 0x7f7f7f7f;
const ll Inf_ll = 1ll*Inf*Inf;
const int Mod = 1e9+7;
const double eps = 1e-7;

int n;
unordered_map<int,int> mp;
vector<int> ans;
int a[Maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		mp[a[i]]=i;
	}
	int i=1;
	while(i<=n) {
		i=mp[a[i]];
		ans.push_back(i);
		i++;
	}
	i=1;
	for(int p:ans) {
		int t=i;
		while(i<=p) {
			cout<<a[t]<<'\n';
			i++;
		}
	}
	return 0;
}
