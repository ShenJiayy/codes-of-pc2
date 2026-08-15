#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
struct hyoli{
	int val,pos;
}a[MAXN];
int n,b[MAXN],ans[MAXN];
map<int,int> m;
priority_queue<int> q;
bool cmp(hyoli xx,hyoli yy){
	return xx.val<yy.val;
}
bool t;
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		scanf("%d",&a[i].val);
		a[i].pos=i;
	}
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+2,cmp);
	sort(b+1,b+n+1);
	for(int p=2,qq=1;qq<=n;p++,qq++){
		int shiroi=max(a[p].val-b[qq],0);
		ans[a[1].pos]=max(ans[a[1].pos],shiroi);
		m[shiroi]++;
		q.push(shiroi);
	}
	for(int i=2;i<=n+1;i++){
		q.push(max(a[i-1].val-b[i-1],0));
		m[max(a[i-1].val-b[i-1],0)]++;
		int re=max(a[i].val-b[i-1],0);
		m[re]--;
		while(!q.empty()&&m[q.top()]==0){
			q.pop();
		}
		ans[a[i].pos]=q.top();
	}
	for(int i=1;i<=n+1;i++) printf("%d ",ans[i]);
	return 0;
}
