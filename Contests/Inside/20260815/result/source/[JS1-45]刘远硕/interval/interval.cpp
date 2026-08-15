#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1000000200,ls[500020];
struct sg{
	int l,r;
} a[500020];
bool cmp(sg a,sg b){
	return a.r<b.r;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i].l>>a[i].r;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i+m-1<=n;i++){
		int sum=1;
		for (int j=i+1;j<=n;j++){
			if (a[j].l<=a[i].r) {
				sum++; 
				ls[sum]=(a[j].r-a[j].l);
			}
		}
		if (sum<m) continue;
		sort(ls+1,ls+1+sum);
		for(int i=1;i+m-1<sum;i++)ans=min(ans,ls[i+m-1]-ls[i]);
	}
	
	if (ans==1000000200) cout<<-1;
	else cout<<ans;
	return 0;
}
