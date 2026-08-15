//50pts
#include<bits/stdc++.h>
using namespace std;
int n,b[200010],c[200010],ans[200010];
struct num{
	int val,id;
	bool operator<(const num &x)const{
		return x.val>val;
	} 
}a[200010]; 
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n+1;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+n+2);
	sort(b+1,b+n+1);
//	for(int i=1;i<=n+1;i++) cout<<a[i]<<" ";
//	cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	for(int i=1;i<=n+1;i++){
		memset(c,0,sizeof(c));
		int cnt=1;
		for(int j=1;j<=n+1;j++){
			if(j==i) continue;
			c[cnt]=max(c[cnt-1],a[j].val-b[cnt]);
			cnt++;
		}
		ans[a[i].id]=c[n];
	}
	for(int i=1;i<=n+1;i++) cout<<ans[i]<<" "; 
	return 0;
}
