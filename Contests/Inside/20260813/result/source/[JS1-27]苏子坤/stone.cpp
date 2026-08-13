#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,a[200005],cnt=1;
pair<pii,int>b[200005];
bool cmp(pair<pii,int>x,pair<pii,int>y){
	return x.fi.se<y.fi.se;
}
map<int,int>mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp[a[i]]!=0){
			b[cnt]={{mp[a[i]],i},a[i]};
			cnt++;
		}
		mp[a[i]]=i;
	}
	sort(b+1,b+cnt,cmp);
	for(int i=1;i<cnt;i++){
//		cout<<b[i].fi.fi<<" "<<b[i].fi.se<<" "<<a[b[i].fi.fi]<<" "<<a[b[i].fi.se]<<endl;
		if(a[b[i].fi.fi]!=b[i].se)continue;
		for(int j=b[i].fi.fi;j<=b[i].fi.se;j++)a[j]=b[i].se;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
