#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
const int M=5005;
struct node{
	int l,r;
};
int n,m;
int h[M],ans[N];
node a[N];
signed main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		for(int j=a[i].l;j<=a[i].r;j++){
			h[j]++;
		}
	}
	int yy=INT_MAX;
	for(int i=0;i<=5004;i++){
		if(h[i]>=m){
			int tot=0;
			for(int j=1;j<=n;j++){
				if(a[j].l<=i&&a[j].r>=i)ans[++tot]=a[j].r-a[j].l;
			}
			sort(ans+1,ans+tot+1);
			int ss=INT_MAX;
			for(int j=m;j<=tot;j++)ss=min(ss,ans[j]-ans[j-m+1]);
			yy=min(yy,ss);
		}
	}if(yy==INT_MAX){cout<<-1;
	}else cout<<yy;
	return 0;
}
