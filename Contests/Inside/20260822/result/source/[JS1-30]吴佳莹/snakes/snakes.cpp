#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int T,w[N],n;
struct node{
	int x,id;
}a[N];
bool cmp(node a,node b){
	if(a.x!=b.x) return a.x>b.x;
	return a.id>b.id;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+1+n,cmp);
	if(a[1].x-a[3].x>a[2].x||a[1].x-a[3].x==a[2].x&&a[1].id>a[2].id) cout<<1<<'\n',a[1].x=a[1].x-a[2].x-a[3].x;
	else cout<<3<<'\n';
	for(int i=1;i<=n;i++) w[a[i].id]=a[i].x;
	T--;
	while(T--){
		int k;cin>>k;
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			w[x]=y;
		}
		if(w[3]-w[1]>=w[2]) cout<<1<<'\n',w[3]=w[3]-w[1]-w[2];
		else cout<<3<<'\n';
	}
	return 0;
}
