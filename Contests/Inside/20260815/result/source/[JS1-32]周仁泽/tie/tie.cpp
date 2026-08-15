// tie
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
struct node{
	int w,id;
	bool operator < (const node &t)const{
		return w>t.w;
	}
}a[MAXN];
int n;
int b[MAXN],ans[MAXN];
int qmax[MAXN],hmax[MAXN];
int now[MAXN],nxt[MAXN];
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++){
		cin>>a[i].w;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+n+2);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		now[i]=max(a[i].w-b[i],(int)0);
		nxt[i+1]=max(a[i+1].w-b[i],(int)0);
	}
	for(int i=1;i<=n;i++) qmax[i]=max(qmax[i-1],now[i]);
	for(int i=n+1;i>=2;i--) hmax[i]=max(hmax[i+1],nxt[i]);
	for(int i=1;i<=n+1;i++){
		int idx=a[i].id;
		ans[idx]=max(hmax[i+1],qmax[i-1]);
	}
	for(int i=1;i<=n+1;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
