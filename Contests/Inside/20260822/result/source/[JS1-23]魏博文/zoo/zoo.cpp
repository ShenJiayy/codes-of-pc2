#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=1e6+5;
ll a[N],p[N],q[N],s[N],cnt,h,v[N];
vector<int>f[70];
bool find(int x){
	int l=1,r=cnt;
	while(l<=r){
		int mid=(l+r)/2;
		if(s[mid]==x){
			return 1;
		}
		if(s[mid]>x) r=mid-1;
		if(s[mid]<x) l=mid+1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	ll s1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s1|=a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>p[i]>>q[i];
		f[p[i]].push_back(q[i]);
		//cout<<p[i]<<" ";
		if((s1&(1<<p[i]))!=0){
			s[++cnt]=q[i];
			v[p[i]]=1;
			//cout<<p[i]<<' ';
		}
	}
	//cout<<s1;
	for(int i=0;i<k;i++){
		if(v[i]==1) h++;
	}
	//cout<<f[1][0]<<f[1][1];
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<f[i].size();j++){
			cout<<f[i][j]<<' ';
		}
		cout<<"\n";
	}*/
	//cout<<h;
	sort(s+1,s+1+cnt);
	for(int i=0;i<k;i++){
		if(v[i]==0){
			int flag=0;
			for(int j=0;j<f[i].size();j++){
				//cout<<f[i][j];
				if(!find(f[i][j])){
					flag=1;
					break;
				}
			}
			if(flag==0){
				h++;
			}
		}
	}
	ll ans=(1<<h)-n;
	cout<<ans;
}
