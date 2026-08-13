#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define E second
using namespace std;
int n;
pii a[500005];
pair<pii,pii>b[500005];
vector<int>v[500005];
bool cmp(pair<pii,pii>x,pair<pii,pii>y){return x.E.X>y.E.X;}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].X>>a[i].E;
		b[i].X=a[i];
		b[i].E.E=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(a[i].E-a[j].E>=abs(a[i].X-a[j].X)){
				b[i].E.X++;
				v[i].push_back(j);
			}
		}
	}
	sort(b+1,b+1+n,cmp);
	set<int>st;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(st.count(b[i].E.E))continue;
		if(!st.count(b[i].E.E))st.insert(b[i].E.E);
		for(auto j:v[b[i].E.E])st.insert(j);
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(!st.count(j)){
				flag=0;
				break;
			}
		}
		ans++;
		if(flag)break;
	}
	cout<<ans;
	return 0;
}
