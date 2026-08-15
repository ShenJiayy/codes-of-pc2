#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int b[N];
int ans[N];
unordered_map<int,int> mp;
set<int> s;
struct node {
	int id;
	int a;
}t[N];
bool cmp(node x,node y) {
	return x.a<y.a;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n+1;i++) {
		cin>>t[i].a;
		t[i].id=i;
	}
	for(int i=1;i<=n;i++) {
		cin>>b[i];
	}
	sort(t+1,t+n+2,cmp);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) {
		int tmp=t[i].a-b[i];
		mp[tmp]++;
		s.insert(-tmp);
	}
	ans[t[n+1].id]=-*s.begin();
	for(int i=n;i>=1;i--) {
		mp[t[i].a-b[i]]--;
		if(mp[t[i].a-b[i]]==0) {
			s.erase(-(t[i].a-b[i]));
		}
		mp[t[i+1].a-b[i]]++;
		s.insert(-(t[i+1].a-b[i]));
		ans[t[i].id]=-*s.begin();
	}
	for(int i=1;i<=n+1;i++) {
		cout<<ans[i]<<' ';
	}
	return 0;
}

