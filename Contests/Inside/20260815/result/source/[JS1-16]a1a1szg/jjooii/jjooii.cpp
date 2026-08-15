#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int a[N],b[N],c[N];
int n,k,lo,li,ed,ans;
int cj,co,ci;
const int INF=LLONG_MAX;
string s;
signed main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>s;
	s=" "+s; cj=co=ci=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='J')a[++cj]=i;
		else if(s[i]=='O')b[++co]=i;
		else if(s[i]=='I')c[++ci]=i;
	}//count
	lo=li=1,ans=INF;
	for(int i=1;i<=cj;i++){//jump
		if(i+k-1>cj) break;
		ed=a[i+k-1];
		while(b[lo]<=ed&&lo<=co)lo++;
		if(lo+k-1>co) break;
		ed=b[lo+k-1];
		while(c[li]<=ed&&li<=ci)li++;
		if(li+k-1>ci) break;
		ans=min(ans,c[li+k-1]-a[i]+1-3*k);
	}
	if(ans!=INF)cout<<ans;
	else cout<<-1;
	return 0;
}
