//interval
#include<bits/stdc++.h>

using namespace std;
int m,n;
struct edge{
	int l,r,len;
};
vector<edge>e;
vector<int>ls;
bool cmp(edge a,edge b){
	if(a.l==b.l)return a.r<b.r;
	return a.l<b.l;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		e.push_back({x,y,y-x});
		ls.push_back(x);
		ls.push_back(y);
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	int poi=ls.size();
	for(int i=0;i<n;i++){
		e[i].l=lower_bound(ls.begin(),ls.end(),e[i].l)-ls.begin()+1;
		e[i].r=lower_bound(ls.begin(),ls.end(),e[i].r)-ls.begin()+1;
	}
	sort(e.begin(),e.end(),cmp);
	int now=0;
	int f=e.size();
	int ans=2e9;
	int cnt=0;
	int mal,mil,l,r;
	bool flag=0;
	vector<int>wait[20000];
	for(int i=1;i<=poi;i++){
		cnt=0;
		for(int j=0;j<f;j++){
			if(e[j].l>i)break;
			if(e[j].l<=i&&i<=e[j].r){
				cnt++;
				wait[i].push_back(e[j].len);
			}
		}
		if(wait[i].size()>=m){
			flag=1;
			sort(wait[i].begin(),wait[i].end());
			int sz=wait[i].size();
			l=0,r=sz-1;
			while(r-l+1>m){
				if(wait[i][l+1]-wait[i][l]>wait[i][r]-wait[i][r-1]){
					l++;
				}
				else r--;
			}
			cnt=wait[i][r]-wait[i][l];
			ans=min(ans,cnt);
		}
	}
	if(flag==0){
		cout<<-1;
		return 0;
	}
	cout<<ans;
	return 0;
} 
