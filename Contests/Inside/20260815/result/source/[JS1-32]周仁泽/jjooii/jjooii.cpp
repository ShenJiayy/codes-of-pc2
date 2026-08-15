// jjooii
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
const int INF=0x3f3f3f3f;
int n,k,ans=INF;
int J,O,I;
int sumj[MAXN],sumo[MAXN],sumi[MAXN];
char ch[MAXN];
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>ch[i];
	for(int i=n;i>=1;i--){
		sumj[i]=sumj[i+1];
		sumo[i]=sumo[i+1];
		sumi[i]=sumi[i+1];
		if(ch[i]=='J') sumj[i]++;
		else if(ch[i]=='O') sumo[i]++;
		else if(ch[i]=='I') sumi[i]++;
	}
	for(int i=1;i<=n;i++){
		if(ch[i]=='J'){
			int a=-1,b=-1,c=-1;
			int l=i,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(sumj[i]-sumj[mid+1]>=k){
					a=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			if(a==-1) continue;
			l=a+1,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(sumo[a]-sumo[mid+1]>=k){
					b=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			if(b==-1) continue;
			l=b+1,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(sumi[b]-sumi[mid+1]>=k){
					c=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			if(c==-1) continue;
			int tmp=(c-i+1-3*k);
			ans=min(ans,tmp);
		}
	}
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
