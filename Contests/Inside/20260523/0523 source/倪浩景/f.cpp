#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
using namespace std;
int n,q,a[3510],la[3510],col[3510],c[3510];
map<int,int> dp[3510];
struct nd{
	int id,x;
}f[3510];
bool cmp(nd x,nd y){
	return x.x>y.x;
}
bool ck(int k){
	memset(la,0,sizeof(la));
	memset(f,0,sizeof(f));
	memset(col,0,sizeof(col));
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		dp[i].clear();
	}
	for(int i=1;i<=n;i++){
		f[i].id=i;
		for(int j=1;j<i;j++){
			int t=a[i]-a[j];
			if(t<k) break;
			dp[i][t]=dp[j][t]+1;
			if(dp[i][t]>f[i].x){
				f[i].x=dp[i][t];
				la[i]=j;
			}
		}
	}
	sort(f+1,f+n+1,cmp);
	int cnt=0,t=0;
	for(int i=1;i<=n;i++){
		cnt++;
		int tmp=0;
		for(int j=f[i].id;j;j=la[j]){
			if(col[j]) break;
			col[j]=cnt;
			tmp++;
		}
		if(tmp==1) t++;
	}
	return !(t%2);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=a[n]-a[1],ans=1e9+7,p=1e9+7;
	while(l<=r){
		int mid=(l+r)/2;
		if(ck(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(ans==p) cout<<-1;
	else cout<<ans;
	I AK IOI;
}
//time:O(n^2logA)
//memory:O(n)
//[0,100]
