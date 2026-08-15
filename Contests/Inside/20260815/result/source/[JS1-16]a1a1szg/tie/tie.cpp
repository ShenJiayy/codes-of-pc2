#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int u,id;
};
int n;
node a[N];
int b[N],ans[N],qzh[N],pre[N];
signed main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n+1;i++){cin>>a[i].u;a[i].id=i;}
	sort(a+1,a+n+2,[](node &t,node &y){if(t.u==y.u)return t.id<y.id;return t.u<y.u;});
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)pre[i]=max(max(pre[i-1],a[i].u-b[i]),0ll);
	for(int i=n;i>=1;i--)qzh[i]=max(max(qzh[i+1],a[i+1].u-b[i]),0ll);
	for(int i=1;i<=n+1;i++)ans[a[i].id]=max(pre[i-1],qzh[i]);
	for(int i=1;i<=n+1;i++)cout<<ans[i]<<" ";
	return 0;
}
