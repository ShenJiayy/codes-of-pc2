#include<bits/stdc++.h>
using namespace std;
#define f(x) for(int x=0;x<=1;x++)
int n,m,l[500010],r[500010],ans=INT_MAX;
void dfs(int now,int tot,string used){
	if(now==n+1&&m==tot){
		int p[110]={0},cnt=1,flag=0,mn=INT_MAX,mx=INT_MIN,tcnt=0;
		while(cnt<=n){
			if(used[cnt]=='A'){
				//cout<<3333<<" ";
				for(int i=l[cnt];i<=r[cnt];i++){
					p[i]+=1;
				}
				mn=min(mn,r[cnt]-l[cnt]);
				mx=max(mx,r[cnt]-l[cnt]);
			}
			cnt++;
		}
		//cout<<"\n";
		//cout<<used<<" "<<ans<<" "<<mx<<" "<<mn<<"\n";
		for(int i=1;i<=n;i++){
			if(p[i]==m){
				ans=min(ans,mx-mn);
				
				return;				
			}
		}
		return;
	}
	if(now==n+1) return;
	if(m-tot>n-now+1) return;
	dfs(now+1,tot+1,used+"A");
	dfs(now+1,tot,used+"B");
	return;
}
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	dfs(1,0,"O");
	cout<<(ans==INT_MAX? -1:ans);
	return  0;
}
