#include <bits/stdc++.h>
using namespace std;
struct node{int l,r;}a[500010];
int n,m,ans=1e9;
bool cmp(node x,node y){return x.l<y.l;}
priority_queue < int > q;
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i].l>>a[i].r;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-m+1;++i){
		queue < int > p;
		int cnt=0,j=i+1,len=0;
		q.push(a[i].r-a[i].l);
		while(j<=n&&a[j].l<a[i].r){
			cnt++,j++;
			q.push(a[j].r-a[j].l);
		}
		while(!q.empty()){
			if(len==m-1){
				ans=min(ans,p.front()-q.top());
				p.pop(),q.pop();
			}
			else{
				p.push(q.top());
				q.pop();
				len++;
			}
		}
	}
	cout<<ans;
	return 0;
}
