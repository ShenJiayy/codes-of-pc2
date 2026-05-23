#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pii;
#define fi first
#define se second
const int N = 300030;

int n,q;
int a[N];
int sum[N];
pii c[N];
inline int check(int now,int k){
	int pos = lower_bound(a+1,a+n+1,k*c[now].se)-a;
	if(pos>=n+1)return c[now].fi*k;
	return sum[n]-sum[pos-1]-k*c[now].se*(n-pos+1)+c[now].fi*k;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)sum[i] = sum[i-1]+a[i];
	for(int i = 1;i<=q;i++){
		cin>>c[i].fi>>c[i].se;
	}
	for(int i = 1;i<=q;i++){
		int l = 0,r = 1e9,mid1 = (2*l+r)/3,mid2 = (l+2*r)/3,ansl = check(i,l),ansr = check(i,r),ans = 1e18;
		ans = min(ans,ansl);
		ans = min(ans,ansr);
		while(mid1<mid2){
			int ansmid1 = check(i,mid1);
			int ansmid2 = check(i,mid2);
			ans = min(ans,ansmid1);
			ans = min(ans,ansmid2);
			if(ansl>ansmid1&&ansmid2<ansr){
				l = mid1;
				r = mid2;
				ansl = ansmid1;
				ansr = ansmid2;
			}
			else if(ansl<ansmid1){
				r = mid1;
				ansr = ansmid1;
			}
			else if(ansr<ansmid2){
				l = mid2;
				ansl = ansmid2;
			}
			else if(ansl==ansmid1)r = mid2,ansr = ansmid2;
			else if(ansr==ansmid2)l = mid1,ansl = ansmid1;
			mid1 = (2*l+r)/3;
			mid2 = (l+2*r)/3;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
