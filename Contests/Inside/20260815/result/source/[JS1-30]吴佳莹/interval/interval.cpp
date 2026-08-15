#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,b[N],l[N],r[N],ans=INT_MAX;
bool check(int a,int b,int c,int d){
	if(a<=c&&d<=b) return 1;
	if(c<=a&&b<=d) return 1;
	if(a>c) swap(a,c),swap(b,d);
	if(a<=c&&b>=c) return 1;
	return 0;
}
void dfs(int k,int last){
	if(k==m+1){
		int maxn=0,minn=INT_MAX,flag=1;
		for(int i=1;i<=n;i++){
			if(!b[i]) continue;
			maxn=max(maxn,r[i]-l[i]);
			minn=min(minn,r[i]-l[i]);
			for(int j=i+1;j<=n;j++){
				if(b[j]){
					if(!(check(l[i],r[i],l[j],r[j]))) flag=0;
				}
			}
		}
		if(flag) ans=min(ans,maxn-minn);
		return;
	}
	for(int i=last+1;i<=n;i++){
		b[i]=1;
		dfs(k+1,i);
		b[i]=0;
	}
}
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	if(n<=20){
		dfs(1,0);
		if(ans!=INT_MAX) cout<<ans;
		else cout<<-1;
	}
	else if(n<=200){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(check(l[i],r[i],l[j],r[j])&&check(l[i],r[i],l[k],r[k])&&check(l[j],r[j],l[k],r[k])){
						int maxn=max(max(r[i]-l[i],r[j]-l[j]),r[k]-l[k]);
						int minn=min(min(r[i]-l[i],r[j]-l[j]),r[k]-l[k]);
						ans=min(ans,maxn-minn);
					}
				}
			}
		}
		if(ans!=INT_MAX) cout<<ans;
		else cout<<-1;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(l[i],r[i],l[j],r[j])){
					int maxn=max(r[i]-l[i],r[j]-l[j]);
					int minn=min(r[i]-l[i],r[j]-l[j]);
					ans=min(ans,maxn-minn);
				}
			}
		}
		if(ans!=INT_MAX) cout<<ans;
		else cout<<-1;		
	}
	return 0;
}
